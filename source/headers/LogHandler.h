#pragma once

class LogHandler {
	
	public:
		LogHandler();
		void logStart();
		void logEvent();
		void logEnd();
		
	protected:	
	
	private:
		int logCount;
		clock_t startTicker;
		clock_t totalTicks;
		double ticksInSeconds;	
		
};