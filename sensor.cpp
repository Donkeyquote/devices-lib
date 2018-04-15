#include "sensor.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "definitions.h"

//constructor

Sensor::Sensor(const int & iPin,
			   const float & iLowerThreshold,
			   const float & iUpperThreshold,
			   const float & iSetupValue): 
			   Device(iPin, _input_), 
			   _lower_threshold(iLowerThreshold), 
			   _upper_threshold(iUpperThreshold),
			   _set_up_value(iSetupValue){
}



//destructor
Sensor::~Sensor(){
}

//getters and setters
const float & Sensor::getLowerThreshold(){
	return _lower_threshold;
}
		
void Sensor::setLowerThreshold(const float & iLowerThreshold){
	_lower_threshold = iLowerThreshold;
}

const float & Sensor::getUpperThreshold(){
	return _upper_threshold;
}

void Sensor::setUpperThreshold(const float & iUpperThreshold){
	_upper_threshold = iUpperThreshold;
}

const float & Sensor::getSetupValue(){
	return _set_up_value;
}

void Sensor::setSetupValue(const float & iSetupValue){
	_set_up_value = iSetupValue;
}

const float & Sensor::getCurrentValue(){
	return _current_value;
}

void Sensor::setCurrentValue(const float & iCurrentValue){
	_current_value = iCurrentValue;
}

bool Sensor::inRange(){
	if ((_current_value < _set_up_value + _upper_threshold) && (_current_value > _set_up_value - _lower_threshold))
		return true;
	
	else
		return false;
}

bool Sensor::isLow(){
	if ( _current_value < _set_up_value - _lower_threshold )
		return true;
	
	else
		return false;
}

bool Sensor::isHigh(){
	if ( _current_value > _set_up_value + _upper_threshold )
		return true;
	
	else
		return false;
}

void Sensor::loadCurrentValue(){
	
}
