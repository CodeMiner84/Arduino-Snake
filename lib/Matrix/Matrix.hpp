#ifndef MATRIX_H
#define MATRIX_H
#include <Joystick.cpp>
#include "Point.hpp"
#include <LedControl.h>


class Matrix  
{
	private:
		int x;
		int y;
		LedControl* lc;
		Joystick* joystick;
		static const int MIN = 0;
		static const int MAX = 7;
		int currentDirection;
		enum directions { up, down, left, right };
		int SnakeSize;
		Point Snake[10];
		Point TmpSnake[10];


	public:
		static const int SIZE = 8;

		Matrix(Joystick* joystick, LedControl* lc);
		~Matrix();

		void ChangeCoordinates(int x, int y);
		void Print();
		void AssignJoystick(Joystick* joystick);
		void MoveSnake();
		void DisplaySnake();
		void PlaceSnake();
};

#endif