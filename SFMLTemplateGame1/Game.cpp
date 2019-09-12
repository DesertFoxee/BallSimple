#include "Game.h"



Game::Game(unsigned int width, unsigned int height, std::string title) {
	this->width = width;
	this->title = title;
	this->height = height;
}


Game::~Game() {
}

void Game::init() {
	sf::ContextSettings setting;
	setting.antialiasingLevel = 8;

	window.create(sf::VideoMode(width, height), title , sf::Style::Default , setting);
	Keyboard::getIntance();
	Mouse::getIntance();

	// setup ball 

}

void Game::handleKeyboard(const sf::Keyboard::Key key, bool state) {
	switch(key) {
		case sf::Keyboard::W:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::UP, state);
			break;
		case sf::Keyboard::S:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::DOWN, state);
			break;
		case sf::Keyboard::A:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::LEFT, state);
			break;
		case sf::Keyboard::D:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::RIGHT, state);
			break;
		case sf::Keyboard::LControl:
		case sf::Keyboard::RControl:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::CONTROL, state);
			break;
		case sf::Keyboard::LShift:
		case sf::Keyboard::RShift:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::SHIFT, state);
			break;
		default:
			break;
	}
}

void Game::handleKeyboardUniq(const sf::Keyboard::Key key, bool state) {
	switch(key) {
		case sf::Keyboard::W:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::UP, state);
			break;
		case sf::Keyboard::S:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::DOWN, state);
			break;
		case sf::Keyboard::A:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::LEFT, state);
			break;
		case sf::Keyboard::D:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::RIGHT, state);
			break;
		case sf::Keyboard::LControl:
		case sf::Keyboard::RControl:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::CONTROL, state);
			break;
		case sf::Keyboard::LShift:
		case sf::Keyboard::RShift:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::SHIFT, state);
			break;
		default:
			break;
	}
}

void Game::handleMouse(const sf::Mouse::Button btn, bool state) {
	switch(btn) {
		case sf::Mouse::Left:
			Mouse::getIntance().setStateMouse(MOUSE::MOUSE_B::LEFT, state);
			break;
		case sf::Mouse::Right:
			Mouse::getIntance().setStateMouse(MOUSE::MOUSE_B::RIGHT, state);
			break;
		case sf::Mouse::Middle:
			Mouse::getIntance().setStateMouse(MOUSE::MOUSE_B::MIDDLE, state);
			break;
		default:
			break;
	}
}

void Game::handleMouseUniq(const sf::Mouse::Button btn, bool state) {
	switch(btn) {
		case sf::Mouse::Left:
			Mouse::getIntance().setStateMouseUniq(MOUSE::MOUSE_B::LEFT, state);
			break;
		case sf::Mouse::Right:
			Mouse::getIntance().setStateMouseUniq(MOUSE::MOUSE_B::RIGHT, state);
			break;
		case sf::Mouse::Middle:
			Mouse::getIntance().setStateMouseUniq(MOUSE::MOUSE_B::MIDDLE, state);
			break;
		default:
			break;
	}
}

void Game::handleMouseScrolled(const sf::Mouse::Wheel wheel , int deltascr) {
	switch(wheel) {
		case sf::Mouse::VerticalWheel:
			std::cout << "Mouse Wheel vertical" << std::endl;
			break;
		case sf::Mouse::HorizontalWheel:
			std::cout << "Mouse Wheel horizontal" << std::endl;
			break;
		default:
			break;
	}
	Mouse::getIntance().Zoom(deltascr);
}

void Game::processBall() {
	if(Keyboard::getIntance().getStateKeyBoard(KEYBOARD::KEY_B::LEFT) 
		&& Mouse::getIntance().getStateMouseUniq(MOUSE::MOUSE_B::LEFT)) {
		Ball ball;
		sf::Vector2i mouse = Mouse::getIntance().getMouseWindow(window);
		ball.init(Vector2D(float(mouse.x), float(mouse.y)), 10.f, 20.f);
		balls.push_back(ball);
	}
}


void Game::update() {
	for(auto &ball : balls) {
		ball.update();
	}
}



// after time remove event keyboard or mouse ;

void Game::process() {
	sf::Event event;

	if(isKeyPressed) {
		Keyboard::getIntance().resetUniq();
		isKeyPressed = false;
	}
	if(isMouseClick) {
		Mouse::getIntance().resetMouseUniq();
		isMouseClick = false;
	}

	while(window.pollEvent(event)) {
		switch(event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				this->handleKeyboard(event.key.code, true);
				this->handleKeyboardUniq(event.key.code, true);
				isKeyPressed = true;
				break;

			case sf::Event::KeyReleased:
				this->handleKeyboard(event.key.code, false);
				isKeyPressed = false;
				break;

			case sf::Event::MouseButtonPressed:
				this->handleMouse(event.mouseButton.button, true);
				this->handleMouseUniq(event.mouseButton.button, true);
				isMouseClick = true;
				break;

			case sf::Event::MouseButtonReleased:
				this->handleMouse(event.mouseButton.button, false);
				isMouseClick = false;
				break;

			case sf::Event::MouseWheelScrolled:
				this->handleMouseScrolled(event.mouseWheelScroll.wheel ,event.mouseWheel.delta);
				break;
			default:
				break;
		}
		
	}
	for(auto & ball : balls) {
		ball.process(window);
	}
	this->processBall();
}

void Game::render() {
	window.clear();

	for(auto & ball : balls) {
		ball.render(window);
	}

	window.display();
}

void Game::run() {
	this->init();

	while(window.isOpen()) {
		
		this->process();
		this->update();
		this->render();
	}	
}
