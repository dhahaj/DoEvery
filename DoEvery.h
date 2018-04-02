#pragma once

#define LIBRARY_VERSION	"1.0.0"

#include <inttypes.h>

#if ARDUINO >= 100
#include <Arduino.h> 
#else
#include <WProgram.h> 
#endif

class DoEvery
{
	public:
		DoEvery(void);
		DoEvery(long);
		void reset();
		bool check();
		bool before(double);
		void setPeriod(double);
		void stop(void);
		void start(void);

	private:
		unsigned long period;
		unsigned long savedPeriod;
		unsigned long lastTime;
};

