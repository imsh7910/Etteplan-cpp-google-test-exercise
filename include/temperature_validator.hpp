#pragma once

namespace quality {

// Returns true only for finite temperatures in the supported range [-40, 85] °C.
bool isTemperatureAllowed(double celsius);

}  // namespace quality
