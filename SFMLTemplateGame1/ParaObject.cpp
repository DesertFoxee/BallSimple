#include "ParaObject.h"



ParaObject::ParaObject() {
	this->vec = Vector2D(0, 0);
	this->loc = Vector2D(0, 0);
	this->acc = Vector2D(0, 0);
	mass = 10;
}

ParaObject::ParaObject(Vector2D loc, float mass, Vector2D vec, Vector2D acc) {
	this->loc = loc;
	this->vec = vec;
	this->acc = acc;
	this->mass = mass;

}


ParaObject::~ParaObject() {
}
