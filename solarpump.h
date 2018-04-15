#ifndef solarpump_h
#define solarpump_h

#include "pump.h"
#include "temperaturesensor.h"
#include "photosensor.h"
#include "humiditysensor.h"


class SolarPump: public Pump, public StateMachine{
	public:
		//constructor
		SolarPump( const int & iPin, 
				   PhotoSensor * const iPhotoSensor, 
				   HumiditySensor * const iHumiditySensor, 
				   TemperatureSensor * const iTemperatureSensor,
				   const unsigned long int & i_tOff,
				   const unsigned long int & i_tOn);
		
		
		//destructor
		virtual ~SolarPump();
	
		//Acting
		void act();
		
	private:
		PhotoSensor * _photo_sensor = nullptr;
		HumiditySensor * _humidity_sensor = nullptr;
		TemperatureSensor * _solar_sensor = nullptr;
};

#endif