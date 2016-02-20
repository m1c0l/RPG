#include "Random.h"

random_t Random::drawNumber(random_t min, random_t max) {
	return uniform_int_distribution<random_t>{min, max}(eng);
}

Random g_randGen;