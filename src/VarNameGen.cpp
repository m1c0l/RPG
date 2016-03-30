#include "VarNameGen.h"
#include "Random.h"

#include <stdio.h>
#include <iostream>
#include <stdexcept>

VarNameGen::VarNameGen() {
	if (freopen("src/VarWords.txt", "r", stdin) == NULL) {
		throw runtime_error("Couldn't open VarWords.txt for variable words!");
	}
	string word;
	while (cin >> word) {
		varWords.push_back(word);
	}
	fclose(stdin);
}

string VarNameGen::getRandVarName() {
	unsigned wordIndex = g_randGen.drawNumber(0, varWords.size() - 1);
	return varWords[wordIndex];
}

VarNameGen g_varNameGen;