/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

// The TimeScheduler class keeps track of periodic events. It is non-drifting
// and keeps track of any missed periods so that it is possible to catch up.
// (compare to a metronome)

#ifndef WEBRTC_MODULES_AUDIO_CONFERENCE_MIXER_SOURCE_TIME_SCHEDULER_H_
#define WEBRTC_MODULES_AUDIO_CONFERENCE_MIXER_SOURCE_TIME_SCHEDULER_H_

#include "tick_util.h"

namespace webrtc {
class CriticalSectionWrapper;
class TimeScheduler
{
public:
    TimeScheduler(const WebRtc_UWord32 periodicityInMs);
    ~TimeScheduler();

    // Signal that a periodic event has been triggered.
    WebRtc_Word32 UpdateScheduler();

    // Set updateTimeInMs to the amount of time until UpdateScheduler() should
    // be called. This time will never be negative.
    WebRtc_Word32 TimeToNextUpdate(WebRtc_Word32& updateTimeInMS) const;

private:
    CriticalSectionWrapper* _crit;

    bool _isStarted;
    TickTime _lastPeriodMark;

    WebRtc_UWord32 _periodicityInMs;
    WebRtc_Word64  _periodicityInTicks;
    WebRtc_UWord32 _missedPeriods;
};
} // namespace webrtc

#endif // WEBRTC_MODULES_AUDIO_CONFERENCE_MIXER_SOURCE_TIME_SCHEDULER_H_
