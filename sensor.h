#ifndef sensor_h
#define sensor_h

#include "device.h"


class Sensor: public Device{
	public:
		//constructor
		Sensor(const int & iPin,
			   const float & iLowerThreshold,
			   const float & iUpperThreshold,
			   const float & iSetupValue);
		
		//destructor
		virtual ~Sensor();
		
		//getters and setters
		const float & getLowerThreshold();
		void setLowerThreshold(const float & iLowerThreshold);
		
		const float & getUpperThreshold();
		void setUpperThreshold(const float & iUpperThreshold);
		
		const float & getSetupValue();
		void setSetupValue(const float & iSetupValue);
		
		const float & getCurrentValue();
		void setCurrentValue(const float & iCurrentValue);
		
		virtual void loadCurrentValue();

	
		//Acting
		bool inRange();
		bool isLow();
		bool isHigh();
		
	private:		
		//attributes
		float _lower_threshold; // associated sensor device: temperature, light, pressure,...
		float _upper_threshold;
		float _set_up_value;
		float _current_value;
};

#endif