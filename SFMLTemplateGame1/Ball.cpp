#include "Ball.h"



Ball::Ball() :Object() {

}

Ball::Ball(ParaObject para) : Object(para) {
	obj.loc = Vector2D(100, 100);
	this->ball.setRadius(50);
}


Ball::~Ball() {
}

void Ball::init(Vector2D loc, float mass, float radius) {
	obj.loc = loc;
	obj.vec.reset();
	obj.acc.reset();
	obj.mass = mass;
	// setup ball 

	this->ball.setRadius(radius);
	this->ball.setFillColor(sf::Color(100, 100, 120));

	for(auto i = 0; i < STATE_COUNT; i++) {
		state[i] = false;
	}
	check = false;

	f_pull_force = Vector2D(0, 0);
	
}

void Ball::update() {

	//apply out of force 
	this->applyForce(GRAVITATION);
	this->applyForce(
		Resistance::getEnvir(obj.vec.normalize(), obj.vec.mag(), ENVIR_CONST));
	this->applyForce(WIND);
	if(f_pull_force != Vector2D( 0, 0))
		this->applyForceDecrease(f_pull_force);

	// update state 
	obj.vec += obj.acc;
	obj.loc += obj.vec;
	

	if(obj.vec.mag() < 0.2f) obj.vec/=1.002f;

	ball.setPosition(obj.loc.toVec2f());
	obj.acc.reset();
}

void Ball::applyForce(Vector2D force) {
	obj.acc += (obj.mass != 0) ? (force / obj.mass) : (Vector2D(0, 0));
}

void Ball::applyForceDecrease(Vector2D& force) {
	obj.acc += (obj.mass != 0) ? (force / obj.mass) : (Vector2D(0, 0));
	force /=(obj.mass);
	if(force.mag() < 7.0f)
		force = Vector2D(0, 0);
}

void Ball::checkEdge() {

	if(obj.loc.x + ball.getRadius() > SCREEN_WIDTH) {
		obj.loc.x = SCREEN_WIDTH - ball.getRadius();
		obj.vec.x *= -1;
	}
	else if(obj.loc.x < 0) {
		obj.vec.x *= -1;
		obj.loc.x = 0;
	}
	if(obj.loc.y + ball.getRadius() > SCREEN_HEIGHT) {
		obj.loc.y = SCREEN_HEIGHT - ball.getRadius();
		obj.vec.y *= -1;
	}
	else if(obj.loc.y < 0) {
		obj.vec.y *= -1;
		obj.loc.y = 0;
	}

}

void Ball::render(sf::RenderWindow & window) {
	window.draw(ball);
	window.draw(thrust , 2 ,sf::Lines);
}

void Ball::resetBallPull() {
	this->thrust[0].position = sf::Vector2f(0, 0);
	this->thrust[1].position = sf::Vector2f(0, 0);
	a_pull_force = Vector2D(0, 0);
	v_pull_force = Vector2D(0, 0);
	state[StateBall::pull_force] = false;
	check = false;
}

void Ball::process(sf::RenderWindow& window) {
	this->checkEdge();

	// using space assign force
	if(Keyboard::getIntance().getStateKeyBoard(KEYBOARD::KEY_B::CONTROL)
		&& Mouse::getIntance().getStateMouse(MOUSE::MOUSE_B::LEFT)) {
		auto mouse_pos = Mouse::getIntance().getMouseWindow(window);
		auto translated_pos = window.mapPixelToCoords(mouse_pos);
		auto contain = ball.getGlobalBounds();
		if(state[StateBall::pull_force] == false && contain.contains(translated_pos)) {
			this->thrust[0].position = ball.getPosition() + sf::Vector2f(contain.width / 2, contain.height / 2);
			this->thrust[1].position = ball.getPosition() + sf::Vector2f(contain.width / 2, contain.height / 2);
			state[StateBall::pull_force] = true;
			check = true;
		}
		else if(state[StateBall::pull_force]) {
			this->thrust[0].position = ball.getPosition() + sf::Vector2f(contain.width / 2, contain.height / 2);
			this->thrust[1].position = sf::Vector2f(float(translated_pos.x), float(translated_pos.y));
			this->a_pull_force = Vector2D(thrust[1].position - thrust[0].position).normalize() / 50;
		}
	}
	// catch event click on ball and keep control 
	else if(Mouse::getIntance().getStateMouse(MOUSE::MOUSE_B::LEFT)) {
		auto mouse_pos = Mouse::getIntance().getMouseWindow(window); // Mouse position relative to the window
		auto translated_pos = window.mapPixelToCoords(mouse_pos);
		auto contain = ball.getGlobalBounds();
		if(contain.contains(translated_pos)) {
			state[StateBall::move_ball] = true;
			obj.vec.reset();
			obj.loc = translated_pos - sf::Vector2f(contain.width/2, contain.height/2);
		}
		else {
			state[StateBall::move_ball] = false;
		}
	}
	
	if(check ==true && state[StateBall::pull_force] 
		&& !Keyboard::getIntance().getStateKeyBoard(KEYBOARD::KEY_B::CONTROL)) {
		auto contain = ball.getGlobalBounds();
		
		v_pull_force += a_pull_force;
		thrust[0].position += v_pull_force.toVec2f();

		obj.loc = thrust[0].position - sf::Vector2f(contain.width / 2, contain.height / 2);

		Vector2D c = Vector2D(thrust[1].position - thrust[0].position);

		if(c.mag() < 7.f) {
			this->f_pull_force =  v_pull_force.normalize()* v_pull_force.mag()*v_pull_force.mag() * (obj.mass/2);
			this->resetBallPull();
		}
	}
	if(Keyboard::getIntance().getStateKeyBoard(KEYBOARD::KEY_B::SHIFT)) {
		f_pull_force.reset();
		obj.acc.reset();
		obj.vec.reset();
	}
	// collision ;

	

}
