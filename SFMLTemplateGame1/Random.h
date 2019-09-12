#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random {

	public:

		static float randomFloatUniform(float min, float max);

		static int randomIntUniform(int min, int max);

		template <typename T>
		static T randomNormal(T min, T max);
};


#endif // !RANDOM_H



