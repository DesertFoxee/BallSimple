#include "ExternalForce.h"


Vector2D Resistance::getEnvir(Vector2D normal_v, float mag_v, float envir_c) {
	return normal_v * mag_v*mag_v * envir_c *(-1);
}

Vector2D Resistance::getFric(Vector2D normal_v, float mass, float angle, float fric_c) {
	return normal_v * mass  * cosf(angle) * fric_c *(-1);
}
