#include "plc_joystick.h"

#define MAX_SPEED 27648.0
#define XY_MAX_SPEED 19550.0
#define MEDIUM_SPEED 15000.0

#define DRIFTING_VALUE 0.1

PLCJoystick::PLCJoystick(UINT joy_id) : MyJoyStick(joy_id) {
	speed = new double[]{ 0.0, 0.0, 0.0, 0.0 };
}

void PLCJoystick::setSpeed(double* speed) {
	this->speed = speed;
}

double* PLCJoystick::getSpeed() {
	return speed;
}

void PLCJoystick::listenJs(){
	cout << listen_flag << endl;
	if (!listen_flag) return;
	
	switch (cur_dire_btn){
	case 0:
		//cout << "方向键上" << endl;
		speed = new double[] {MAX_SPEED, MAX_SPEED, MAX_SPEED, MAX_SPEED};

		return;
	case 18000:
		//cout << "方向键下" << endl;
		speed = new double[] {-MAX_SPEED, -MAX_SPEED, -MAX_SPEED, -MAX_SPEED};

		return;
	case 27000:
		//cout << "方向键左" << endl;
		speed = new double[] {MAX_SPEED, -MAX_SPEED, MAX_SPEED, -MAX_SPEED};

		return;
	case 9000:
		//cout << "方向键右" << endl;
		speed = new double[] {-MAX_SPEED, MAX_SPEED, -MAX_SPEED, MAX_SPEED};

		return;
	default:
		break;
	}

	// cout << "xy坐标：（" << xy_point.x << "," << xy_point.y << "）" << endl;
	// cout << "uv坐标：（" << uv_point.x << "," << uv_point.y << "）" << endl;

	if(uv_point.y > 0 && (xy_point.x || xy_point.y)){
		speed = new double[] {XY_MAX_SPEED* uv_point.y*(-xy_point.x + xy_point.y), XY_MAX_SPEED* uv_point.y* (xy_point.x + xy_point.y), XY_MAX_SPEED* uv_point.y* (-xy_point.x + xy_point.y), XY_MAX_SPEED* uv_point.y* (xy_point.x + xy_point.y)};
	}
	else if (uv_point.x != 0 && fabs(uv_point.y) < DRIFTING_VALUE) {
		speed = new double[] {-MEDIUM_SPEED * uv_point.x, MEDIUM_SPEED* uv_point.x, MEDIUM_SPEED* uv_point.x, -MEDIUM_SPEED * uv_point.x };

	}
	else if (uv_point.y < 0) {
		speed = new double[] {MEDIUM_SPEED* uv_point.y, MEDIUM_SPEED* uv_point.y, MEDIUM_SPEED* uv_point.y, MEDIUM_SPEED* uv_point.y};
	}
	else {
		speed = new double[] {0.0, 0.0, 0.0, 0.0};
	}



	/*if (cur_btn != pre_btn)
	{
		switch (cur_btn) {
		case 2:
			cout << "A" << endl;
			break;
		case 4:
			cout << "B" << endl;
			break;
		case 1:
			cout << "X" << endl;
			break;
		case 8:
			cout << "Y" << endl;
			break;
		case 16:
			cout << "LB" << endl;
			break;
		case 32:
			cout << "LR" << endl;
			break;
		case 64:
			cout << "LT" << endl;
			break;
		case 128:
			cout << "RT" << endl;
			break;
		case 256:
			cout << "Back" << endl;
			break;
		case 512:
			cout << "Start" << endl;
			break;
		default:
			break;
		}
		pre_btn = cur_btn;
	}*/
}

PLCJoystick::~PLCJoystick() {
	if (joy_info != NULL)
	{
		delete joy_info;
		joy_info = NULL;
	}
	if (speed != NULL) {
		delete speed;
		speed = NULL;
	}
}