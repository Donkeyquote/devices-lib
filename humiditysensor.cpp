#include "sensor.h"
#include "HumiditySensor.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/*
HumiditySensor::HumiditySensor(){
} */


HumiditySensor::HumiditySensor( const int & iPin,
								const float & iLowerThreshold,
								const float & iUpperThreshold,
								const float & iSetupValue):			   
								Sensor(iPin, iLowerThreshold, iUpperThreshold, iSetupValue),
								DHT(iPin, DHT22) {
	begin();
	
}


HumiditySensor::~HumiditySensor(){

}


void HumiditySensor::loadCurrentValue(){
	setCurrentValue( readHumidity() );
}