#ifndef UTIL_H
#define UTIL_H

#include <iostream>

using namespace std;
/*
 * A counter of how many tabs to output at the start of the line;
 * increment it whenever we reach a new scope
 */
extern unsigned g_currentTabCount;

void coutLine(const string lineStr = "");

#endif