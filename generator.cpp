#include "generator.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif		
		
		
Generator::Generator(SeasonSelector * const iSeasonSelector, 
					 const int & iPin1,
					 const int & iPin2,
					 const int & iPin3,
					 Sensor * const iSensor1,
					 Sensor * const iSensor2,
					 Sensor * const iSensor3):
					 Device(iPin1, _output_),
					 _seasonSelector(iSeasonSelector),
					 _pinAux1(iPin2),
					 _pinAux2(iPin3),
					 _sensor_1(iSensor1),
					 _sensor_2(iSensor2),
					 _sensor_3(iSensor3){	

	pinMode(iPin2, OUTPUT);
	pinMode(iPin3, OUTPUT);
}


Generator::~Generator(){
	
}


void Generator::setSensor1(Sensor * const iSensor1){
	_sensor_1 = iSensor1;
}
	
	
Sensor * const Generator::getSensor1(){
	return _sensor_1;
}


void Generator::setSensor2(Sensor * const iSensor2){
	_sensor_2 = iSensor2;
}


Sensor * const Generator::getSensor2(){
	return _sensor_2;
}


void Generator::setSensor3(Sensor * const iSensor3){
	_sensor_3 = iSensor3;
}


Sensor * const Generator::getSensor3(){
	return _sensor_3;
}
		

void Generator::bridge_1_on(){

	digitalWrite(getPin(), LOW);

}


void Generator::bridge_1_off(){

	digitalWrite(getPin(), HIGH);

}


void Generator::bridge_2_on(){
	digitalWrite(_pinAux1, LOW);
}


void Generator::bridge_2_off(){
	digitalWrite(_pinAux1, HIGH);
}

	
void Generator::bridge_3_on(){
	digitalWrite(_pinAux2, LOW);
}


void Generator::bridge_3_off(){
	digitalWrite(_pinAux2, HIGH);
}


SeasonSelector * const Generator::getSeasonSelector(){
	return _seasonSelector;
}
