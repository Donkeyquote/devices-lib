#include "heatpump.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif	




HeatPump::HeatPump( SeasonSelector * const iSeasonSelector,
					const int & iPin ):
					Generator(iSeasonSelector, iPin){

}


HeatPump::~HeatPump(){
}


void HeatPump::act(){
	
	getSeasonSelector() -> loadSeason();

	if ( getSeasonSelector() -> isWinter() || getSeasonSelector() -> isSummer() )
		bridge_1_on();

	else
		bridge_1_off();
}
