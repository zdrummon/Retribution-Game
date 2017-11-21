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
		
		double ticksInSeconds;	
		
};