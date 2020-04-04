#ifndef GAME_H
#define GAME_H
#include <Matrix.cpp>
#include <LedControl.h>

class Game  
{
	private:
		Matrix* matrix;
		Joystick* joystick;
	public:

		Game();
		~Game();
		void Initialize();
		void Display(LedControl lc);
		bool gameStarted = false;
		void StartGameOnFirstMove();
		void StartGame();
		bool IsStarted();

};

#endif