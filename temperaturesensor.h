#ifndef temperature_sensor_h
#define temperature_sensor_h

#include "sensor.h"
#include <DallasTemperature.h>

class TemperatureSensor: public Sensor, public DallasTemperature{
	public:
		//constructor
		//TemperatureSensor();
		TemperatureSensor(const int & iPin,
						  const float & iLowerThreshold = -99.0,
						  const float & iUpperThreshold = -99.0,
						  const float & iSetupValue = -99.0);
		
		//destructor
		virtual ~TemperatureSensor();
		
		//getters and setters
		OneWire * const getBus();
		void setBus(OneWire * const iBus);

		//calculates and sets the current temperature value
		void loadCurrentValue();

		//attributes
		OneWire * _bus;
};


#endif