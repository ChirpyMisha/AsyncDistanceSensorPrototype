// DistanceSensorController.h

#ifndef _DISTANCESENSORCONTROLLER_h
#define _DISTANCESENSORCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <StandardCplusplus.h>
#include <vector>
#include "DistanceSensor.h"

class DistanceSensorController
{
private: static DistanceSensorController *s_instance;

public:
	static DistanceSensorController *Instance(const int _trigPins[], const int _size, const int _echoPin, const float _maxDistance);
	static DistanceSensorController *Instance();

	std::vector<DistanceSensor *> sensors;

	float maxDistance;
	int maxDuration;

	void SetTimer(const uint16_t, const uint16_t);
	void OnTimerInterrupt();
};

#endif

