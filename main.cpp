#include <iostream>
#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>  

using namespace std;

int main()
{
	srand (time(NULL));
	
//declare map values
	int axisx = 40;
	int axisy = 40;
	int terrainmap[axisx][axisy][2];

//fill map with boolean values	
	for (int i = 0; i < axisx; i++) {
		for (int j = 0; j < axisy; j++) {
			
			terrainmap[i][j][0] = rand()%2;
			terrainmap[i][j][1] = 1;
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
	
	return 0;
}