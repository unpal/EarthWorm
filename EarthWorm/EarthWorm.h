#pragma once
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#include<iostream>
#include<Windows.h>
#include<String>
#include<stdlib.h>
#include<time.h>
#include<thread>
#include<conio.h>

using namespace std;
class EarthWorm
{
private:
	string MainBord[2] = { "бр" ,"бр"};
	string BordCramps[4] = { "бр", "бр", "бр", "бр" };
	string Point = "г└";
	string Worm = "б█";
public:
	void GoTo_XY(int X, int Y)
	{
		COORD pos;
		pos.X = X;
		pos.Y = Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	void DrawMainBord(int OrderBord)
	{
		cout << MainBord[OrderBord];
	}
	void DrawBordCramp(int OrderCramp)
	{
		cout << BordCramps[OrderCramp];
	}
	void DrawPoint()
	{
		cout << Point;
	}
	void DrawEarthWorm()
	{
		cout << Worm;
	}
	void Erase()
	{
		system("cls");
	}
};