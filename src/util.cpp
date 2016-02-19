#include <iostream>
#include "util.h"

unsigned g_currentTabCount = 0;

void coutLine(const string lineStr) {
	for (unsigned i = 0; i < g_currentTabCount; i++) {
		cout << '\t';
	}
	cout << lineStr << '\n';
}
