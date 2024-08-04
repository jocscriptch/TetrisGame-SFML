#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Parts
{
private:
	vector<vector<vector<bool>>> parts;
public:
	Parts();
	vector<vector<bool>> consultPart(int);
	void rotatePart(int);
	void desrotatePart(int);
};

