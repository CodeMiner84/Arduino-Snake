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
};