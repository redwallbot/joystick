#pragma once
#include "myjoystick.hpp"

class PLCJoystick : public MyJoyStick {

public:

	PLCJoystick(UINT joy_id);

	void setSpeed(double* speed);

	double* getSpeed();

	virtual void listenJs();

	virtual ~PLCJoystick();


private:
	// 定义右前轮、左前轮、左后轮、右后轮转数
	double* speed = new double[4];
	
};

