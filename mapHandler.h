	
#pragma once
#include <iostream>
#include <stdio.h>    
#include <stdlib.h> 
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
	
	while((maxaxisx <= 19)||(maxaxisx >= 65)){
			cout << "you will be prompted to answer questions in number format\n please no letters"<<endl;
			cout << "choose a map width \n 20-64"<<endl;

			cin >> maxaxisx;
		
		}
		
		while((maxaxisy <= 19)||(maxaxisy >= 65)){
			cout << "choose a map height \n 20-64"<<endl;
	
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
		
		};

		
		//---------------------fill map layer with given value---------------------
		
		
		void fillMap(int layer, int fillNumber){
			cout << "\n fill map with "<<fillNumber<<"\n";
			for(int i=0;i< getMapDimensionX(); i++){
				for(int j=0;j< getMapDimensionY(); j++){
					setMapArray(i, j, layer, fillNumber);
				}
			}
		}; 
		//---------------------fill map layer with binary noise---------------------
		void fillMapNoise(int layer, int fillRange){
			cout << "\n fill map with noise from 0 to "<<fillRange <<"\n";
			int noiseValue;
			for(int i=0;i< getMapDimensionX(); i++){
				for(int j=0;j< getMapDimensionY(); j++){
					noiseValue=rand()%(fillRange+1);
					setMapArray(i, j, layer, noiseValue );
				}
			}
		}; 
		
		
		//---------------------smooth out the binary noise maps
		void smoothMap(int layerGet, int layerSet, int neighborCount){
				for (int i = 1; i < getMapDimensionX() - 1; i++) {
					for (int j = 1; j < getMapDimensionY() - 1; j++) {			
							
						if(getMapArray(i - 1,j - 1,layerGet) +
							getMapArray(i,j - 1,layerGet) +
							getMapArray(i + 1,j - 1,layerGet) +
							getMapArray(i - 1,j ,layerGet) +
							getMapArray(i + 1,j ,layerGet) +
							getMapArray(i - 1,j + 1,layerGet) +
							getMapArray(i,j + 1,layerGet) +
							getMapArray(i + 1,j + 1,layerGet) 
							> neighborCount)
							{
							
								setMapArray(i,j,1,1);
							
						}

					}
				}
				
		};
		//---------------------smooth out the binary noise maps
		void killLoners(int layerGet, int layerSet, int neighborCount){
				for (int i = 1; i < getMapDimensionX() - 1; i++) {
					for (int j = 1; j < getMapDimensionY() - 1; j++) {			
							
						if(getMapArray(i - 1,j - 1,layerGet) +
							getMapArray(i,j - 1,layerGet) +
							getMapArray(i + 1,j - 1,layerGet) +
							getMapArray(i - 1,j ,layerGet) +
							getMapArray(i + 1,j ,layerGet) +
							getMapArray(i - 1,j + 1,layerGet) +
							getMapArray(i,j + 1,layerGet) +
							getMapArray(i + 1,j + 1,layerGet) 
							< neighborCount)
							{
							
								setMapArray(i,j,1,0);
							
						} 
					
					}
				}
		};
		//--------------------print the map
		
		void printMap(int layer){
			cout << "\n print the map";
			int scanValue;
		
			for(int i=0;i< getMapDimensionX(); i++){
				cout << endl;
				for(int j=0;j< getMapDimensionY(); j++){
					
					
					scanValue=getMapArray(i, j, layer);
					
					switch(scanValue){
 
						case 0 :
							cout << "0 ";
							break;
					
						case 1 :
							cout << "1 ";
							break;
					
						case 2 :
							cout << "2 ";
							break;
					
						default :
							cout << "  ";
						}
				}
			}
			cout << endl;
		};
		//--------------------print the map fancy
		
		void printMapFancy(int layer){
			cout << "\n print the map";
			cout << endl;
			int scanValue;
		
			for(int i=0;i< getMapDimensionX(); i++){
				
				for(int j=0;j< getMapDimensionY(); j++){
					
					
					scanValue=getMapArray(i, j, layer);
					
					switch(scanValue){
 
						case 0 :
							cout << (char)178u<<(char)178u;
							break;
					
						case 1 :
							cout << (char)176u<<(char)176u;
							break;
					
						case 2 :
							cout << "2 ";
							break;
					
						default :
							cout << "  ";
						}
				}
			cout << endl;
			}
			cout << endl;
		}; 
		
		
		
		
		
		
		
		
		
		
		
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
		int getMapArray(int xScan, int yScan, int layerScan){
			return mapArray[xScan][yScan][layerScan];
		}
	
	
	private:
	
		int mapDimensionX;
		int mapDimensionY;
		int mapSeed;
		int mapArray[64][64][4];
		
	protected:
	
	
};
	
	
	
	
