#ifndef HOYSTICK_H
#define HOYSTICK_H

class Joystick  
{
	private:
		int x;
		int y;

	public:
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