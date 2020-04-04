#ifndef MATRIX_H
#define MATRIX_H
#include <Joystick.cpp>

class Matrix  
{
	private:
		int x;
		int y;
		Joystick* joystick;
		static const int MIN = 0;
		static const int MAX = 7;

	public:
		static const int SIZE = 8;

		Matrix();
		~Matrix();

		void ChangeCoordinates(int x, int y);
		void Print();
		void AssignJoystick(Joystick* joystick);
		void MoveSnake();

		int GetX();
		int GetY();
};

#endif