#include "pump.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

Pump::Pump( const int & iPin, Sensor * const iSensor1,
			Sensor * const iSensor2 ) : Device(iPin, _output_), 
										_sensor_1(iSensor1),
										_sensor_2(iSensor2){

}

//destructor
Pump::~Pump(){
	
}

//Parameter 1 sensor setter
void Pump::setSensor1(Sensor * const iSensor1){
	_sensor_1 = iSensor1;
}

//Parameter 1 sensor getter
Sensor * const Pump::getSensor1(){
	return _sensor_1;
}

//Parameter 2 sensor setter
void Pump::setSensor2(Sensor * const iSensor2){
	_sensor_2 = iSensor2;
}

//Parameter 2 sensor getter
Sensor * const Pump::getSensor2(){
	return _sensor_2;
}

//Acting
void Pump::on(){
	digitalWrite(_pin, LOW);	
}

void Pump::off(){
	digitalWrite(_pin, HIGH);	
}