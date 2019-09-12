#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Convert.h"

/*

	-Get number keyboard in enum class using Complie = current line - begin line - space


*/



constexpr auto BEGIN_KEYBOARD = __LINE__;
namespace KEYBOARD
{
	enum class KEY_B
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		CONTROL,
		SHIFT,
	};
	constexpr static auto COUNT_KEY_B = __LINE__ - BEGIN_KEYBOARD - 4;

	enum class KEY_E
	{
		COUNT
	};
}


class Keyboard
{
public:
	~Keyboard();

	static Keyboard& getIntance()
	{
		if (instance == nullptr) {
			instance = std::unique_ptr<Keyboard>(new Keyboard());
		}
		return *instance;
	}


	//using for keyboard one click
	void resetUniq();
	void setStateKeyboardUniq(KEYBOARD::KEY_B key, bool state);
	bool getStateKeyBoardUniq(KEYBOARD::KEY_B key);

	// using for keyboard real_time 
	void setStateKeyboard(KEYBOARD::KEY_B key, bool state);
	bool getStateKeyBoard(KEYBOARD::KEY_B key);
	void resetReal();

	// function test

	void show();

private:
	Keyboard();

	std::vector<bool> keyboard;
	std::vector<bool> keyboard_uniq;

	static std::unique_ptr<Keyboard> instance;
};

#endif // !KEYBOARDMANAGER_H


