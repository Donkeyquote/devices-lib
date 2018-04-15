#ifndef seasonselector_h
#define seasonselector_h

#include "device.h"


class SeasonSelector: public Device{
	public:
		//constructor
		SeasonSelector(const int & iPin, const int & iAuxPin);
		
		//destructor
		virtual ~SeasonSelector();
		
		//getters and setters
		const Season & getSeason();
		void setSeason(const Season & iSeason);
	
		//mode
		bool isWinter();
		bool isSummer();
		
		//read selector button
		void loadSeason();
		
	private:		
		//attributes
		Season _season; // associated selector position
		int _auxPin;

};

#endif