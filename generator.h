#ifndef generator_h
#define generator_h

#include "device.h"
#include "sensor.h"
#include "seasonSelector.h"


class Generator: public Device{
	public:
		//constructor
		Generator(SeasonSelector * const iSeasonSelector, const int & iPin1, const int & iPin2 = 0, const int & iPin3 = 0, Sensor * const iSensor1 = nullptr, Sensor * const iSensor2 = nullptr, Sensor * const iSensor3 = nullptr);
		
		//destructor
		virtual ~Generator();
		
		//getters and setters
		void setSensor1(Sensor * const iSensor1);
		Sensor * const getSensor1();
		
		void setSensor2(Sensor * const iSensor2);
		Sensor * const getSensor2();
		
		void setSensor3(Sensor * const iSensor3);
		Sensor * const getSensor3();
		
	
		//Acting
		void bridge_1_on();
		void bridge_1_off();
		
		void bridge_2_on();
		void bridge_2_off();

		void bridge_3_on();
		void bridge_3_off();
		
		SeasonSelector * const getSeasonSelector();

	private:		
		//attributes
		Sensor * _sensor_1 = nullptr; // associated sensor device: temperature, light, pressure,...
		Sensor * _sensor_2 = nullptr;
		Sensor * _sensor_3 = nullptr;
	
		int _pinAux1;
		int _pinAux2;
		
		SeasonSelector * _seasonSelector = nullptr;

};

#endif