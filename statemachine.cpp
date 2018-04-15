#include "statemachine.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif



StateMachine::StateMachine( const unsigned long int & i_tOff,
							const unsigned long int & i_tOn ) : _tOff(i_tOff),
																_tOn(i_tOn),
																_previousTime(0),
																_state(_OFF_){
																	
}


StateMachine::~StateMachine(){
	
}
		

void StateMachine::set_tOff(const unsigned long int & i_tOff){
	_tOff = i_tOff;
}


const unsigned long int & StateMachine::get_tOff(){
	return _tOff;
}


void StateMachine::set_tOn(const unsigned long int & i_tOn){
	_tOn = i_tOn;
}


const unsigned long int & StateMachine::get_tOn(){
	return _tOn;
}


void StateMachine::setPreviousTime(const unsigned long int & iPreviousTime){
	_previousTime = iPreviousTime;
}


const unsigned long int & StateMachine::getPreviousTime(){
	return _previousTime;
}


void StateMachine::setState(const State & iState){
	_state = iState;
}


const State & StateMachine::getState(){
	return _state;
}