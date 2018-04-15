#ifndef rf_valve_h
#define rf_valve_h

#include "valve.h"
#include "temperaturesensor.h"
#include "statemachine.h"
#include "seasonselector.h"

class RF_Valve: public Valve, public StateMachine{
	public:
		//constructor
		RF_Valve( SeasonSelector * const iSeasonSelector,
				  const int & iPin_A,
				  const int & iPin_B,
				  TemperatureSensor * const iSensor_AB,
				  TemperatureSensor * const iSensor_A,
				  TemperatureSensor * const iSensor_B,
				  const unsigned long int & i_tOff,
				  const unsigned long int & i_tOn );

		//destructor
		virtual ~RF_Valve();
		
		//Acting
		void act();
		
		//getters and setters
		const Position & getPosition();

	private:
		Season _previousSeason;
		SeasonSelector * _seasonSelector = nullptr;
		Position _position;
};

#endif