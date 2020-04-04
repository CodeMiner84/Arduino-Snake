class Joystick  
{
	private:
		int x;
		int y;

	public:

		Joystick();
		~Joystick();

		void print();
		void setX(int xCoordination);
		void setY(int yCoordination);

		int getX();
		int getY();
};