#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, EverythingIsOk) {
  ASSERT_TRUE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT + 1.0,
                      PULSE_RATE_LOWER_LIMIT + 1.0,
                      SPO2_LOWER_LIMIT + 1.0));
}
TEST(Monitor, OnlyLowTemperature) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT - 0.1,
                      PULSE_RATE_LOWER_LIMIT + 1.0,
                      SPO2_LOWER_LIMIT + 1.0));
}
TEST(Monitor, OnlyHighTemperature) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_UPPER_LIMIT + 0.1,
                      PULSE_RATE_LOWER_LIMIT + 1.0,
                      SPO2_LOWER_LIMIT + 1.0));
}
TEST(Monitor, OnlyLowPulseRate) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT + 1.0,
                      PULSE_RATE_LOWER_LIMIT - 0.1,
                      SPO2_LOWER_LIMIT + 1.0));
}
TEST(Monitor, OnlyHighPulseRate) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT + 1.0,
                      PULSE_RATE_UPPER_LIMIT + 0.1,
                      SPO2_LOWER_LIMIT + 1.0));
}
TEST(Monitor, OnlyLowSpo2) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT + 1.0,
                      PULSE_RATE_LOWER_LIMIT + 1.0,
                      SPO2_LOWER_LIMIT - 0.1));
}
TEST(Monitor, OnlyHighSpo2) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT + 1.0,
                      PULSE_RATE_LOWER_LIMIT + 1.0,
                      SPO2_UPPER_LIMIT + 0.1));
}
TEST(Monitor, WhenLowTemperatureAndLowPulseRate) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT - 0.1,
                      PULSE_RATE_LOWER_LIMIT - 0.1,
                      SPO2_LOWER_LIMIT + 1.0));
}
TEST(Monitor, WhenHighTemperatureAndHighPulseRate) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_UPPER_LIMIT + 0.1,
                      PULSE_RATE_UPPER_LIMIT + 0.1,
                      SPO2_LOWER_LIMIT + 1.0));
}
TEST(Monitor, WhenLowTemperatureAndLowSpo2) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT - 0.1,
                      PULSE_RATE_LOWER_LIMIT + 1.0,
                      SPO2_LOWER_LIMIT - 0.1));
}
TEST(Monitor, WhenHighTemperatureAndHighSpo2) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_UPPER_LIMIT + 0.1,
                      PULSE_RATE_LOWER_LIMIT + 1.0,
                      SPO2_UPPER_LIMIT + 0.1));
}
TEST(Monitor, WhenLowPulseRateAndLowSpo2) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT + 1.0,
                      PULSE_RATE_LOWER_LIMIT - 0.1,
                      SPO2_LOWER_LIMIT - 0.1));
}
TEST(Monitor, WhenHighPulseRateAndHighSpo2) {
  ASSERT_FALSE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT + 1.0,
                      PULSE_RATE_UPPER_LIMIT + 0.1,
                      SPO2_UPPER_LIMIT + 0.1));
}
TEST(Monitor, WhenAllAreInLowerBorderLine) {
  ASSERT_TRUE(vitalsOk(
                      TEMPERATURE_LOWER_LIMIT,
                      PULSE_RATE_LOWER_LIMIT,
                      SPO2_LOWER_LIMIT));
}
TEST(Monitor, WhenAllAreInUpperBorderLine) {
  ASSERT_TRUE(vitalsOk(
                      TEMPERATURE_UPPER_LIMIT,
                      PULSE_RATE_UPPER_LIMIT,
                      SPO2_UPPER_LIMIT));
}
