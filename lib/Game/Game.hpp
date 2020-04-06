#ifndef GAME_H
#define GAME_H
#include <Matrix.cpp>
#include <LedControl.h>

class Game  
{
	private:
		bool gameOver = false;
		bool gameStarted = false;
		Matrix* matrix;
		Joystick* joystick;

	public:
		Game();
		~Game();
		void Initialize(LedControl* lc);
		void Display();
		void StartGameOnFirstMove();
		void StartGame();
		void GameOver();
		bool IsStarted();
		bool IsGameOver();

};

#endif