#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

char randChar() {
	return (rand() % ('z' - 'a')) + 'a';
}

class Scope {
	private:
		unordered_set<string> variableNames;
		unordered_map<string, unordered_set<string>> types;

	public:
		string newVariable(string type);
		string newVariable(string type, string name);
		string getVariable(string type);
};

string Scope::newVariable(string type) {
	string var;
	var += randChar();

	while (variableNames.count(var))
		var += randChar();
	variableNames.insert(var);
	types[type].insert(var);
	return var;
}

string Scope::getVariable(string type) {
	if (types[type].empty())
		throw runtime_error("Scope has no variables of type " + type);

	int random = rand() % types[type].size();
	for (string var : types[type]) {
		if (random-- == 0)
			return var;
	}
	return "";
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
	cout << scope.newVariable("double") << '\n';
	cout << scope.newVariable("double") << '\n';
	cout << scope.getVariable("double") << '\n';
}
