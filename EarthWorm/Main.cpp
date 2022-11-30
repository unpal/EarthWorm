#include "DrawBord.h"
#include "Point.h"
#include "DrawWorm.h"
using namespace std;
int main()
{
	static DrawBord drawbord;
	static COORD PointLocation[10];
	static Point drawpoint;
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
			DrawWorm drawworm;
			drawworm.CreateWorm();
			char Input;
			while (true)
			{
					Input = drawworm.GetCommand();
					if (Input != -1)
					{
						if (Input == UP)
							drawworm.Move_Worm_Up();
						if (Input == DOWN)
							drawworm.Move_Worm_Down();
						if (Input == LEFT)
							drawworm.Move_Worm_Left();
						if (Input == RIGHT)
							drawworm.Move_Worm_Right();
						drawbord.CreateBord();
						for (int i = 0; i < 9; i++)
						{
							if (PointLocation[i].X != 0)
							{
								drawpoint.CreatePoint(PointLocation[i].X, PointLocation[i].Y);
							}
						}
					}
			}
		});
	Thread_1.join();
	Thread_2.join();

}