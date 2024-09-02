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

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (!CheckMargins(95, 102, temperature)) {
    cout << "Temperature is critical!\n";
    ShowWarning();
    return 0;
  } else if (!CheckMargins(60, 100, pulseRate)) {
    cout << "Pulse Rate is out of range!\n";
    ShowWarning();
    return 0;
  } else if (!CheckMargins(90, ~0, spo2)) {
    cout << "Oxygen Saturation out of range!\n";
    ShowWarning();
    return 0;
  }
  return 1;
}
