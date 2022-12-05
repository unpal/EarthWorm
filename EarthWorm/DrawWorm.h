#pragma once

#include "EarthWorm.h"
class DrawWorm:EarthWorm
{
private:
	int WormLange;
	COORD WormLocation[2];
public:
	void CreateWorm()
	{
		WormLocation[0].X = 40;
		WormLocation[0].Y = 15;
		WormLocation[1].X = 47;
		WormLocation[1].Y = 19;
	}
	void Move_Worm_Left()
	{
		Erase();
		GoTo_XY(WormLocation[0].X - 2, WormLocation[0].Y);
		for (WormLange = 0; WormLange < 9; WormLange++)
		{
			if (WormLange < 5)
				GoTo_XY(WormLocation[0].X - 2 + (WormLange * 2), WormLocation[0].Y);
			if (WormLange >= 5)
				GoTo_XY(WormLocation[0].X - 2, WormLocation[0].Y + (WormLange - 4));
			DrawEarthWorm();
		}
		WormLocation[0].X = WormLocation[0].X - 2;
	}
	void Move_Worm_Right()
	{
		Erase();
		GoTo_XY(WormLocation[0].X + 2, WormLocation[0].Y);
		for (WormLange = 0; WormLange < 9; WormLange++)
		{
			if (WormLange < 5)
				GoTo_XY(WormLocation[0].X - 2 + (WormLange * 2), WormLocation[0].Y);
			if (WormLange >= 5)
				GoTo_XY(WormLocation[0].X - 2, WormLocation[0].Y + (WormLange - 4));
			DrawEarthWorm();
		}
		WormLocation[0].X = WormLocation[0].X + 2;
	}
	void Move_Worm_Up()
	{
		Erase();
		GoTo_XY(WormLocation[0].X, WormLocation[0].Y-1);
		for (WormLange = 0; WormLange < 9; WormLange++)
		{
			if (WormLange < 5)
				GoTo_XY(WormLocation[0].X - 2 + (WormLange * 2), WormLocation[0].Y);
			if (WormLange >= 5)
				GoTo_XY(WormLocation[0].X - 2, WormLocation[0].Y + (WormLange - 4));
			DrawEarthWorm();
		}
		WormLocation[0].Y = WormLocation[0].Y-1;
	}
	void Move_Worm_Down()
	{
		Erase();
		GoTo_XY(WormLocation[0].X, WormLocation[0].Y+1);
		for (WormLange = 0; WormLange < 9; WormLange++)
		{
			if (WormLange < 5)
				GoTo_XY(WormLocation[0].X - 2 + (WormLange * 2), WormLocation[0].Y);
			if (WormLange >= 5)
				GoTo_XY(WormLocation[0].X - 2, WormLocation[0].Y + (WormLange - 4));
			DrawEarthWorm();
		}
		WormLocation[0].Y = WormLocation[0].Y + 1;
	}
	int GetCommand() {
		if (_kbhit()) {
			return _getch();
		}

		return -1;
	}
};