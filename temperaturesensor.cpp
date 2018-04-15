#include "TemperatureSensor.h"
#include <OneWire.h>


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


TemperatureSensor::TemperatureSensor( const int & iPin,
									  const float & iLowerThreshold,
									  const float & iUpperThreshold,
									  const float & iSetupValue):			   
									  Sensor(iPin, iLowerThreshold, iUpperThreshold, iSetupValue),
									  DallasTemperature(){

	_bus = new OneWire(iPin);
	setOneWire(_bus);
	
	begin();
	requestTemperatures();
	this->Sensor::setCurrentValue(getTempCByIndex(0));
}


TemperatureSensor::~TemperatureSensor(){
	if (_bus != NULL)
		delete _bus;
}


OneWire * const TemperatureSensor::getBus(){
	return _bus;
}

void TemperatureSensor::setBus(OneWire * const iBus){
	_bus = iBus;
}


void TemperatureSensor::loadCurrentValue(){

	requestTemperatures();
	setCurrentValue(getTempCByIndex(0));	
}