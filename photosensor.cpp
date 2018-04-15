#include "photosensor.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "definitions.h"

//constructor
PhotoSensor::PhotoSensor( const int & iPin,
						  const float & iLowerThreshold,
						  const float & iUpperThreshold,
						  const float & iSetupValue,
						  const State & iState ): Sensor(iPin, iLowerThreshold, iUpperThreshold, iSetupValue),
													_state(iState){
														
}

		
//destructor
PhotoSensor::~PhotoSensor(){

}

//getters and setters
const State & PhotoSensor::getState(){
	return _state;
}

void PhotoSensor::setState(const State & iState){
	_state = iState;
}

void PhotoSensor::loadState(){
	if ( digitalRead( getPin() ) == HIGH )
		_state = _ON_;
	else
		_state = _OFF_;
}

bool PhotoSensor::isOn(){
	
	loadState();
	
	if (_state == _ON_)
		return true;
	
	else
		return false;
}
