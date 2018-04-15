#include "radiantfloorpump.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif



RadiantFloorPump::RadiantFloorPump( const int & iPin, 
									SeasonSelector * const iSeasonSelector) : 
									Pump(iPin, nullptr, nullptr), 
									_seasonSelector (iSeasonSelector){

}


//destructor
RadiantFloorPump::~RadiantFloorPump(){
	
}


void RadiantFloorPump::act(){

	_seasonSelector -> loadSeason();
	
	if ( !_seasonSelector -> isWinter() && !_seasonSelector -> isSummer() )
		digitalWrite( getPin(), HIGH );
	
	else
		digitalWrite( getPin(), LOW );
}
