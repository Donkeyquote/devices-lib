#include "solarpump.h"
#include "photosensor.h"
#include "humiditysensor.h"
#include "settings.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


SolarPump::SolarPump( const int & iPin, 
					  PhotoSensor * const iPhotoSensor, 
					  HumiditySensor * const iHumiditySensor, 
					  TemperatureSensor * const iTemperatureSensor,
					  const unsigned long int & i_tOff,
					  const unsigned long int & i_tOn) : 
					  Pump(iPin, nullptr, nullptr), 
					  _photo_sensor(iPhotoSensor), 
					  _humidity_sensor(iHumiditySensor), 
					  _solar_sensor(iTemperatureSensor),
					  StateMachine(i_tOff, i_tOn){

}


//destructor
SolarPump::~SolarPump(){
	
}

void SolarPump::act(){
	
	_humidity_sensor -> loadCurrentValue();
	_solar_sensor -> loadCurrentValue();

	//Sweeping
	if ( ( getState() == _OFF_ ) &&
		 _photo_sensor->isOn() && 
	     ( _humidity_sensor -> readTemperature() > __solar_min_temperature__ ) &&
	     ( get_tOff() < (millis() - getPreviousTime())) ){

			on();
			setPreviousTime( millis() );
			setState(_ON_);
	}

	
	if ( ( getState() == _ON_ ) && ( !_solar_sensor->inRange() ) &&
	     ( get_tOn() < (millis() - getPreviousTime()))){
			 
			off();
			setPreviousTime( millis() );
			setState(_OFF_);
	}
		
		
}
