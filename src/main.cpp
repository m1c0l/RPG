#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

/*
 * Random distribution objects are lightweight, so we simply construct a new
 * distribution object every time we need a random number
 */
class Random {
public:
    Random() = default;
    Random(mt19937::result_type seed) : eng(seed) {}
    int drawNumber(int min, int max);

private:        
    mt19937 eng{random_device{}()};
};

int Random::drawNumber(int min, int max) {
    return uniform_int_distribution<int>{min, max}(eng);
}

/*
 * A counter of how many tabs to output at the start of the line;
 * increment it whenever we reach a new scope
 */
unsigned g_currentTabCount = 0;

void coutLine(const string lineStr = "") {
	for (unsigned i = 0; i < g_currentTabCount; i++) {
		cout << '\t';
	}
	cout << lineStr << '\n';
}

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
	coutLine("int main() {");
	g_currentTabCount++;
	coutLine("cout << \"Hello world!\" << '\\n';");
	coutLine("return 0;");
	g_currentTabCount--;
	coutLine("}");
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
