#ifndef returnpump_h
#define returnpump_h

#include "pump.h"


class ReturnPump: public Pump, public StateMachine{
	public:
		//constructor
		ReturnPump( const int & iPin, 
				   const unsigned long int & i_tOff,
				   const unsigned long int & i_tOn);
		
		
		//destructor
		virtual ~ReturnPump();
	
		//Acting
		void act();

};

#endif
