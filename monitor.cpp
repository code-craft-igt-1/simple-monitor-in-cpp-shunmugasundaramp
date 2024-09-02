#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds, std::string;

bool CheckMargins(float minRange, float maxRange, float value) {
  bool isValueInRange = false;
  if (minRange <= value && value <= maxRange) {
    isValueInRange = true;
  }
  return isValueInRange;
}

void ShowWarning(const string& message) {
  cout << message << "\n";
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

bool isTemperatureCritical(float temperature, const string& message) {
  bool isTemperatureCritical = false;
  if (!CheckMargins(TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT, temperature)) {
    ShowWarning(message);
    isTemperatureCritical = true;
  }
  return isTemperatureCritical;
}

bool isPulseRateOutOfRange(float pulseRate, const string& message) {
  bool isPulseRateOutOfRange = false;
  if (!CheckMargins(PULSE_RATE_LOWER_LIMIT, PULSE_RATE_UPPER_LIMIT, pulseRate)) {
    ShowWarning(message);
    isPulseRateOutOfRange = true;
  }
  return isPulseRateOutOfRange;
}

bool isSpo2OutOfRange(float spo2, const string& message) {
  bool isSpo2OutOfRange = false;
  if (!CheckMargins(SPO2_LOWER_LIMIT, SPO2_UPPER_LIMIT, spo2)) {
    ShowWarning(message);
    isSpo2OutOfRange = true;
  }
  return isSpo2OutOfRange;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  string temperatureMessage = "Temperature is critical!";
  string pulseRateMessage = "Pulse Rate is out of range!";
  string spo2Message = "Oxygen Saturation out of range!";
  return !(isTemperatureCritical(temperature, temperatureMessage) ||
           isPulseRateOutOfRange(pulseRate, pulseRateMessage) ||
           isSpo2OutOfRange(spo2, spo2Message));
}
