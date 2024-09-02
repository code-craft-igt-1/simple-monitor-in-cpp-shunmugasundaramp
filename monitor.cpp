#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

int CheckMargins(float minRange, float maxRange, float value) {
  if (value < minRange || value > maxRange) {
    return 0;
  }
  return 1;
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
  if (!CheckMargins(95, 102, temperature)) {
    cout << "Temperature is critical!\n";
    ShowWarning();
    return true;
  }
  return false;
}

bool isPulseRateOutOfRange(float pulseRate) {
  if (!CheckMargins(60, 100, pulseRate)) {
    cout << "Pulse Rate is out of range!\n";
    ShowWarning();
    return true;
  }
  return false;
}

bool isSpo2OutOfRange(float spo2) {
  if (!CheckMargins(90, 100, spo2)) {
    cout << "Oxygen Saturation out of range!\n";
    ShowWarning();
    return true;
  }
  return false;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  int isvitalsOk = 1;
  if (isTemperatureCritical(temperature) ||
      isPulseRateOutOfRange(pulseRate) ||
      isSpo2OutOfRange(spo2)) {
    isvitalsOk = 0;
  }
  return isvitalsOk;
}
