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

#ifndef METAVISION_HAL_PSEE_PLUGINS_V4L2_CAMERA_DISCOVERY
#define METAVISION_HAL_PSEE_PLUGINS_V4L2_CAMERA_DISCOVERY

#include "metavision/hal/utils/camera_discovery.h"
#include "devices/v4l2/v4l2_device_builder.h"

namespace Metavision {
class V4L2BoardCommand;

class V4l2CameraDiscovery : public CameraDiscovery {
public:
    V4l2CameraDiscovery();
    SerialList list() override;
    SystemList list_available_sources() override;
    bool discover(DeviceBuilder &device_builder, const std::string &serial, const DeviceConfig &config) override;
    bool is_for_local_camera() const override;
    std::vector<std::shared_ptr<V4L2BoardCommand>> devices_;

private:
    std::unique_ptr<V4L2DeviceBuilder> builder;
};

} // namespace Metavision

#endif // METAVISION_HAL_PSEE_PLUGINS_V4L2_CAMERA_DISCOVERY
