#ifndef GAME_H
#define GAME_H
#include <Matrix.cpp>
#include <LedControl.h>

class Game  
{
	private:
		Matrix* matrix;
	public:

		Game();
		~Game();
		void Initialize(Matrix* matrix);
		void Display(LedControl lc);

};

#endif