//libraries
#include <ctime>
#include <stdio.h>
#include <string>
//headers
#include "headers/LogHandler.h"
//namespaces
using namespace std;

LogHandler::LogHandler() {}

void LogHandler::logStart() {
	
	startTicker = clock();
	logCount = 0;
	printf ("\n DEBUG LOG\n =============================="); 
	logEvent();
	printf ("program has started"); 
}

void LogHandler::logEvent() {
	
	++logCount;
	totalTicks = clock() - startTicker;
	ticksInSeconds = totalTicks / (double) CLOCKS_PER_SEC;
	printf ("\n [Event %.6i - %.3f seconds]: ", logCount, ticksInSeconds);
}

void LogHandler::logEnd() {
	
	logEvent();
	printf ("program has ended\n ==============================\n");
}
