#include "Parts.h"

// constructr para pintar los bloques del tetris
Parts::Parts() {
	parts = { 
				{
					{1,1},
					{1,1}
				},

				{
					{0,0,0,0,0},
					{0,0,1,0,0},
					{0,0,1,1,0},
					{0,0,0,1,0},
					{0,0,0,0,0}
				},

				{
					{0,0,0,0,0},
					{0,0,0,1,0},
					{0,0,1,1,0},
					{0,0,1,0,0},
					{0,0,0,0,0}
				},

				{		
					{0,0,0,0,0},
					{0,0,1,1,0},
					{0,0,1,0,0},
					{0,0,1,0,0},
					{0,0,0,0,0}
				},

				{
					{0,0,0,0,0},
					{0,1,1,0,0},
					{0,0,1,0,0},
					{0,0,1,0,0},
					{0,0,0,0,0}
				},

				{
					{0,0,0,0,0},
					{0,0,1,0,0},
					{0,0,1,1,0},
					{0,0,1,0,0},
					{0,0,0,0,0}
				},

				{
					{0,0,1,0},
					{0,0,1,0},
					{0,0,1,0},
					{0,0,1,0}
				} 
	};
}


vector<vector<bool>> Parts::consultPart(int id) {
	return parts[id];
}

void Parts::rotatePart(int ind) {
	vector<vector<bool>> vAux = parts[ind];
	int indI = 0, indJ = 0;
	int sz = (int)parts[ind].size();
	for (int i = 0; i < sz; i++) {
		for (int j = sz - 1; j >= 0; j--) {
			parts[ind][indI][indJ] = vAux[j][i];
			indJ++;
		}
		indI++;
		indJ = 0;
	}
}

void Parts::unRotatePart(int ind) {
	vector<vector<bool>> vAux = parts[ind];
	int indI = 0, indJ = 0;
	int sz = (int)parts[ind].size();
	for (int i = sz - 1; i >= 0; i--) {
		for (int j = 0; j < sz; j++) {
			parts[ind][indI][indJ] = vAux[j][i];
			indJ++;
		}
		indI++;
		indJ = 0;
	}
}