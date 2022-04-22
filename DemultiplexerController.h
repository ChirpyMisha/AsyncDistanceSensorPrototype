//// DemultiplexerController.h
//
//#ifndef _DEMULTIPLEXERCONTROLLER_h
//#define _DEMULTIPLEXERCONTROLLER_h
//
//#if defined(ARDUINO) && ARDUINO >= 100
//	#include "arduino.h"
//#else
//	#include "WProgram.h"
//#endif
//
//class DemultiplexerController
//{
//private: static DemultiplexerController* s_instance;
//
//public:
//	static DemultiplexerController* Instance(int input1, int input2, int input3);
//	static DemultiplexerController* Instance(int input1, int input2);
//	static DemultiplexerController* Instance();
//
//	std::vector<DistanceSensor*> sensors;
//
//	float maxDistance;
//	int maxDuration;
//
//	void SetTimer(const uint16_t, const uint16_t);
//	void OnTimerInterrupt();
//};
//
//#endif
//
