/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* PlaybackRate implementation */

#include "sles_allinclusive.h"


static SLresult IPlaybackRate_SetRate(SLPlaybackRateItf self, SLpermille rate)
{
    SL_ENTER_INTERFACE

    IPlaybackRate *thiz = (IPlaybackRate *) self;
    // const, so no lock needed
    if (!(thiz->mMinRate <= rate && rate <= thiz->mMaxRate)) {
        result = SL_RESULT_PARAMETER_INVALID;
    } else {
        interface_lock_exclusive(thiz);
        thiz->mRate = rate;
        interface_unlock_exclusive(thiz);
#ifdef ANDROID
        CAudioPlayer *ap = (SL_OBJECTID_AUDIOPLAYER == InterfaceToObjectID(thiz)) ?
                (CAudioPlayer *) thiz->mThis : NULL;
        if (NULL != ap) {
            result = android_audioPlayer_setPlayRate(ap, rate, true);
        } else {
            result = SL_RESULT_PARAMETER_INVALID;
        }
#else
        result = SL_RESULT_SUCCESS;
#endif
    }

    SL_LEAVE_INTERFACE
}


static SLresult IPlaybackRate_GetRate(SLPlaybackRateItf self, SLpermille *pRate)
{
    SL_ENTER_INTERFACE

    if (NULL == pRate) {
        result = SL_RESULT_PARAMETER_INVALID;
    } else {
        IPlaybackRate *thiz = (IPlaybackRate *) self;
        interface_lock_peek(thiz);
        SLpermille rate = thiz->mRate;
        interface_unlock_peek(thiz);
        *pRate = rate;
        result = SL_RESULT_SUCCESS;
    }

    SL_LEAVE_INTERFACE
}


static SLresult IPlaybackRate_SetPropertyConstraints(SLPlaybackRateItf self, SLuint32 constraints)
{
    SL_ENTER_INTERFACE

    IPlaybackRate *thiz = (IPlaybackRate *) self;
    thiz->mProperties = constraints;
#ifdef ANDROID
    // verify property support before storing
    CAudioPlayer *ap = (SL_OBJECTID_AUDIOPLAYER == InterfaceToObjectID(thiz)) ?
            (CAudioPlayer *) thiz->mThis : NULL;
    if (NULL != ap) {
        result = android_audioPlayer_setPlaybackRateBehavior(ap, constraints);
    } else {
        result = SL_RESULT_PARAMETER_INVALID;
    }

#else
    result = SL_RESULT_SUCCESS;
#endif
    interface_lock_poke(thiz);
    if (result == SL_RESULT_SUCCESS) {
        thiz->mProperties = constraints;
    }
    interface_unlock_poke(thiz);

    SL_LEAVE_INTERFACE
}


static SLresult IPlaybackRate_GetProperties(SLPlaybackRateItf self, SLuint32 *pProperties)
{
    SL_ENTER_INTERFACE

    if (NULL == pProperties) {
        result = SL_RESULT_PARAMETER_INVALID;
    } else {
        IPlaybackRate *thiz = (IPlaybackRate *) self;
        interface_lock_peek(thiz);
        SLuint32 properties = thiz->mProperties;
        interface_unlock_peek(thiz);
        *pProperties = properties;
        result = SL_RESULT_SUCCESS;
    }

    SL_LEAVE_INTERFACE
}


static SLresult IPlaybackRate_GetCapabilitiesOfRate(SLPlaybackRateItf self,
    SLpermille rate, SLuint32 *pCapabilities)
{
    SL_ENTER_INTERFACE

    if (NULL == pCapabilities) {
        result = SL_RESULT_PARAMETER_INVALID;
    } else {
        IPlaybackRate *thiz = (IPlaybackRate *) self;
        // const, so no lock needed
        if (!(thiz->mMinRate <= rate && rate <= thiz->mMaxRate)) {
            result = SL_RESULT_PARAMETER_INVALID;
        } else {
            SLuint32 capabilities = 0;
#ifdef ANDROID
            CAudioPlayer *ap = (SL_OBJECTID_AUDIOPLAYER == InterfaceToObjectID(thiz)) ?
                    (CAudioPlayer *) thiz->mThis : NULL;
            if (NULL != ap) {
                android_audioPlayer_getCapabilitiesOfRate(ap, &capabilities);
            }
#else
            capabilities = thiz->mCapabilities;
#endif
            *pCapabilities = capabilities;
            result = SL_RESULT_SUCCESS;
        }
    }

    SL_LEAVE_INTERFACE
}


static SLresult IPlaybackRate_GetRateRange(SLPlaybackRateItf self, SLuint8 index,
    SLpermille *pMinRate, SLpermille *pMaxRate, SLpermille *pStepSize, SLuint32 *pCapabilities)
{
    SL_ENTER_INTERFACE

    // only one range
    if (NULL == pMinRate || NULL == pMaxRate || NULL == pStepSize || NULL == pCapabilities ||
        (0 < index)) {
        result = SL_RESULT_PARAMETER_INVALID;
    } else {
        IPlaybackRate *thiz = (IPlaybackRate *) self;
        interface_lock_shared(thiz);
        SLpermille minRate = thiz->mMinRate;
        SLpermille maxRate = thiz->mMaxRate;
        SLpermille stepSize = thiz->mStepSize;
        SLuint32 capabilities = thiz->mCapabilities;
        interface_unlock_shared(thiz);
        *pMinRate = minRate;
        *pMaxRate = maxRate;
        *pStepSize = stepSize;
        *pCapabilities = capabilities;
        result = SL_RESULT_SUCCESS;
    }

    SL_LEAVE_INTERFACE
}


static const struct SLPlaybackRateItf_ IPlaybackRate_Itf = {
    IPlaybackRate_SetRate,
    IPlaybackRate_GetRate,
    IPlaybackRate_SetPropertyConstraints,
    IPlaybackRate_GetProperties,
    IPlaybackRate_GetCapabilitiesOfRate,
    IPlaybackRate_GetRateRange
};

void IPlaybackRate_init(void *self)
{
    IPlaybackRate *thiz = (IPlaybackRate *) self;
    thiz->mItf = &IPlaybackRate_Itf;
    thiz->mProperties = SL_RATEPROP_NOPITCHCORAUDIO;
    thiz->mRate = 1000;
    // const
    thiz->mMinRate = 500;
    thiz->mMaxRate = 2000;
    thiz->mStepSize = 0;
#ifdef ANDROID
    // for an AudioPlayer, mCapabilities will be initialized in sles_to_android_audioPlayerCreate
#endif
    // The generic implementation sets no capabilities because the generic
    // implementation alone doesn't support any.
    thiz->mCapabilities = 0;
    // SL_RATEPROP_SILENTAUDIO | SL_RATEPROP_STAGGEREDAUDIO | SL_RATEPROP_NOPITCHCORAUDIO |
    // SL_RATEPROP_PITCHCORAUDIO
}
