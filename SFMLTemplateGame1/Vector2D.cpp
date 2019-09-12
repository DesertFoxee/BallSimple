#include "Vector2D.h"



Vector2D::Vector2D() {
	this->x = 0;
	this->y = 0;
}

Vector2D::Vector2D(const float& x, const float& y)
{
	this->x = x;
	this->y = y;
}


Vector2D::Vector2D(const Vector2D & v2D) {
	this->x = v2D.x;
	this->y = v2D.y;
}

Vector2D::Vector2D(const sf::Vector2f & v2F) {
	this->x = v2F.x;
	this->y = v2F.y;
}


Vector2D & Vector2D::operator*=(const float & factor) {
	this->x *= float(factor);
	this->y *= float(factor);
	return *this;
}

Vector2D & Vector2D::operator/=(const float& factor) {
	if(factor) {
		this->x /= factor;
		this->y /= factor;
	};
	return *this;
}


Vector2D::~Vector2D() {
	this->x = 0;
	this->y = 0;
}

Vector2D & Vector2D::operator=(const Vector2D & v) {
	this->x = v.x;
	this->y = v.y;
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D & v) {
	return Vector2D(this->x+v.x , this->y+v.y);
}

Vector2D Vector2D::operator-(const Vector2D & v) {
	return Vector2D(this->x - v.x, this->y - v.y);
}

Vector2D Vector2D::operator*(const float & factor) {
	return Vector2D(this->x *factor , this->y*factor);
}

Vector2D Vector2D::operator/(const float & factor) {
	if(factor) {
		return Vector2D(this->x /factor, this->y/factor);
	}
	return *this;
}

bool Vector2D::operator==(const Vector2D & v) {
	return (this->x == v.x)&&(this->y == v.y);
}

bool Vector2D::operator!=(const Vector2D & v) {
	return (this->x != v.x)||(this->y != v.y);
}

bool Vector2D::operator!=(const sf::Vector2f & v) {
	return (this->x != v.x) || (this->y != v.y);
}

bool Vector2D::operator==(const sf::Vector2f & v) {
	return (this->x == v.x) && (this->y == v.y);
}

sf::Vector2f Vector2D::toVec2f() {
	return sf::Vector2f(this->x, this->y);
}

Vector2D & Vector2D::operator+=(const Vector2D & v) {
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vector2D & Vector2D::operator-=(const Vector2D & v) {
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

float Vector2D::mag() {
	return std::sqrtf(this->x*this->x + this->y * this->y);
}

float Vector2D::mag(const Vector2D & v) {
	Vector2D temp = *this - v;
	return temp.mag();
}

Vector2D Vector2D::normalize() {
	float mag = this->mag();

	if(mag) {
		return Vector2D(this->x / mag, this->y / mag);
	}
	return Vector2D(0, 0);
}

void Vector2D::reset() {
	this->x = 0;
	this->y = 0;
}

float Vector2D::angle() {
	return atan2f(this->y, this->x);
}

void Vector2D::random(float min , float max) {
#ifdef RANDOM_H
	this->x = Random::randomFloatUniform(min, max);
	this->y = Random::randomFloatUniform(min, max);
#else
	this->x = 0; this->y = 0;
#endif // RANDOM_H

}
