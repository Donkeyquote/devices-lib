#ifndef boiler_h
#define boiler_h

#include "definitions.h"
#include "generator.h"
#include "temperaturesensor.h"

class Boiler: public Generator{
	public:

		//constructor
		Boiler( SeasonSelector * const iSeasonSelector,
				TemperatureSensor * const iTemperatureSensor,
				const int & iPin );

		//destructor
		~Boiler();
			
		//acting
		void act();
	

};

#endif