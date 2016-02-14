#include <string>
#include <cstdlib>
#include "Scope.h"
using namespace std;

char randChar() {
	return (rand() % ('z' - 'a')) + 'a';
}

void Scope::addVar(string type, string name) {
	names.insert(name);
	types[type].push_back(name);
}

string Scope::newVar(string type) {
	string name;
	name += randChar();

	while (names.count(name))
		name += randChar();

	addVar(type, name);
	return name;
}

string Scope::newVar(string type, string name) {
	// add a number to the end of the proposed name
	int counter = 1;
	string newName = name;
	while (names.count(newName))
		newName = name + to_string(counter++);
	addVar(type, newName);
	return newName;
}

string Scope::getVar(string type) {
	if (types[type].empty())
		throw runtime_error("Scope has no variables of type " + type);

	int random = rand() % types[type].size();
	return types[type][random];
}
