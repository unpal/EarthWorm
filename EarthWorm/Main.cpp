#include "DrawBord.h"
#include "Point.h"
#include "DrawWorm.h"
using namespace std;
int main()
{
	static DrawBord drawbord;
	static COORD PointLocation[10];
	static Point drawpoint;
	static int MoveCase = 3;
	static DrawWorm drawworm;
	thread Thread_1 = thread([] 
		{
			while (true)
			{
				Sleep(3000);
				for (int i = 0; i < 9; i++)
				{
					if (PointLocation[i].X == 0)
					{
						PointLocation[i] = drawpoint.ReturnXY();
						for (int i = 0; i < 9; i++)
						{
							if (PointLocation[i].X != 0)
							{
								drawpoint.CreatePoint(PointLocation[i].X, PointLocation[i].Y);
							}
						}
						break;
					}
				}
			}
		});
	thread Thread_2 = thread([]
		{
			drawworm.CreateWorm();
			while (true)
			{
						switch (MoveCase)
						{
						case 1:
							drawworm.Move_Worm_Up();
							break;
						case 2:
							drawworm.Move_Worm_Down();
							break;
						case 3:
							drawworm.Move_Worm_Left();
							break;
						case 4:
							drawworm.Move_Worm_Right();
							break;
						}
						drawbord.CreateBord();
						for (int i = 0; i < 9; i++)
						{
							if (PointLocation[i].X != 0)
							{
								drawpoint.CreatePoint(PointLocation[i].X, PointLocation[i].Y);
							}
						}
						Sleep(500);
			}
		});
	thread Thread_3 = thread([]
		{
			while (true)
			{
				char Input;
				Input = drawworm.GetCommand();
				if (Input != -1)
				{
					if (Input == UP)
						MoveCase = 1;
					if (Input == DOWN)
						MoveCase = 2;
					if (Input == LEFT)
						MoveCase = 3;
					if (Input == RIGHT)
						MoveCase = 4;
				}
			}
		});
	Thread_1.join();
	Thread_2.join();

}