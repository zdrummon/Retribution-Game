#pragma once

class Map {
	public:
		Map(){};
		
		//setters and getters
		void setMapXDimension(int xDimension);
		int  getMapXDimension();
		
		void setMapYDimension(int yDimension);
		int  getMapYDimension();
		
		void setMapSeed(int xDimension);
		int  getMapXSeed();
		
		
	protected:
	private:
		int mapXDimension;
		int mapYDimension;
		int mapSeed;
};