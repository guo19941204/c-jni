/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

/******************************************************************

 iLBC Speech Coder ANSI-C Source Code

 WebRtcIlbcfix_Refiner.h

******************************************************************/

#ifndef WEBRTC_MODULES_AUDIO_CODING_CODECS_ILBC_MAIN_SOURCE_REFINER_H_
#define WEBRTC_MODULES_AUDIO_CODING_CODECS_ILBC_MAIN_SOURCE_REFINER_H_

#include "defines.h"

/*----------------------------------------------------------------*
 * find segment starting near idata+estSegPos that has highest
 * correlation with idata+centerStartPos through
 * idata+centerStartPos+ENH_BLOCKL-1 segment is found at a
 * resolution of ENH_UPSO times the original of the original
 * sampling rate
 *---------------------------------------------------------------*/

void WebRtcIlbcfix_Refiner(
    WebRtc_Word16 *updStartPos, /* (o) updated start point (Q-2) */
    WebRtc_Word16 *idata,   /* (i) original data buffer */
    WebRtc_Word16 idatal,   /* (i) dimension of idata */
    WebRtc_Word16 centerStartPos, /* (i) beginning center segment */
    WebRtc_Word16 estSegPos,  /* (i) estimated beginning other segment (Q-2) */
    WebRtc_Word16 *surround,  /* (i/o) The contribution from this sequence
                                 summed with earlier contributions */
    WebRtc_Word16 gain    /* (i) Gain to use for this sequence */
                           );

#endif
