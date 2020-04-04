#ifndef MATRIX_H
#define MATRIX_H
#include <Joystick.cpp>

class Matrix  
{
	private:
		int x;
		int y;
		Joystick* joystick;

	public:
		static const int SIZE = 8;

		Matrix();
		~Matrix();

		void ChangeCoordinates(int x, int y);
		void Print();
		void AssignJoystick(Joystick* joystick);
		void LogMatrix();

		int GetX();
		int GetY();
};

#endif