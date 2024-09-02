#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, EverythingIsOk) {
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}
TEST(Monitor, OnlyTemperatureIsOffRange) {
  ASSERT_FALSE(vitalsOk(105, 75, 100)); 
}
TEST(Monitor, OnlyPulseRateIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 100));
}
TEST(Monitor, OnlySpo2IsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 75, 70));
}
TEST(Monitor, WhenTemperatureAndPulseRateAreOffRange) {
  ASSERT_FALSE(vitalsOk(105, 102, 100));
}
TEST(Monitor, WhenTemperatureAndSpo2AreOffRange) {
  ASSERT_FALSE(vitalsOk(105, 75, 70));
}
TEST(Monitor, WhenPulseRateAndSpo2AreOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
}
TEST(Monitor, WhenAllAreInBorderLine) {
  ASSERT_FALSE(vitalsOk(102, 100, 90));
}
