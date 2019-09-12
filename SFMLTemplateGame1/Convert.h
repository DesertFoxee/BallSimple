#ifndef CONVERT_H
#define CONVERT_H

#define PI  3.1415926535

#include <iostream>


class Convert {
public:
	static float RadiusToDegree(float Rad);
	static float DegreeToRadius(float Deg);

	template<typename Enumeration>
	static auto as_integer(Enumeration const value)
		-> typename std::underlying_type<Enumeration>::type {
		return static_cast<typename std::underlying_type<Enumeration>::type>(value);
	}
};




#endif // !CONVERT_H


