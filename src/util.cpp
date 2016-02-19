#include <iostream>
#include "util.h"



void coutLine(const string lineStr) {
	for (unsigned i = 0; i < g_currentTabCount; i++) {
		cout << '\t';
	}
	cout << lineStr << '\n';
}
