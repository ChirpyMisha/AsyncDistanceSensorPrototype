// 
// 
// 

#include "DistanceSensorController.h"


DistanceSensorController *DistanceSensorController::Instance(const int _trigPins[], const int _size, const int _echoPin, const float _maxDistance)
{
	DistanceSensorController *instance = Instance();

	for (int i = 0; i < _size; ++i) {
		instance->sensors.push_back(new DistanceSensor(_trigPins[i], _echoPin));
	}

	instance->maxDistance = _maxDistance;
	instance->maxDuration = 2 * instance->maxDistance / 0.034;

	return instance;
}

DistanceSensorController* DistanceSensorController::s_instance = 0;
DistanceSensorController *DistanceSensorController::Instance()
{
	if (!s_instance)
	{
		s_instance = new DistanceSensorController();
	}

	return s_instance;
}

void DistanceSensorController::SetTimer(const uint16_t t1_load, const uint16_t t1_comp)
{
	/// Set Timer 1
	// Reset Timer1 Control Reg A
	TCCR1A = 0;

	// Set CTC mode
	TCCR1B &= ~(1 << WGM13); // Make sure it's cleared
	TCCR1B |= (1 << WGM12); // Set the WGM12 bit

	// Set to prescaler of 256 (Byte values 1,0,0)
	TCCR1B |= (1 << CS12);
	TCCR1B &= ~(1 << CS11);
	TCCR1B &= ~(1 << CS10);

	// Reset Timer1 and set compare value
	TCNT1 = t1_load;
	OCR1A = t1_comp;

	// Enable Timer1 compare interrupt
	TIMSK1 = (1 << OCIE1A);

	// Enable global interrupts
	sei();
}

void DistanceSensorController::OnTimerInterrupt()
{
	int cnt = 0;
	for (DistanceSensor *sensor : sensors)
	{
		float distance = sensor->GetDistance(maxDuration);

		// Prints the distance on the Serial Monitor
		Serial.print("Distance ");
		Serial.print(++cnt);
		Serial.print(": ");
		Serial.println(distance);
		Serial.println("=============");
	}
}

ISR(TIMER1_COMPA_vect)
{
	DistanceSensorController::Instance()->OnTimerInterrupt();
}
