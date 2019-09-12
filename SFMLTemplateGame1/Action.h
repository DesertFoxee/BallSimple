#ifndef ACTION_H
#define ACTION_H

#include <SFML/Graphics.hpp>

class Action {
public:
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void process() = 0;
};


#endif // !ACTION_H




