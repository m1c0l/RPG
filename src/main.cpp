#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <limits.h>

#include "Random.h"
#include "VarNameGen.h"
#include "Scope.h"
#include "Function.h"
#include "util.h"

using namespace std;


void generateHeader() {
	vector<string> stdLibraries = {"stdio.h", "iostream", "string", "stdlib.h", "math.h"};
	for (unsigned i = 0; i < stdLibraries.size(); i++) {
		coutLine("#include <" + stdLibraries[i] + ">");
	}
	coutLine();
	coutLine("using namespace std;");
	coutLine();
}

void generateMainFunction() {
	Function mainFunction = Function("int", "main");
	mainFunction.printBody();
}

int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "Need a filename!\n";
		return 1;
	}
	char *filename = argv[1];
	if (!freopen(filename, "w", stdout)) {
		cerr << filename << " could not be opened for writing\n";
		return 1;
	}
	generateHeader();
	generateMainFunction();
	fclose(stdout);
	return 0;
}
