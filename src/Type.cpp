#include "Type.h"
#include "Random.h"

using namespace std;

SupportedType getRandType() {
	return (SupportedType)g_randGen.drawNumber(0, NUM_SUPPORTED_TYPES - 1);
}

string getRandValue(SupportedType type) {
	string randString;
	random_t randLong = g_randGen.drawNumber(g_typeMinValues[type], g_typeMaxValues[type]);
	return to_string(randLong);
}
