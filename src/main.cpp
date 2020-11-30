#include "plc_joystick.h"


int main(int argc, char** argv) {

	PLCJoystick joystick(JOYSTICKID1);
	double* speed;
	bool is_connect = joystick.getJsCaps();
	while(is_connect){
		if (!joystick.updateStatus()) {
			break;
		}
		joystick.listenJs();
		// memcpy(speed, joystick.getSpeed(), sizeof(speed));
		speed = joystick.getSpeed();
		cout << "speed:" << speed[0] << "\t" << speed[1] << "\t" << speed[2] << "\t" << speed[3] << endl;
		Sleep(100);
	}
	
	return 0;
}
