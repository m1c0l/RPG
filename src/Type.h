#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <unordered_map>

#include <limits.h>

using namespace std;

enum SupportedType { CHAR = 0, INT, LONG, LLONG };
/* As long as the orders match, we can easily access an enum value's corresponding string */
const string g_typeStrings[] = {"char", "int", "long", "long long" };

const long long g_typeMinValues[] = { CHAR_MIN, INT_MIN, LONG_MIN, LLONG_MIN };
const long long g_typeMaxValues[] = { CHAR_MAX, INT_MAX, LONG_MAX, LLONG_MAX };

#define NUM_SUPPORTED_TYPES 4

SupportedType getRandType();

string getRandValue(SupportedType type);



#endif
