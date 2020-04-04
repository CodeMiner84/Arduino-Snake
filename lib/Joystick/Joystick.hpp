#ifndef HOYSTICK_H
#define HOYSTICK_H

class Joystick  
{
	private:

	public:
		int x;
		int y;
		Joystick();
		~Joystick();

		Joystick* ReadAnalog();
		void Debug();
		bool WaitForFirstAction();

		bool IsUp();
		bool IsDown();
		bool IsLeft();
		bool IsRight();
};

#endif