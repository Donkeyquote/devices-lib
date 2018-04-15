#ifndef pump_h
#define pump_h

#include "device.h"
#include "Sensor.h"

#include "statemachine.h"

class Pump: public Device{
	public:
		//constructor
		Pump(const int & iPin, Sensor * const iSensor1, Sensor * const iSensor2);
		
		//destructor
		virtual ~Pump();
		
		//getters and setters
		void setSensor1(Sensor * const iSensor1);
		Sensor * const getSensor1();
		
		void setSensor2(Sensor * const iSensor2);
		Sensor * const getSensor2();
	
		//Acting
		void on();
		void off();

		
	private:		
		//attributes
		Sensor * _sensor_1 = nullptr; // associated sensor device: temperature, light, pressure,...
		Sensor * _sensor_2 = nullptr;
};

#endif