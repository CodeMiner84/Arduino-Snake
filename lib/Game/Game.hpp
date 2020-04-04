#ifndef GAME_H
#define GAME_H
#include <Matrix.cpp>

class Game  
{
	private:
		Matrix* matrix;
	public:

		Game();
		~Game();
		void Initialize(Matrix* matrix);

};

#endif