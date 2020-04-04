#ifndef MATRIX_H
#define MATRIX_H

class Matrix  
{
	private:
		int x;
		int y;

	public:

		Matrix();
		~Matrix();

		void ChangeCoordinates(int x, int y);
		void Print();

		int GetX();
		int GetY();
};

#endif