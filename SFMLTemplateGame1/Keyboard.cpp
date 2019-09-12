#include "Keyboard.h"

std::unique_ptr<Keyboard> Keyboard::instance = nullptr;

Keyboard::Keyboard() {
	for(auto i = 0; i < KEYBOARD::COUNT_KEY_B; i++) {
		this->keyboard.push_back(false);
	}
}


void Keyboard::setStateKeyboard(KEYBOARD::KEY_B key , bool state) {
	this->keyboard[static_cast<int>(key)] = state;
}

bool Keyboard::getStateKeyBoard(KEYBOARD::KEY_B  key) {
	return this->keyboard[static_cast<int>(key)];
}

void Keyboard::reset() {
	for(auto i = 0; i < KEYBOARD::COUNT_KEY_B; i++) {
		this->keyboard[i] = false;
	}
}

void Keyboard::show() {
	std::cout << "Keyboard map : ";
	for(auto i = 0; i < KEYBOARD::COUNT_KEY_B; i++) {
		std::cout << keyboard[i];
	}
}

Keyboard::~Keyboard() {
}
