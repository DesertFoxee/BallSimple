#ifndef OBJECT_H
#define OBJECT_H

#include "Action.h"
#include "ParaObject.h"

class Object :public Action {
public:
	Object();
	Object(ParaObject para);
	virtual ~Object();
	virtual void update() {};
	virtual void applyForce() {};
	virtual void render(sf::RenderWindow & window) {};
	virtual void process(){};
protected:
	ParaObject obj;
};


#endif // !OBJECT_H



