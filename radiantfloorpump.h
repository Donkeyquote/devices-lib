#ifndef radiant_floor_pump_h
#define radiant_floor_pump_h

#include "pump.h"
#include "seasonselector.h"


class RadiantFloorPump: public Pump{
	public:
		//constructor
		RadiantFloorPump( const int & iPin,
						  SeasonSelector * const iSeasonSelector);
		
		
		//destructor
		virtual ~RadiantFloorPump();
	
		//Acting
		void act();
		
	private:
		SeasonSelector * _seasonSelector = nullptr;

};

#endif
