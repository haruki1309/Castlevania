#pragma once
#include <dinput.h>


#define DIRECTINPUT_VERSION 0x0800
#define KEYBOARD_BUFFER_SIZE 1024


class InputDevice
{
private:
	static InputDevice * instance;

	LPDIRECTINPUT8       di;		         
	LPDIRECTINPUTDEVICE8 didv;		

	BYTE  keyStates[256];	

	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		

public:
	InputDevice();
	~InputDevice();

	bool Initialize(HWND hWnd);

	int IsKeyDown(int keyCode);

	void ProcessKeyBoard();

	static InputDevice * GetInstance();
};

typedef InputDevice * LPINPUTDEVICE;

