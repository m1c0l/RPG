#include <stdlib.h>

#include "VarStack.h"
#include "Random.h"

using namespace std;

Random randGen;

char randChar() {
	return randGen.drawNumber('a', 'z');
}

void VarStack::addVar(SupportedType type, string name) {
	names.insert(name);
	types[type].push_back(name);
}

string VarStack::newVar(SupportedType type) {
	string name;
	name += randChar();

	while (names.count(name))
		name += randChar();

	addVar(type, name);
	return name;
}

string VarStack::newVar(SupportedType type, string name) {
	// add a number to the end of the proposed name
	int counter = 1;
	string newName = name;
	while (names.count(newName))
		newName = name + to_string(counter++);
	addVar(type, newName);
	return newName;
}

string VarStack::getVar(SupportedType type) {
	if (types[type].empty())
		throw runtime_error("VarStack has no variables of type " + type);

	int random = randGen.drawNumber(0, types[type].size() - 1);
	return types[type][random];
}

bool VarStack::popVars(unsigned numPop) {
	if (names.size() < numPop) {
		return false;
	}

	// TODO
	return true;
}