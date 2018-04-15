#include "extractor.h"
#include "sensor.h"
#include "settings.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


Extractor::Extractor( const int & iPin, 
					  HumiditySensor * const iHumiditySensor1,
					  HumiditySensor * const iHumiditySensor2,
					  HumiditySensor * const iExternalHumiditySensor,
					  const unsigned long int & i_tOff,
					  const unsigned long int & i_tOn):
					  Pump(iPin, nullptr, nullptr),
					  _humidity_sensor_1(iHumiditySensor1),
					  _humidity_sensor_2(iHumiditySensor2),
					  _external_humidity_sensor(iExternalHumiditySensor),
					  StateMachine(i_tOff, i_tOn){

}


Extractor::~Extractor(){

}

void Extractor::act(){

	// RUN: if system Off, AND longtime Off, AND humidity high 
	if ( ( getState() == _OFF_ ) &&
		 ( get_tOff() < (millis() - getPreviousTime()) ) &&
		 ( ( _external_humidity_sensor->readHumidity() * (__start_external_vs_1__) < _humidity_sensor_1->readHumidity() )  ||
	       ( _external_humidity_sensor->readHumidity() * (__start_external_vs_2__) < _humidity_sensor_2->readHumidity() * __correction_sensor_h_2__ ) ) ){ 

			on();
			setState(_ON_);
			setPreviousTime( millis() );

	} 

	// STOP: if system On, AND longtime, OR humidity LOW
	if ( ( getState() == _ON_ ) &&
		 ( _external_humidity_sensor->readHumidity() * (__stop_external_vs_1__) > _humidity_sensor_1->readHumidity() ) &&
		 ( _external_humidity_sensor->readHumidity() * (__stop_external_vs_2__) > _humidity_sensor_2->readHumidity() * __correction_sensor_h_2__ ) 
		 /*( get_tOn() < (millis() - getPreviousTime()) )*/ ){
			
			off();
			setState(_OFF_);
			setPreviousTime( millis() );

	}
	
	// if too much time working then stop
	if ( ( (millis() - getPreviousTime()) > get_tOn() ) && getState() == _ON_ )
	{
		off();
		setState(_OFF_);
		setPreviousTime( millis() );

	}
			  
}