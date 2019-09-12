#ifndef MOUSE_H
#define MOUSE_H

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

/*

	-Get number Mouse in enum class using Complie = current line - begin line - space

*/


constexpr auto BEGIN_MOUSE = __LINE__;
namespace MOUSE {
	enum class MOUSE_B {
		RIGHT,
		LEFT,
		MIDDLE,
		WHEEL,
	};
	constexpr static auto COUNT_MOUSE_B = __LINE__ - BEGIN_MOUSE - 4;

	enum class MOUSE_E {
	};
};


class Mouse {
public:
	~Mouse();

	static Mouse& getIntance() {
		if(instance == nullptr) {
			instance = std::unique_ptr<Mouse>(new Mouse());
		}
		return *instance;
	}
	

	sf::Vector2i getMouseScreen();
	sf::Vector2i getMouseWindow(const sf::Window& window);


	void setMouseScreen(const sf::Vector2i& pos );
	void setMouseWindow(const sf::Window& window ,const sf::Vector2i& pos);


	
	void show();
	void showMousePos();

	// procee wheel moose ;

	void zoomin() { mouse_zoom++; };
	void zoomout() { (mouse_zoom > 0) ? mouse_zoom-- : mouse_zoom; };
	int getZoom() { return Mouse::mouse_zoom; };


	// process mouse real ;

	void reset_real();
	void setStateMouse(MOUSE::MOUSE_B mousekey, bool state);
	bool getStateMouse(MOUSE::MOUSE_B mousekey);

	// process unique_mouse 

	void reset_unique();
	bool getStateMouseUniq(MOUSE::MOUSE_B mousekey);
	void setStateMouseUniq(MOUSE::MOUSE_B mousekey , bool state);


private:
	Mouse();
	static sf::Vector2i pos;
	std::vector<bool> mouse;
	std::vector<bool> mouse_uniq;
	static int mouse_zoom;

	static std::unique_ptr<Mouse> instance;
};


#endif // !MOUSE_H


