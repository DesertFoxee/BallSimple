#ifndef EXTERNALFORCE_H
#define EXTERNALFORCE_H

#include "Vector2D.h"


#define GRAVITATION Vector2D(0 , 0.1f)
#define ENVIR_CONST 0.01f
#define WIND Vector2D(0.005f , 0)

/*

Force air or fluid Resistance

 F = (-1/2) *p * v^2 AC v(v)

*/

class Resistance {
public :
	static Vector2D getEnvir(Vector2D normal_v , float mag_v , float envir_c);
	static Vector2D getFric(Vector2D normal_v ,float mass , float angle , float fric_c);
};



#endif // !EXTERNALFORCE_H
