// class refrence file : 
//

																						
#include <chrono>																							
#include <thread>
#include <string>																																														
#include <iostream>																							
#include <cstdlib>																							
#include <ctime>																							
#include <cmath>																							
#include <fstream>																							
#include <sstream>																							
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str();													

#include <windows.h>
																									
#include <Mmsystem.h>																																															
																									




class MapTerrain {
	
	public:
	
	int getFromMap(int positionX,int positionY){
		return mapTerrain[positionX][positionY];
	};
	private:
		int mapTerrain[50][50]; // 0 wall, 1 floor, 2 item, 3 lever, 4 sheild, 5 archer, 6 player
		int interact;
};
class InteractiveElement {
	
	public:
	int getThingState(){
	};
	void setThingState(){
	};
	
	private:
	int thingLocationX;
	int thingLocationY;
	int thingState;
	int ID;
};

class Mob : public InteractiveElement {
	
	public:
	
	private:
};

class Npc : public Mob {
	
	public:
	
	private:
	
};
class PcUnit : public Mob {
	
	public:
	
	private:
};
class Item : public Mob {
	
	public:
	int setItemGet(){
		itemPresent = false;
		return itemID;
	};
	private:
	int itemID;
	bool itemPresent;
};






int main(){
	MapTerrain CurrentMap;
	
	Npc badGuy;
	
	PcUnit playerDude;
	
	Item sheild;
	
	
	
	
	return 0;
}