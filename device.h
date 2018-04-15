#ifndef device_h
#define device_h

#include "definitions.h"

class Device {
	public:
		//constructor
		Device(const int & iPin, const Mode & iMode);
		
		//destructor
		virtual ~Device();
		
		//getters and setters
		void setPin(const int & iPin);
		const int & getPin();
		
		void setMode(const Mode & iMode);
		const Mode & getMode();
		
	protected:		
		//attributes
		int _pin; // A0, 7,...
		Mode _mode; //INPUT or OUTPUT

};

#endif