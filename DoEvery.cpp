#include <DoEvery.h>

DoEvery::DoEvery(void) 
{
	period = -1;
	lastTime = 0;
}

DoEvery::DoEvery(long _period) 
{
	period = _period;
	lastTime = 0;
}

void DoEvery::reset()
{
	lastTime = millis();
}

bool DoEvery::check()
{
	if(period < 0) return false;
	
	if (millis() - lastTime > period) {
		lastTime += period;
		return true;
	} else
		return false;
}

bool DoEvery::before(double threshTime)
{	
	if(period < 0) return false;
	
	if (millis() - lastTime < threshTime) 
		return true;
	else 
		return false;
}

void DoEvery::setPeriod(double _period)
{
	period = _period;
	this->reset();
}

void DoEvery::stop(void)
{
	savedPeriod = period;
	period = -1;
	this->reset();
}

void DoEvery::start(void)
{
	period = savedPeriod;
	this->reset();
}