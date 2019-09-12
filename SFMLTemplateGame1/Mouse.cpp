#include "Mouse.h"


std::unique_ptr<Mouse> Mouse::instance = nullptr;
sf::Vector2i  Mouse::pos = sf::Vector2i(0, 0);
int Mouse::mouse_zoom = 0;

Mouse::Mouse() {
	for(auto i = 0; i < MOUSE::COUNT_MOUSE_B; i++) {
		mouse.push_back(false);
		mouse_uniq.push_back(false);
	}
}

Mouse::~Mouse() {
}

void Mouse::setStateMouse(MOUSE::MOUSE_B mousekey, bool state) {
	this->mouse[static_cast<int>(mousekey)] = state;
}

bool Mouse::getStateMouse(MOUSE::MOUSE_B mousekey) {
	return this->mouse[static_cast<int>(mousekey)];
}



void Mouse::reset_real() {
	for(auto i = 0; i < MOUSE::COUNT_MOUSE_B; i++) {
		this->mouse[i] = false;
	}
}

sf::Vector2i Mouse::getMouseScreen() {
	Mouse::pos = sf::Mouse::getPosition();
	return pos;
}

sf::Vector2i Mouse::getMouseWindow(const sf::Window & window) {
	Mouse::pos = sf::Mouse::getPosition(window);
	return Mouse::pos;
}

void Mouse::setMouseScreen(const sf::Vector2i& pos) {
	sf::Mouse::setPosition(pos);
}

void Mouse::setMouseWindow(const sf::Window & window, const sf::Vector2i& pos) {
	sf::Mouse::setPosition(pos, window);
}

void Mouse::show() {
	std::cout << "Mouse map : ";
	for(auto i = 0; i < MOUSE::COUNT_MOUSE_B; i++) {
		std::cout << mouse[i];
	}
	std::cout << std::endl;
}

void Mouse::showMousePos() {
	std::cout << "Mouse : (" << pos.x << " , " << pos.y << ")" << std::endl;
}



// unique_mouse 

void Mouse::reset_unique() {
	for(auto i = 0; i < MOUSE::COUNT_MOUSE_B; i++) {
		this->mouse_uniq[i] = false;
	}
}

bool Mouse::getStateMouseUniq(MOUSE::MOUSE_B mousekey) {
	return this->mouse_uniq[static_cast<int>(mousekey)];
}

void Mouse::setStateMouseUniq(MOUSE::MOUSE_B mousekey, bool state) {
	this->mouse_uniq[static_cast<int>(mousekey)] = state;
}
