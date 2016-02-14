#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

char randChar() {
	return (rand() % ('z' - 'a')) + 'a';
}

class Scope {
	private:
		unordered_set<string> names;
		unordered_map<string, vector<string>> types;

		void addVariable(string type, string name);

	public:
		string newVariable(string type);
		string newVariable(string type, string name);
		string getVariable(string type);
};

void Scope::addVariable(string type, string name) {
	names.insert(name);
	types[type].push_back(name);
}

string Scope::newVariable(string type) {
	string name;
	name += randChar();

	while (names.count(name))
		name += randChar();

	addVariable(type, name);
	return name;
}

string Scope::newVariable(string type, string name) {
	if (!names.count(name)) {
		addVariable(type, name);
		return name;
	}
	// add a number to the end of the proposed name
	int counter = 1;
	string newName = name + to_string(counter++);
	while (names.count(newName))
		newName = name + to_string(counter++);
	addVariable(type, newName);
	return newName;
}

string Scope::getVariable(string type) {
	if (types[type].empty())
		throw runtime_error("Scope has no variables of type " + type);

	int random = rand() % types[type].size();
	return types[type][random];
}

int main() {
	srand((int)time(0));
	Scope scope;
	char in;
	while(1) {
		cout << scope.newVariable("int") << '\n';
		cout << scope.getVariable("int") << '\n';
		in = getchar();
		if (in == 'q')
			break;
	}
	cout << '\n';
	cout << scope.newVariable("int", "test") << '\n';
	cout << scope.newVariable("int", "test") << '\n';
	cout << scope.newVariable("int", "test") << '\n';
	cout << scope.newVariable("int", "test") << '\n';
}
