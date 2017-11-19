#pragma once

class Map {
	public:
		Map();
		
		//setters and getters
		/*
		void setMapXDimension(int xDimension);
		int  getMapXDimension();
		
		void setMapYDimension(int yDimension);
		int  getMapYDimension();
		
		void setMapSeed(int xDimension);
		int  getMapXSeed();
		*/
		int terrainmap[50][50][3];
		int mapXDimension = 30;
		int mapYDimension = 30;
	protected:
	private:
		
		int mapSeed;
		
};