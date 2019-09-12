
#ifndef MOUSEMANAGER_H
#define MOUSEMANAGER_H

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

/*
	-Get number Mouse in enum class using Complie = current line - begin line - space
*/
#define MIN_ZOOM 1

#define MAX_ZOOM 20


constexpr auto BEGIN_MOUSE = __LINE__;
namespace MOUSE {
	enum class MOUSE_B
	{
		RIGHT,
		LEFT,
		MIDDLE,
		WHEEL,
	};
	constexpr static auto COUNT_MOUSE_B = __LINE__ - BEGIN_MOUSE - 4;

	enum class MOUSE_E
	{
	};
};


class Mouse
{
public:
	~Mouse();

	static Mouse& getIntance()
	{
		if (instance == nullptr) {
			instance = std::unique_ptr<Mouse>(new Mouse());
		}
		return *instance;
	}


	sf::Vector2i getMouseScreen();
	sf::Vector2i getMouseWindow(const sf::Window& window);


	void setMouseScreen(const sf::Vector2i& pos);
	void setMouseWindow(const sf::Window& window, const sf::Vector2i& pos);


	void show();
	void showMousePos();

	// procee wheel moose ;
	void Zoom(int delta = 1);
	int getZoom() { return Mouse::mouse_zoom; };
	void resetZoom() { mouse_zoom = MIN_ZOOM; }


	// process mouse real ;

	void resetMouseReal();
	void setStateMouse(MOUSE::MOUSE_B mousekey, bool state);
	bool getStateMouse(MOUSE::MOUSE_B mousekey);

	// process unique_mouse 

	void resetMouseUniq();
	bool getStateMouseUniq(MOUSE::MOUSE_B mousekey);
	void setStateMouseUniq(MOUSE::MOUSE_B mousekey, bool state);
private:
	Mouse();
	static sf::Vector2i pos;
	std::vector<bool> mouse;
	std::vector<bool> mouse_uniq;
	static int mouse_zoom;

	static std::unique_ptr<Mouse> instance;
};


#endif // !MOUSEMANAGER_H


