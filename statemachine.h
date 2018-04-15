//Reference: https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all

#ifndef state_machine_h
#define state_machine_h

#include "definitions.h"

class StateMachine {
	public:
		//constructor
		StateMachine(const unsigned long int & i_tOff, const unsigned long int & i_tOn);
		
		//destructor
		virtual ~StateMachine();
		
		//getters and setters
		void set_tOff(const unsigned long int & i_tOff);
		const unsigned long int & get_tOff();
		
		void set_tOn(const unsigned long int & i_tOn);
		const unsigned long int & get_tOn();
		
		void setPreviousTime(const unsigned long int & iPreviousTime);
		const unsigned long int & getPreviousTime();		
		
		void setState(const State & iState);
		const State & getState();
		
		

	private:
		//attributes
		unsigned long int _tOff;
		unsigned long int _tOn;
		unsigned long int _previousTime;
		State _state;

};

#endif