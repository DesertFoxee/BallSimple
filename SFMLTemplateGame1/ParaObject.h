#ifndef PARAOBJECT_H
#define PARAOBJECT_H

#include "Vector2D.h"

class ParaObject {

public:
	ParaObject();
	ParaObject(Vector2D loc, float mass = 10, Vector2D vec = Vector2D(0, 0),
		Vector2D acc = Vector2D(0, 0));
	~ParaObject();
public:
	Vector2D loc;
	Vector2D vec;
	Vector2D acc;
	float mass;
};



#endif // !PARAOBJECT_H




