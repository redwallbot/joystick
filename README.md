# 控制蓝牙手柄（罗技）

myjoystick.hpp为主要的头文件，要想实现具体的功能，需要继承MyJoystick并重写`updateStatus`和`listenJs`方法，可以参考代码中的PLCJoystick的例子。