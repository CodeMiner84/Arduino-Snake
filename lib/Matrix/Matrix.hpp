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
		static const int MIN = 0;
		static const int MAX = 7;
		static const int MAX_SEGMENTS = 15;
		enum directions { up, down, left, right };
		int SnakeSegments;
		int currentDirection;
		LedControl* lc;
		Joystick* joystick;
		Point Snake[MAX_SEGMENTS];
		Point TmpSnake[MAX_SEGMENTS];
		Point Food;

	public:
		static const int SIZE = 8;

		Matrix(Joystick* joystick, LedControl* lc);
		~Matrix();

		void ChangeHeadCoordinates(int x, int y);
		void Print();
		void AssignJoystick(Joystick* joystick);
		void MoveSnake();
		void DisplaySnake();
		void PlaceSnake();
		void GenerateFood();
		void YouLooseScreen();
		void DisplayImage(const byte* image);
		void AddNewBodySegment();
		void BlinkDiode(Point point, bool active = true);
		void YouWinScreen();
		bool hasEatOwnBody();
};

#endif