#ifndef BALL_H
#define BALL_H

#include "Object.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "ExternalForce.h"
#include "Asset.h"


#define STATE_COUNT 4
enum StateBall {
	pull_force,
	move_ball,
};


class Ball : public Object {
public:
	Ball();
	Ball(ParaObject para);

	~Ball();
	void init(Vector2D loc = Vector2D(100, 100), float mass = 10, float radius = 20);
	void update();
	void applyForce(Vector2D force);
	void applyForceDecrease(Vector2D& force);
	void checkEdge();
	void render(sf::RenderWindow& window);
	void resetBallPull();
	void process(sf::RenderWindow& window);
private:
	sf::CircleShape ball;
	sf::Vertex thrust[2];
	bool state[STATE_COUNT];
	Vector2D f_pull_force;
	Vector2D a_pull_force;
	Vector2D v_pull_force;
	bool check;
	float mag;
};

#endif // !BALL_H



