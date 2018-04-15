#include "valve.h"
#include "definitions.h"
#include "settings.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


//constructor with parameters
Valve::Valve( const int & iPin_A,
			  const int & iPin_B,
			  Sensor * const iSensor_AB,
			  Sensor * const iSensor_A,
			  Sensor * const iSensor_B) : 
													Device(iPin_A, _output_), 
													_pinAux(iPin_B), 
													_sensor_AB(iSensor_AB),
													_sensor_A(iSensor_A),
													_sensor_B(iSensor_B){

	pinMode(iPin_B, OUTPUT);
}

//destructor
Valve::~Valve(){
	
}

//Input (AB) sensor setter
void Valve::setSensor_AB(Sensor * const iSensor_AB){
	_sensor_AB = iSensor_AB;
}

//Input (AB) sensor getter
Sensor * const Valve::getSensor_AB(){
	return _sensor_AB;
}

//Output (A) sensor setter
void Valve::setSensor_A(Sensor * const iSensor_A){
	_sensor_A = iSensor_A;
}

//Output (A) sensor getter
Sensor * const Valve::getSensor_A(){
	return _sensor_A;
}

//Output (B) sensor setter
void Valve::setSensor_B(Sensor * const iSensor_B){
	_sensor_B = iSensor_B;
}

//Output (B) sensor getter
Sensor * const Valve::getSensor_B(){
	return _sensor_B;
}

void Valve::setPinAux(const int & iPinAux){
	_pinAux = iPinAux;
}

const int & Valve::getPinAux(){
	return _pinAux;
}

//Valve opening A way
void Valve::open_A(){

	digitalWrite(_pinAux, HIGH);
	digitalWrite(_pin, LOW);
	
}

//Valve opening B way
void Valve::open_B(){

Serial.print("!!!!!!!EEEEEOOOOO!!!!!!!!!");

	digitalWrite(_pin, HIGH);
	digitalWrite(_pinAux, LOW);

	/*
if ( digitalRead(_pinAux) == HIGH )
	Serial.print("!!!!!!!ALGO FALLA??!!!!!!!!!");
*/
}

// Stopping voltage on valve
void Valve::off(){

	digitalWrite(_pin, HIGH);
	digitalWrite(_pinAux, HIGH);

}
