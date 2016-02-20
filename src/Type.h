#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <unordered_map>

using namespace std;

enum SupportedType { CHAR = 0, INT, LONG, LLONG };
/* As long as the orders match, we can easily access an enum value's corresponding string */
const string g_typeStrings[] = {"char", "int", "long", "long long" };
// const unordered_map<int, string> g_supportedTypeStrings;
// g_supportedTypeStrings[CHAR] = "char";

string getRandValue(SupportedType type);

#endif