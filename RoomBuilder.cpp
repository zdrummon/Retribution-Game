#include <iostream>
#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>  

using namespace std;

int main() {
	
	srand (time(NULL));
	
//declare map values
	int axisx = 30;
	int axisy = 30;
	int terrainmap[axisx][axisy][3];
	int roomCenterX = 0;
	int roomCenterY = 0;
	int roomWidth = 0;
	int roomHeight = 0;

//fill map with starting values	
	for (int i = 0; i < axisx; i++) {
		for (int j = 0; j < axisy; j++) {
			
			terrainmap[i][j][0] = rand()%2;
			terrainmap[i][j][1] = 1;
			terrainmap[i][j][2] = 0;
		}
	}
	
//print map as grid
	cout << "\n Perlin noise map\n ";
	for (int i = 0; i < axisx; i++) {
		for (int j = 0; j < axisy; j++) {
			
			cout << terrainmap[i][j][0] << " ";
			
			if (j == axisy - 1) {
				cout << "\n ";
			}
		}
	}
	cout << "\n";
	
//smooth map
	for (int loop = 0; loop < 3; loop++) {
		for (int i = 1; i < axisx - 1; i++) {
			for (int j = 1; j < axisy - 1; j++) {			
					
				if ((terrainmap[i - 1][j - 1][0] +
				terrainmap[i][j - 1][0] +
				terrainmap[i + 1][j - 1][0] +
				terrainmap[i - 1][j][0] +
				terrainmap[i + 1][j][0] +
				terrainmap[i - 1][j + 1][0] +
				terrainmap[i][j + 1][0] +
				terrainmap[i + 1][j + 1][0]) > 4) {
				
					terrainmap[i][j][1] = 1;
					
				} else {
					terrainmap[i][j][1] = 0;
				}
			}
		}
		for (int i = 0; i < axisx; i++) {
			for (int j = 0; j < axisy; j++) {
				terrainmap[i][j][0] = terrainmap[i][j][1];
			}
		}
	}
	
//print map as grid
	cout << " Post automata map\n ";
	for (int i = 0; i < axisx; i++) {
		for (int j = 0; j < axisy; j++) {
			
			cout << terrainmap[i][j][1] << " ";
			
			if (j == axisy - 1) {
				cout << "\n ";
			}
		}
	}
	cout << "\n";
	
//generate a room
	roomCenterX = rand() % axisx;
	roomCenterY = rand() % axisy;
	roomWidth = rand() % 5 + 6;
	roomHeight = rand() % 5 + 6;
	
	if (roomCenterX - roomWidth/2 - 1 < 0) {
		roomCenterX = roomCenterX + roomWidth/2;
	}
	else if (roomCenterX + roomWidth/2 + 1 > 30) {
		roomCenterX = roomCenterX - roomWidth/2;
	}
	
	if (roomCenterY - roomHeight/2 - 1 < 0) {
		roomCenterY = roomCenterY + roomHeight/2;
	}
	else if (roomCenterY + roomHeight/2 + 1 > 30) {
		roomCenterY = roomCenterY - roomHeight/2;
	}
	
//map a room	
	for (int i = (roomCenterX - roomWidth/2 - 1); i < (roomWidth + roomCenterX); i++) {
		for (int j = (roomCenterY - roomHeight/2 - 1); j < (roomHeight + roomCenterY); j++) {
			
			terrainmap[i][j][2] = 2;
		}
	}
	
	cout << " Post architecture map\n ";
	for (int i = 0; i < axisx; i++) {
		for (int j = 0; j < axisy; j++) {
			
			if (terrainmap[i][j][2] == 2) {
				cout << terrainmap[i][j][2] << " ";
			} else {
			cout << terrainmap[i][j][1] << " ";
			}
			
			if (j == axisy - 1) {
				cout << "\n ";
			}
		}
	}
	cout << "\n";
	
	
	return 0;
}