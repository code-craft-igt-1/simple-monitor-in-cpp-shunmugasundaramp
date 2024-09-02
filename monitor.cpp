#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

bool CheckMargins(float minRange, float maxRange, float value) {
  bool isValueInRange = false;
  if (minRange <= value && value <= maxRange) {
    isValueInRange = true;
  }
  return isValueInRange;
}

void ShowWarning() {
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

bool isTemperatureCritical(float temperature) {
  bool isTemperatureCritical = false;
  if (!CheckMargins(TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, temperature)) {
    cout << "Temperature is critical!\n";
    ShowWarning();
    isTemperatureCritical = true;
  }
  return isTemperatureCritical;
}

bool isPulseRateOutOfRange(float pulseRate) {
  bool isPulseRateOutOfRange = false;
  if (!CheckMargins(PULSE_RATE_LOWER_LIMIT, PULSE_RATE_UPPER_LIMIT, pulseRate)) {
    cout << "Pulse Rate is out of range!\n";
    ShowWarning();
    isPulseRateOutOfRange = true;
  }
  return isPulseRateOutOfRange;
}

bool isSpo2OutOfRange(float spo2) {
  bool isSpo2OutOfRange = false;
  if (!CheckMargins(SPO2_LOWER_LIMIT, SPO2_UPPER_LIMIT, spo2)) {
    cout << "Oxygen Saturation out of range!\n";
    ShowWarning();
    isSpo2OutOfRange = true;
  }
  return isSpo2OutOfRange;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return !(isTemperatureCritical(temperature) ||
           isPulseRateOutOfRange(pulseRate) ||
           isSpo2OutOfRange(spo2));
}
