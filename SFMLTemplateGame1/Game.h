#ifndef GAME_H
#define GAME_H

#include "Keyboard.h"
#include "Mouse.h"
#include "Ball.h"
#include "Asset.h"

class Game {
	public:
		Game(unsigned int width, unsigned int height, std::string title);
		~Game();
		void run();

	private:
		void init();
		void handleKeyboard(const sf::Keyboard::Key key, bool state);
		void handleKeyboardUniq(const sf::Keyboard::Key key, bool state);
		void handleMouse(const sf::Mouse::Button btn, bool state);
		void handleMouseUniq(const sf::Mouse::Button btn, bool state);
		void handleMouseScrolled(const sf::Mouse::Wheel wheel , int deltascr);
		void processBall();
		void update();
		void process();
		void render();
	private:
		sf::RenderWindow window ;
		std::string title;
		unsigned int width;
		unsigned int height;
		std::vector<Ball> balls;
		bool isKeyPressed = false;
		bool isMouseClick = false;
};


#endif // !GAME_H



