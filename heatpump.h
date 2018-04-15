#ifndef heat_pump_h
#define heat_pump_h

#include "definitions.h"
#include "generator.h"


class HeatPump: public Generator{
	public:

		//constructor
		HeatPump( SeasonSelector * const iSeasonSelector, const int & iPin );
		
		//destructor
		~HeatPump();
			
		//acting
		void act();
	
	private:
		SeasonSelector * _seasonSelector = nullptr;

};

#endif