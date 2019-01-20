/*
 * Copyright (C) 2018 The Android Open Source Project
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

/*
 * The Opus specification is part of IETF RFC 6716:
 * http://tools.ietf.org/html/rfc6716
 */

#ifndef OPUS_HEADER_H_
#define OPUS_HEADER_H_

namespace android {

struct OpusHeader {
    int channels;
    int channel_mapping;
    int num_streams;
    int num_coupled;
    int16_t gain_db;
    int skip_samples;
    uint8_t stream_map[8];
};

bool ParseOpusHeader(const uint8_t* data, size_t data_size, OpusHeader* header);
int WriteOpusHeader(const OpusHeader &header, int input_sample_rate, uint8_t* output, size_t output_size);
}  // namespace android

#endif  // OPUS_HEADER_H_
