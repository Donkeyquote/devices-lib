#include "seasonselector.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "definitions.h"


SeasonSelector::SeasonSelector( const int & iPin, const int & iAuxPin ) : 
							    Device(iPin, _input_),
								_auxPin(iAuxPin),
								_season(_winter_){

}
		

SeasonSelector::~SeasonSelector(){

}
		

const Season & SeasonSelector::getSeason(){

	return _season;

}


void SeasonSelector::setSeason(const Season & iSeason){

	_season = iSeason;

}
	

bool SeasonSelector::isWinter(){

	loadSeason();

	if ( _season == _winter_)
		return true;
	
	else
		return false;
}


bool SeasonSelector::isSummer(){

	loadSeason();

	if ( _season == _summer_ )
		return true;
	
	else
		return false;
}
		

void SeasonSelector::loadSeason(){

	if ( digitalRead( getPin() ) == HIGH )
		_season = _winter_;

	else if ( digitalRead( _auxPin ) == HIGH )
		_season = _summer_;
	
	else
		_season = _none_;
	
}
