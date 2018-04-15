#include "poolvalve.h"
#include "settings.h"


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

PoolValve::PoolValve(SeasonSelector * const iSeasonSelector,
					 const int & iPin_A, 
					 const int & iPin_B, 
					 TemperatureSensor * const iSensor_AB, 
					 TemperatureSensor * const iSensor_A, 
					 TemperatureSensor * const iSensor_B,
					 const unsigned long int & i_tOff,
					 const unsigned long int & i_tOn):
					 _previousSeason(_winter_),
					 _seasonSelector(iSeasonSelector),
					 Valve(iPin_A, iPin_B, iSensor_AB, iSensor_A, iSensor_B),
					 StateMachine(i_tOff, i_tOn){

					 
					 open_A(); //Initializing at A way position by default
					 _position = _A_;
					 Serial.println("Initializing Pool Valve");
					 delay( get_tOn() );
					 off();
}


//destructor
PoolValve::~PoolValve(){

}

		
//Acting
void PoolValve::act(){

//updating sensors values
getSensor_A() -> loadCurrentValue();
getSensor_AB() -> loadCurrentValue();

//updating season selector value
_seasonSelector -> loadSeason();


Serial.print("******POOL ACT 0 ********** ");
Serial.println( get_tOn() );

	switch (_seasonSelector -> getSeason() ){
	
		case _winter_:
			
			if ( ( getState() == _OFF_ ) &&
			     _previousSeason != _winter_ ) {
			
			   open_A();
			   setState(_ON_);
			   setPreviousTime( millis() );
			   
//			   _previousSeason = _summer_ ;

Serial.println("******POOL ACT 1: WINTER **********");
			   			   
			}
			
			else if ( ( getState() == _ON_ ) &&
					  ( get_tOn() < (millis() - getPreviousTime())) ){
				
			   off();
			   setState(_OFF_);
			   
			   _previousSeason = _winter_ ;
			   _position = _A_;

Serial.println("****** POOL ACT 2: WINTER **********");

			}
			
			break;

		case _summer_:
			//if hot water tank temperature is lower than solar water
			if ( ( getSensor_AB()->getCurrentValue() > getSensor_A()->getCurrentValue() ) && 
			     ( getSensor_A()->isLow() ) &&
			     ( getState() == _OFF_ ) &&
				 ( _position != _A_ )){
			   
			   open_A();
			   setState(_ON_);
			   setPreviousTime( millis() );
			   _position = _A_;

Serial.println("******POOL ACT 1: SUMMER (open A) **********");

			}
			
			//if hot water tank temperature is higher than upper temperature then heat pool
			if ( getSensor_A()->isHigh() &&
			   ( getState() == _OFF_ ) &&
			   ( _position != _B_ ) ){

			   open_B();
			   setState(_ON_);
			   setPreviousTime( millis() );
			   _position = _B_;

Serial.println("******POOL ACT 2: SUMMER (open B) **********");
			
			}
			
			if ( ( getState() == _ON_ ) &&
			     ( get_tOn() < (millis() - getPreviousTime())) ){
					
			   off();
			   setState(_OFF_);
			   
			   _previousSeason = _summer_ ;
			   
Serial.println("******POOL ACT 3: SUMMER **********");

			}
			
			break;	

		
		default:
			if ( ( getState() == _OFF_ ) &&
			     (_previousSeason != _none_) &&
				 (_position != _A_) ) {
			
			   open_A();
			   setState(_ON_);
			   setPreviousTime( millis() );
			

Serial.println("******POOL ACT 1: NONE **********");
			   			   
			}
			
			if ( ( getState() == _ON_ ) &&
			     ( get_tOn() < (millis() - getPreviousTime())) ){
					
			   off();
			   setState(_OFF_);
			   
			   _previousSeason = _none_ ;
			   
Serial.println("******POOL ACT 2: NONE **********");

			}

			break;
	}

}


const Position & PoolValve::getPosition(){
	return _position;
}
