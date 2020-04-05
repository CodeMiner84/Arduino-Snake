#ifndef GAME_H
#define GAME_H
#include <Matrix.cpp>
#include <LedControl.h>

class Game  
{
	private:
		Matrix* matrix;
		Joystick* joystick;
		bool gameOver = false;
		bool gameStarted = false;

	public:
		Game();
		~Game();
		void Initialize(LedControl* lc);
		void Display();
		void StartGameOnFirstMove();
		void StartGame();
		bool IsStarted();
		bool IsGameOver();
		void GameOver();

};

#endif