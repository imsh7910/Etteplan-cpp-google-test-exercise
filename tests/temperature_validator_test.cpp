#include "temperature_validator.hpp"

#include <gtest/gtest.h>
#include <limits>

TEST(TemperatureValidator, AcceptsValueInsideRange) {
    EXPECT_TRUE(quality::isTemperatureAllowed(20.0));
}

TEST(TemperatureValidator, AcceptsBothBoundaryValues) {
    EXPECT_TRUE(quality::isTemperatureAllowed(-40.0));
    EXPECT_TRUE(quality::isTemperatureAllowed(85.0));
}

TEST(TemperatureValidator, RejectsValuesOutsideRange) {
    EXPECT_FALSE(quality::isTemperatureAllowed(-40.1));
    EXPECT_FALSE(quality::isTemperatureAllowed(85.1));
}

TEST(TemperatureValidator, RejectsNonFiniteValues) {
    EXPECT_FALSE(quality::isTemperatureAllowed(std::numeric_limits<double>::quiet_NaN()));
    EXPECT_FALSE(quality::isTemperatureAllowed(std::numeric_limits<double>::infinity()));
}
