#pragma once


class LogHandler {
	public:
		void logStart();
		void logEvents();
		void logEnd();
	protected:	
	private:
		int logCount;
		clock_t startTicker;
		clock_t totalTicks;
		double ticksInSeconds;
	
		
};