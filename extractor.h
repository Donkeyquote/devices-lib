#ifndef extractor_h
#define extractor_h

#include "pump.h"
#include "humiditysensor.h"
#include "statemachine.h"


class Extractor: public Pump, public StateMachine{
	public:
		//constructor
		Extractor( const int & iPin, 
				   HumiditySensor * const iHumiditySensor1,
				   HumiditySensor * const iHumiditySensor2, 
				   HumiditySensor * const iExternalHumiditySensor,
				   const unsigned long int & i_tOff,
				   const unsigned long int & i_tOn );

		//destructor
		virtual ~Extractor();
		
		void act();
		
	private:
		HumiditySensor * _humidity_sensor_1 = nullptr;
		HumiditySensor * _humidity_sensor_2 = nullptr;
		HumiditySensor * _external_humidity_sensor = nullptr;

};

#endif