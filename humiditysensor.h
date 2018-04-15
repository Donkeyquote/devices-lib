#ifndef humidity_sensor_h
#define humidity_sensor_h

#include "sensor.h"
#include <DHT.h>
#include <DHT_U.h>

class HumiditySensor: public Sensor, public DHT{
	public:
		//constructor
		//HumiditySensor();
		HumiditySensor(const int & iPin,
					   const float & iLowerThreshold = 0,
					   const float & iUpperThreshold = 0,
					   const float & iSetupValue = 0);
		
		//destructor
		virtual ~HumiditySensor();
		
		//calculates and sets the current humidity value
		void loadCurrentValue();

};


#endif