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

		void print();
		void setX(int xCoordination);
		void setY(int yCoordination);

		int getX();
		int getY();
};

#endif