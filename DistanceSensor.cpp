// 
// 
// 

#include "DistanceSensor.h"
#include <Arduino.h>

DistanceSensor::DistanceSensor(int _trigPin, int _echoPin)
{
	trigPin = _trigPin;
	echoPin = _echoPin;
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void DistanceSensor::TriggerPulse()
{
	// Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
}

float DistanceSensor::GetDistance(int maxDuration)
{
	TriggerPulse();

	// Calculating the distance
	float distance = GetDuration(maxDuration) * 0.034 / 2;
	return distance;
}

unsigned long DistanceSensor::GetDuration(int maxDuration)
{
	// Reads the echoPin, returns the sound wave travel time in microseconds
	unsigned long duration = pulseIn(echoPin, HIGH, maxDuration);
	return duration;
}
