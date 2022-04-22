// DistanceSensor.h

#ifndef _DISTANCESENSOR_h
#define _DISTANCESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class DistanceSensor
{
	protected:
		// defines pins numbers
		int trigPin;
		int echoPin;

		void TriggerPulse();

		// Constructor
	public: DistanceSensor(int, int);

	public:
		float GetDistance(int maxDuration);
		unsigned long GetDuration(int maxDuration);
};

#endif

