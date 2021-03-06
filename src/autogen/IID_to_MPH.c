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

// This file is automagically generated by hashgen, do not edit

/** \file IID_to_MPH.c Interface ID to MPH mapping */

#include <SLES/OpenSLES.h>
#include "MPH.h"
#include <assert.h>
#include <string.h>

extern const struct SLInterfaceID_ SL_IID_array[MPH_MAX];

/** \brief Map SLInterfaceID to its minimal perfect hash (MPH), or -1 if unknown */

int IID_to_MPH(const SLInterfaceID iid)
{
#define MAX_HASH_VALUE 250
  static const unsigned char asso_values[] =
    {
      251,  22, 251,  87, 251, 251,   0, 251,  37,  17,
      251,  12,   4, 251, 251,  95, 251, 251, 251, 251,
      102, 251,  17, 251, 251,  85, 251, 251, 251,   7,
      251, 115, 251, 251, 251, 251, 251, 251,   7,   2,
      251, 251,  15,   2,  87, 122,  15, 251, 251, 122,
      251, 251, 251,  70, 251,  50, 251, 251,  32, 251,
      251,   7, 251,  47,   2, 251,  52,  12,  47,   2,
      251,  25, 251,  67, 251,  85,  32,  25, 251, 251,
        2, 251, 251, 251,   2, 251,   2, 251, 251, 251,
        2, 251, 251,   2, 251, 251, 251,  12, 105, 125,
      251, 125, 251, 251,   2, 251,  12, 120, 251,  10,
       75,   2,   2, 251, 251, 120, 115, 251, 251, 251,
      110, 120,  10, 110, 251, 251, 251, 105,  15, 251,
        5,  50, 251, 251, 251, 251, 251, 100, 251, 251,
      120,   2, 251,  95, 251, 251, 251, 125,   2, 251,
      251,  90, 251, 251,  90, 251,   0, 251,  90, 251,
      251, 251, 251,  75, 100,   2, 251, 100,  80, 251,
      110, 251, 251,  70,  80,  75, 115,  22,  50,  75,
       90, 251, 251, 251,  65,  65, 251,  60,  65, 251,
      251, 251,  60,   5,  55,  55, 105,   5,  50,  45,
       65, 251, 251, 251,  55,  45,  45, 251,  45,  30,
       40, 251,  65,  55, 251,  75, 251,  30,  75,  45,
      251,  80,  25, 251, 251,  20, 251,  20,   2, 251,
      251,  50, 251, 251, 251,  60, 110,  17,  20,  30,
      251,  45,   0,  85,  20, 251, 120, 251, 251, 251,
      251, 251, 251,  35,  40,  60
    };
    static const signed char hash_to_MPH[] = {
        MPH_BASSBOOST,
        -1,
        MPH_BUFFERQUEUE,
        -1,
        MPH_XAVIDEOENCODERCAPABILITIES,
        MPH_XAIMAGEENCODERCAPABILITIES,
        -1,
        MPH_XAOBJECT,
        -1,
        MPH_VISUALIZATION,
        MPH_DYNAMICSOURCE,
        -1,
        MPH_XAAUDIOIODEVICECAPABILITIES,
        -1,
        MPH_MIDITIME,
        MPH_RECORD,
        -1,
        MPH_3DLOCATION,
        -1,
        MPH_VIBRA,
        MPH_XAEQUALIZER,
        -1,
        MPH_ANDROIDEFFECTCAPABILITIES,
        -1,
        MPH_EQUALIZER,
        MPH_XACONFIGEXTENSION,
        -1,
        MPH_RATEPITCH,
        -1,
        MPH_XAAUDIODECODERCAPABILITIES,
        MPH_PLAYBACKRATE,
        -1,
        MPH_XALED,
        -1,
        MPH_VOLUME,
        MPH_PREFETCHSTATUS,
        -1,
        MPH_XAMETADATAEXTRACTION,
        -1,
        MPH_XAVOLUME,
        MPH_XAIMAGECONTROLS,
        -1,
        MPH_EFFECTSEND,
        -1,
        MPH_XACAMERACAPABILITIES,
        MPH_DEVICEVOLUME,
        -1,
        MPH_XAVIDEOENCODER,
        -1,
        -1,
        MPH_ANDROIDACOUSTICECHOCANCELLATION,
        -1,
        MPH_XAOUTPUTMIX,
        -1,
        -1,
        MPH_XASNAPSHOT,
        -1,
        MPH_ENGINE,
        -1,
        -1,
        MPH_PLAY,
        -1,
        MPH_MUTESOLO,
        -1,
        -1,
        MPH_PITCH,
        -1,
        MPH_XADYNAMICSOURCE,
        -1,
        -1,
        MPH_XACAMERA,
        -1,
        MPH_XAVIBRA,
        -1,
        -1,
        MPH_AUDIOIODEVICECAPABILITIES,
        -1,
        MPH_XADYNAMICINTERFACEMANAGEMENT,
        -1,
        -1,
        MPH_XAVIDEODECODERCAPABILITIES,
        -1,
        MPH_3DMACROSCOPIC,
        -1,
        -1,
        MPH_OUTPUTMIXEXT,
        -1,
        MPH_XADEVICEVOLUME,
        -1,
        -1,
        MPH_XAIMAGEENCODER,
        -1,
        MPH_XAMETADATAINSERTION,
        -1,
        -1,
        MPH_ENGINECAPABILITIES,
        -1,
        MPH_XAENGINE,
        -1,
        -1,
        MPH_XAAUDIOENCODERCAPABILITIES,
        -1,
        MPH_XAVIDEOPOSTPROCESSING,
        -1,
        -1,
        MPH_XAIMAGEDECODERCAPABILITIES,
        -1,
        MPH_3DGROUPING,
        -1,
        -1,
        MPH_ENVIRONMENTALREVERB,
        -1,
        MPH_3DSOURCE,
        -1,
        -1,
        MPH_XAPREFETCHSTATUS,
        -1,
        MPH_XARDS,
        -1,
        -1,
        MPH_ANDROIDNOISESUPPRESSION,
        -1,
        MPH_AUDIODECODERCAPABILITIES,
        -1,
        -1,
        MPH_XAAUDIOENCODER,
        -1,
        MPH_XASTREAMINFORMATION,
        -1,
        -1,
        MPH_XAIMAGEEFFECTS,
        -1,
        MPH_LED,
        -1,
        -1,
        MPH_SEEK,
        -1,
        MPH_VIRTUALIZER,
        -1,
        -1,
        MPH_3DCOMMIT,
        -1,
        MPH_XASEEK,
        -1,
        -1,
        MPH_XARADIO,
        -1,
        MPH_PRESETREVERB,
        -1,
        -1,
        MPH_AUDIOENCODER,
        -1,
        MPH_ANDROIDSIMPLEBUFFERQUEUE,
        -1,
        -1,
        MPH_ANDROIDEFFECT,
        -1,
        MPH_XAPLAYBACKRATE,
        -1,
        -1,
        MPH_MIDIMESSAGE,
        -1,
        MPH_MIDIMUTESOLO,
        -1,
        -1,
        MPH_ANDROIDAUTOMATICGAINCONTROL,
        -1,
        -1,
        -1,
        -1,
        MPH_AUDIOENCODERCAPABILITIES,
        -1,
        -1,
        -1,
        -1,
        MPH_XATHREADSYNC,
        -1,
        -1,
        -1,
        -1,
        MPH_3DDOPPLER,
        -1,
        -1,
        -1,
        -1,
        MPH_OUTPUTMIX,
        -1,
        -1,
        -1,
        -1,
        MPH_XAPLAY,
        -1,
        -1,
        -1,
        -1,
        MPH_XARECORD,
        -1,
        -1,
        -1,
        -1,
        MPH_ANDROIDCONFIGURATION,
        -1,
        -1,
        -1,
        -1,
        MPH_ANDROIDBUFFERQUEUESOURCE,
        -1,
        -1,
        -1,
        -1,
        MPH_METADATATRAVERSAL,
        -1,
        -1,
        -1,
        -1,
        MPH_ANDROIDEFFECTSEND,
        -1,
        -1,
        -1,
        -1,
        MPH_NULL,
        -1,
        -1,
        -1,
        -1,
        MPH_METADATAEXTRACTION,
        -1,
        -1,
        -1,
        -1,
        MPH_MIDITEMPO,
        -1,
        -1,
        -1,
        -1,
        MPH_XAMETADATATRAVERSAL,
        -1,
        -1,
        -1,
        -1,
        MPH_THREADSYNC,
        -1,
        -1,
        -1,
        -1,
        MPH_OBJECT,
        -1,
        -1,
        -1,
        -1,
        MPH_DYNAMICINTERFACEMANAGEMENT
    };
    if (&SL_IID_array[0] <= iid && &SL_IID_array[MPH_MAX] > iid)
        return iid - &SL_IID_array[0];
    if (NULL != iid) {
        unsigned key = asso_values[((unsigned char *)iid)[3]] +
            asso_values[((unsigned char *)iid)[1]];
        if (key <= MAX_HASH_VALUE) {
            int MPH = hash_to_MPH[key];
            if (MPH >= 0) {
                assert(MPH < MPH_MAX);
                SLInterfaceID trial = &SL_IID_array[MPH];
                if (!memcmp(iid, trial, sizeof(struct SLInterfaceID_)))
                    return MPH;
            }
        }
    }
    return -1;
}
