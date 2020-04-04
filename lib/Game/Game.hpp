#ifndef GAME_H
#define GAME_H
#include <Matrix.cpp>
#include <LedControl.h>

class Game  
{
	private:
		Matrix* matrix;
		String currentDirection;
		enum directions { up, down, left, right };
	public:

		Game();
		~Game();
		void Initialize();
		void Display(LedControl lc);

};

#endif