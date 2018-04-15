#ifndef photo_sensor_h
#define photo_sensor_h

#include "sensor.h"


class PhotoSensor: public Sensor{
	public:
		//constructor
		PhotoSensor(const int & iPin,
					const float & iLowerThreshold = 0,
					const float & iUpperThreshold = 0,
					const float & iSetupValue = 0,
					const State & iState = _OFF_);

		//destructor
		virtual ~PhotoSensor();
		
		//getters and setters
		const State & getState();
		void setState(const State & iState);
		
		//status
		void loadState();
		
		//boolean state check
		bool isOn();


		
	private:		
		//attributes
		State _state;
};

#endif