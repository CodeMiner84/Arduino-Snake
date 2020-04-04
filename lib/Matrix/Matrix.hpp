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

		void changeCoordinates(int x, int y);
		void print();

		int getX();
		int getY();
};

#endif