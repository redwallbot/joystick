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
		if (speed == NULL) {
			continue;
		}
		cout << "x_speed:" << speed[0] << "\ty_speed:" << speed[1] << "\tw_speed:" << speed[2] << endl;
		Sleep(100);
	}
	
	return 0;
}
