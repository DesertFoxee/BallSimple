#include "Convert.h"


float Convert::RadiusToDegree(float Rad) {
	return (Rad * 180) / float(PI);
}


float Convert::DegreeToRadius(float Deg) {
	return (Deg*float(PI)) / 180;
}

