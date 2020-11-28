#pragma once
#include <Arduino.h>

class SmartTimer
{
private:
  long unsigned int startTime, endTime, lap_Time, duration, lapDuration;
  float durSec;
  const char *name = "Task";

public:
  SmartTimer()
  {
    startTime = micros();
    lap_Time = startTime;
    Serial.printf("%s started.\n", name);
  }

  SmartTimer(const char *timerName)
  {
    startTime = micros();
    name = timerName;
    Serial.printf("%s started.\n", name);
  }

  void checkpoint()
  {
    duration = micros() - startTime;
    durSec = duration / 1000000.0f;
    Serial.printf("%s CheckPoint Time = %0.2f\n", name, durSec);
  }

  void checkpoint(const char *CPname)
  {
    duration = micros() - startTime;
    durSec = duration / 1000000.0f;
    Serial.printf("%s Time = %0.2f\n", CPname, durSec);
  }

  void lapCheckpoint()
  {
    unsigned long int curr = micros();
    lapDuration = curr - lap_Time;
    lap_Time = curr;
    durSec = lapDuration / 1000000.0f;
    Serial.printf("%s Lap Time = %0.2f\n", name, durSec);
  }

  void lapCheckpoint(const char *LCPname)
  {
    unsigned long int curr = micros();
    lapDuration = curr - lap_Time;
    lap_Time = curr;
    durSec = lapDuration / 1000000.0f;
    Serial.printf("%s %s Lap Time = %0.2f\n", name, LCPname, durSec);
  }

  ~SmartTimer()
  {
    duration = micros() - startTime;
    durSec = duration / 1000000.0f;
    Serial.printf("%s End Time = %0.2f\n", name, durSec);
  }
};