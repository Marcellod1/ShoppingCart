#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <vector>
#include <GLFW/glfw3.h>
#include <iostream>


//Struct to represent the state of a gamepad at any given time.
struct Gamepad {
	float leftStickX;
	float leftStickY;
	float rightStickX;
	float rightStickY;
	float leftTrigger;
	float rightTrigger;
	bool aButton;
	bool bButton;
	bool xButton;
	bool yButton;
	bool leftBump;
	bool rightBump;
	bool backButton;
	bool startButton;
	bool leftStick;
	bool rightStick;
	bool upButton;
	bool rightButton;
	bool downButton;
	bool leftButton;

	bool startButtonJustPressed = false; // hack for now
	bool aButtonJustPressed = false; // hack for now
	bool bButtonJustPressed = false; // hack for now
};

// ONLY HAVE 1 KEYBOARD and MOUSE
struct KeyboardAndMouse {
	bool wKey;
	bool aKey;
	bool sKey;
	bool dKey;
	bool leftShiftKey;
	
	bool spaceKey;
	bool spaceKeyJustPressed = false; // hack for now

	bool pKey;
	bool pKeyJustPressed = false; // hack for now
	
	bool enterKey;
	bool enterKeyJustPressed = false; // hack for now
};


class Broker;

class InputManager {
public:
	InputManager(Broker *broker);
	virtual ~InputManager();
	void init();
	void updateSeconds(double variableDeltaTime);
	Gamepad* getGamePad(int gamePadNumber); // 1, 2, 3, or 4
	KeyboardAndMouse* getKeyboardAndMouse() { return _keyboardAndMouse; }
	int _numGamepads;
private:
	int _joySticks[4] = { GLFW_JOYSTICK_1 ,GLFW_JOYSTICK_2 ,GLFW_JOYSTICK_3 ,GLFW_JOYSTICK_4 };
	std::vector<Gamepad*> _gamePads;
	Broker *_broker = nullptr;
	KeyboardAndMouse *_keyboardAndMouse = new KeyboardAndMouse();
};

#endif // INPUTMANAGER_H_
