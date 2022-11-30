#pragma once
#include "EarthWorm.h"

class Point :EarthWorm
{
private:
	COORD XY;
public:
	COORD ReturnXY()
	{
		while (1)
		{
			srand(time(NULL));
			XY.X = rand() % 36 + 27;
			XY.Y = rand() % 18 + 11;
			return XY;
		}
	}
	void CreatePoint(int X, int Y)
	{
		GoTo_XY(X, Y);
		DrawPoint();
	}
};