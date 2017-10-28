
#pragma once

using namespace std;
//declare map values

int maxaxisx = 0;
int maxaxisy = 0;
int mapSeedBase = 0;
int roomCenterX = 0;
int roomCenterY = 0;
int roomWidth = 0;
int roomHeight = 0;




////--------------special map functions-----

int getUserMapData(){
	
	while((maxaxisx <= 19)||(maxaxisx >= 41)){
			cout << "you will be prompted to answer questions in number format\n please no letters"<<endl;
			cout << "choose a map width \n 20-40"<<endl;

			cin >> maxaxisx;
		
		}
		
		while((maxaxisy <= 19)||(maxaxisy >= 41)){
			cout << "choose a map height \n 20-40"<<endl;
	
			cin >> maxaxisy;
		}
		
		cout << "choose a map seed\n 0 for random"<<endl;

		cin >> mapSeedBase;
		 if (mapSeedBase == 0){
			 mapSeedBase = rand();	 
		}
		srand (mapSeedBase);
		
		cout << mapSeedBase<<endl;
		return 0;
}
////--------------the map class-----

class Map{
	public:
		Map(){
			setMapDimensionX(maxaxisx);
			setMapDimensionY(maxaxisy);
			setMapSeed(mapSeedBase);
			
			//----------------------display map properties----------------
			cout <<"the Map dimensions will be "<< getMapDimensionX()<<" wide and "<<getMapDimensionY()<<" tall"<<endl;
			cout <<"with a seed number of "<<getMapSeed()<<endl;
		
		}				
		//---------------------map generation functions---------------------
		
		
		//void fillMap(int layer, int fillNumber); not working Q!Q!Q!Q!Q!
		void printMap(int layer);
		
		
		
		
		
		
		
		
		
		
		
		//---------------------setters and getters ---------------------
		//---------------------the width of the map
		void setMapDimensionX(int xDimension){
			mapDimensionX = xDimension;
		}
		int getMapDimensionX(){
			return mapDimensionX;
		}
		//---------------------the height of the map
		void setMapDimensionY(int yDimension){
			mapDimensionY = yDimension;
		}
		int getMapDimensionY(){
			return mapDimensionY;
		}
		//---------------------the seed number of the map
		void setMapSeed(int seedNumber){
			mapSeed = seedNumber;
		}
		int getMapSeed(){
			return mapSeed;
		}
		//---------------------the array
		void setMapArray(int xScan, int yScan, int layerScan, int value){
			mapArray[xScan][yScan][layerScan]= value;
		}
		int getMapSeed(int xScan, int yScan, int layerScan){
			return mapArray[xScan][yScan][layerScan];
		}
	
	
	private:
	
		int mapDimensionX;
		int mapDimensionY;
		int mapSeed;
		int mapArray[40][40][4];
		
	protected:
	
	
};
	
	
	
	
