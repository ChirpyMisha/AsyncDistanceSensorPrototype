/*
 Name:		AsyncDistanceSensorPrototype.ino
 Created:	4/11/2022 3:26:31 PM
 Author:	ChirpyMisha
*/

#include <StandardCplusplus.h>
#include <vector>
#include "DistanceSensor.h"
#include "DistanceSensorController.h"




DistanceSensorController* distanceSensorController;
const int NUM_OF_DISTANCE_SENSORS = 3;
const int DISTANCE_SENSORS_TRIGGER_PINS[] = { 9, 8, 2 };
const int DISTANCE_SENSOR_ECHO_PIN = 10;
const float DISTANCE_SENSOR_MAX_DISTANCE = 50.0f;

const uint16_t t1_load = 0;
const uint16_t t1_comp = 31250;

void setup() 
{
	Serial.begin(9600); // Starts the serial communication

	delay(1000);

	///Disable ADC (Analog to Digital Converter)
	ADCSRA &= ~(1 << 7);

	distanceSensorController = DistanceSensorController::Instance(DISTANCE_SENSORS_TRIGGER_PINS, NUM_OF_DISTANCE_SENSORS, DISTANCE_SENSOR_ECHO_PIN, DISTANCE_SENSOR_MAX_DISTANCE);
	distanceSensorController->SetTimer(t1_load, t1_comp);
}

void loop() 
{
	delay(1000);
}


