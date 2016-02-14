#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <limits.h>

using namespace std;

/*
 * Use long long for random number generator as this is the biggest data type;
 * this just means we can't generate unsigned long longs without some casting,
 * though it should work since signed to unsigned conversion is defined.
 */
typedef long long random_t;
/*
 * Random distribution objects are lightweight, so we simply construct a new
 * distribution object every time we need a random number
 */
class Random {
public:
	Random() = default;
	Random(mt19937::result_type seed) : eng(seed) {}
	random_t drawNumber(random_t min, random_t max);

private:        
    mt19937_64 eng{random_device{}()};
};

random_t Random::drawNumber(random_t min, random_t max) {
	return uniform_int_distribution<random_t>{min, max}(eng);
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
	Random randGen;
	random_t tmpRand = randGen.drawNumber(LLONG_MIN, LLONG_MAX);
	coutLine("long long ll = " + to_string(tmpRand) + ";");
	tmpRand = randGen.drawNumber(CHAR_MIN, CHAR_MAX);
	coutLine("char c = " + to_string(tmpRand) + ";");
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
