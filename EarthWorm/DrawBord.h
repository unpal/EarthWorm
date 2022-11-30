#include "EarthWorm.h"

class DrawBord:EarthWorm
{
public:
	void CreateBord()
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int i = 1; i <= 20; i++)
			{
				if(j == 1)
					GoTo_XY(25 + (i * 2), 10);
				if (j == 2)
					GoTo_XY(65, 10 + i);
				if (j == 3)
					GoTo_XY(65 - (i * 2), 30);
				if (j == 4)
					GoTo_XY(25, 30 - i);
				if(j % 2 == 1&& i != 20)
					DrawMainBord(0);
				if (j % 2 == 0&&i !=20)
					DrawMainBord(1);
			}
			DrawBordCramp(j-1);
		}
	}
};
