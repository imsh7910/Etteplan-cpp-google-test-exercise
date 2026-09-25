#include "temperature_validator.hpp"

#include <cmath>

namespace quality {

bool isTemperatureAllowed(double celsius) {
    return std::isfinite(celsius) && celsius >= -40.0 && celsius <= 85.0;
}

}  // namespace quality
