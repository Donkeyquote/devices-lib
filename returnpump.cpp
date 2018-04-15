#include "returnpump.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


ReturnPump::ReturnPump( const int & iPin, 
					  const unsigned long int & i_tOff,
					  const unsigned long int & i_tOn) : 
					  Pump(iPin, nullptr, nullptr), 
					  StateMachine(i_tOff, i_tOn){

}


//destructor
ReturnPump::~ReturnPump(){
	
}

void ReturnPump::act(){

	//Sweeping
	if ( ( getState() == _OFF_ ) &&
	     ( get_tOff() < (millis() - getPreviousTime())) ){

			on();
			setPreviousTime( millis() );
			setState(_ON_);
	}

	
	if ( ( getState() == _ON_ ) &&
	     ( get_tOn() < (millis() - getPreviousTime()))){
			 
			off();
			setPreviousTime( millis() );
			setState(_OFF_);
	}
		
		
}
