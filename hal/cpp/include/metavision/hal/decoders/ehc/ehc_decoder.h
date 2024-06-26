/**********************************************************************************************************************
 * Copyright (c) Prophesee S.A.                                                                                       *
 *                                                                                                                    *
 * Licensed under the Apache License, Version 2.0 (the "License");                                                    *
 * you may not use this file except in compliance with the License.                                                   *
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0                                 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed   *
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                      *
 * See the License for the specific language governing permissions and limitations under the License.                 *
 **********************************************************************************************************************/

#ifndef METAVISION_HAL_EHC_DECODER_H
#define METAVISION_HAL_EHC_DECODER_H

#include <memory>

#include "metavision/sdk/base/events/raw_event_frame_diff.h"
#include "metavision/sdk/base/events/raw_event_frame_histo.h"
#include "metavision/hal/facilities/i_event_frame_decoder.h"

namespace Metavision {

template<class FrameType, typename T>
class EHCDecoder : public I_EventFrameDecoder<FrameType> {
    using RawData = typename I_EventFrameDecoder<FrameType>::RawData;

    static_assert(sizeof(T) == sizeof(RawData),
                  "The size of decoder internal representation does not match the size of RawData to decode");

public:
    EHCDecoder(int height, int width, int bytes_per_pixel) :
        I_EventFrameDecoder<FrameType>(height, width), size_full_(height * width * bytes_per_pixel) {
        event_frame_data_.reserve(size_full_);
    }

    void decode(const RawData *const raw_data_begin, const RawData *const raw_data_end) override {
        const RawData *cur_raw_data = raw_data_begin;

        for (; cur_raw_data != raw_data_end;) {
            unsigned elems_to_add = std::min(static_cast<size_t>(std::distance(cur_raw_data, raw_data_end)),
                                             size_full_ - event_frame_data_.size());
            event_frame_data_.insert(event_frame_data_.end(), reinterpret_cast<const T *>(cur_raw_data),
                                     reinterpret_cast<const T *>(cur_raw_data + elems_to_add));
            if (event_frame_data_.size() == size_full_) {
                finalize_event_frame(event_frame_data_);
                event_frame_data_.clear();
                event_frame_data_.reserve(size_full_);
            }
            cur_raw_data += elems_to_add;
        }
    }

protected:
    virtual void finalize_event_frame(std::vector<T> &frame_data) = 0;

private:
    std::vector<T> event_frame_data_;
    const size_t size_full_;
};

class Histo3dDecoder : public EHCDecoder<RawEventFrameHisto, uint8_t> {
public:
    Histo3dDecoder(int height, int width, unsigned neg_bits, unsigned pos_bits, bool padded) :
        EHCDecoder(height, width, padded ? 2 : 1), frame_histo_(height, width, neg_bits, pos_bits, !padded) {}

    virtual uint8_t get_raw_event_size_bytes() const override {
        return frame_histo_.get_config().packed ? 1 : 2;
    }

private:
    virtual void finalize_event_frame(std::vector<uint8_t> &frame_data) override {
        frame_histo_.get_data().swap(frame_data);
        add_event_frame(frame_histo_);
    }

    RawEventFrameHisto frame_histo_;
};

class Diff3dDecoder : public EHCDecoder<RawEventFrameDiff, int8_t> {
public:
    Diff3dDecoder(int height, int width, unsigned nbits) :
        EHCDecoder(height, width, 1), frame_diff_(height, width, nbits) {}

    virtual uint8_t get_raw_event_size_bytes() const override {
        return 1;
    }

private:
    virtual void finalize_event_frame(std::vector<int8_t> &frame_data) override {
        frame_diff_.get_data().swap(frame_data);
        add_event_frame(frame_diff_);
    }

    RawEventFrameDiff frame_diff_;
};

} // namespace Metavision

#endif // METAVISION_HAL_EHC_DECODER_H
