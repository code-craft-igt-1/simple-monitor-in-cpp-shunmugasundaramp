#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_FALSE(vitalsOk(105, 75, 70));
  ASSERT_FALSE(vitalsOk(99, 75, 100));
  ASSERT_FALSE(vitalsOk(105, 102, 100));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}
