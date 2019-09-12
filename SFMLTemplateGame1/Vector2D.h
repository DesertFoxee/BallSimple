#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "Random.h"

#include <SFML/Graphics.hpp>


class Vector2D {


	public:
		Vector2D();
	

		explicit Vector2D(const float& x,const float& y);

		Vector2D(const Vector2D& v2D);
		Vector2D(const sf::Vector2f& v2F);

		~Vector2D();
	
		Vector2D & operator=(const Vector2D& v);

		Vector2D&  operator+=(const Vector2D& v);
		Vector2D&  operator-=(const Vector2D& v);
		Vector2D&  operator*=(const float& factor);
		Vector2D&  operator/=(const float& factor);


		Vector2D  operator+(const Vector2D& v);
		Vector2D  operator-(const Vector2D& v);
		Vector2D  operator*(const float& factor);
		Vector2D  operator/(const float& factor);


		bool operator==(const Vector2D& v);
		bool operator!=(const Vector2D& v);
		bool operator!=(const sf::Vector2f& v);
		bool operator==(const sf::Vector2f& v);

		sf::Vector2f toVec2f();


		float mag();
		float mag(const Vector2D &v);
		Vector2D normalize();
		float angle();
		void random(float min, float max);


		void reset();


	public:
		float x;
		float y;

};

#endif // !VECTOR2D_H




