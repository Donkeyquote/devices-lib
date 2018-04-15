#ifndef pool_valve_h
#define pool_valve_h

#include "valve.h"
#include "temperaturesensor.h"
#include "statemachine.h"
#include "seasonselector.h"


class PoolValve: public Valve, public StateMachine{
	public:
		//constructor
		PoolValve( SeasonSelector * const iSeasonSelector,
				   const int & iPin_A, 
				   const int & iPin_B, 
				   TemperatureSensor * const iSensor_AB,
				   TemperatureSensor * const iSensor_A,
				   TemperatureSensor * const iSensor_B,
				   const unsigned long int & i_tOff,
				   const unsigned long int & i_tOn);
		
		//destructor
		virtual ~PoolValve();
		
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