#ifndef valve_h
#define valve_h

#include "device.h"
#include "temperaturesensor.h"


class Valve: public Device{
	public:
		//constructor
		Valve( const int & iPin_A,
			   const int & iPin_B,
			   Sensor * const iSensor_AB,
			   Sensor * const iSensor_A,
			   Sensor * const iSensor_B);
		
		//destructor
		virtual ~Valve();
		
		//getters and setters
		void setSensor_AB(Sensor * const iSensor_AB);
		Sensor * const getSensor_AB();
		
		void setSensor_A(Sensor * const iSensor_A);
		Sensor * const getSensor_A();
		
		void setSensor_B(Sensor * const iSensor_B);
		Sensor * const getSensor_B();		
		
		void setPinAux(const int & iPinAux);
		const int & getPinAux();
	
		//Acting
		virtual void act() = 0;
		
	protected:
		//Opening
		void open_A();
		void open_B();

		//Stopping valve engine
		void off();

	private:		
		//attributes
		int _pinAux;
		Sensor * _sensor_AB = nullptr; // associated sensor device: temperature, light, pressure,...
		Sensor * _sensor_A = nullptr;
		Sensor * _sensor_B = nullptr;
};

#endif