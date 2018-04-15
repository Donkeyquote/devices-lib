#include "device.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//constructor
Device::Device( const int & iPin, 
				const Mode & iMode): _pin(iPin),
									 _mode(iMode){	
	if (iMode == _output_){
		pinMode(iPin, OUTPUT);
		digitalWrite(iPin, HIGH);
	}
		
	else
		pinMode(iPin, OUTPUT);
}

//destructor
Device::~Device(){
}

//getters and setters
void Device::setPin(const int & iPin){
	_pin = iPin;
}

const int & Device::getPin(){
	return _pin;
}

void Device::setMode(const Mode & iMode){
	_mode = iMode;
}

const Mode & Device::getMode(){
	return _mode;
}
