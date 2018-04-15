#include "boiler.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif	




Boiler::Boiler( SeasonSelector * const iSeasonSelector, 
				TemperatureSensor * const iTemperatureSensor,
				const int & iPin ):
				Generator(iSeasonSelector, iPin, 0, 0, iTemperatureSensor){
	
}


Boiler::~Boiler(){
}

void Boiler::act(){

	getSeasonSelector() -> loadSeason();
	
	if ( getSeasonSelector() -> isWinter() &&
		 getSensor1() -> isLow() )
		bridge_1_on();

	else {
		if (!getSeasonSelector() -> isWinter() )
			bridge_1_off();
		
		if ( getSensor1() -> isHigh() )
			bridge_1_off();
	}
		
}
