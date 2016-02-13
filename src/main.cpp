#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

/*
Random distribution objects are lightweight, so we simply construct a new
distribution object every time we need a random number
*/
class Random {
public:
    Random() = default;
    Random(std::mt19937::result_type seed) : eng(seed) {}
    int DrawNumber(int min, int max);

private:        
    std::mt19937 eng{std::random_device{}()};
};

int Random::DrawNumber(int min, int max) {
    return std::uniform_int_distribution<int>{min, max}(eng);
}

void generateHeader() {
	vector<string> stdLibraries = {"stdio.h", "iostream", "string", "stdlib.h", "math.h"};
	for (unsigned i = 0; i < stdLibraries.size(); i++) {
		cout <<  "#include <" << stdLibraries[i] << ">\n";	
	}
	cout << "\n";
	cout << "using namespace std;\n\n";
}

void generateMainFunction() {
	cout << "int main() {\n";
	// use endl here instead of \n to make the cout more clear	
	cout << "\tcout << \"Hello world!\" << endl;" << endl;
	cout << "\treturn 0;\n";
	cout << "}\n";
}

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Need a filename!\n";
		return 1;
	}
	char *filename = argv[1];
	if (!freopen(filename, "w", stdout)) {
		cout << filename << " could not be opened for writing\n";
		return 1;
	}
	generateHeader();
	generateMainFunction();
	fclose(stdout);
	return 0;
}
