#ifndef RANDOM_H
#define RANDOM_H

#include <random>

using namespace std;

/*
 * Use long long for random number generator as this is the biggest data type;
 * this just means we can't generate unsigned long longs without some casting,
 * though it should work since signed to unsigned conversion is defined.
 */
typedef long long random_t;
/*
 * Random distribution objects are lightweight, so we simply construct a new
 * distribution object every time we need a random number
 */
class Random {
public:
	Random() = default;
	Random(mt19937::result_type seed) : eng(seed) {}
	random_t drawNumber(random_t min, random_t max);

private:        
    mt19937_64 eng{random_device{}()};
};

extern Random g_randGen;

#endif

