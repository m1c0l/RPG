#include "Type.h"
#include "Random.h"

#include <limits.h>

using namespace std;

string getRandValue(SupportedType type) {
	string randString;
	random_t randLong;
	switch(type) {
	case CHAR:
		randLong = g_randGen.drawNumber(CHAR_MIN, CHAR_MAX);
		randString = to_string(randLong);
		break;
	case INT:
		randLong = g_randGen.drawNumber(INT_MIN, INT_MAX);
		randString = to_string(randLong);
		break;
	case LONG:
		randLong = g_randGen.drawNumber(LONG_MIN, LONG_MAX);
		randString = to_string(randLong);
		break;
	case LLONG:
		randLong = g_randGen.drawNumber(LLONG_MIN, LLONG_MAX);
		randString = to_string(randLong);
		break;
	}
	return randString;
}