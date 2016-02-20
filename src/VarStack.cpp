#include <stdlib.h>

#include "VarStack.h"
#include "Random.h"
#include "Scope.h"

using namespace std;


char randChar() {
	return g_randGen.drawNumber('a', 'z');
}

bool VarStack::doesVarExist(Scope *currScope, string name) {
	unsigned numScopeVars = currScope->getVarCount();
	if (names.size() < numScopeVars) {
		throw runtime_error("More scope variables than contained in VarStack somehow?!");
	}
	for (unsigned i = names.size() - 1; i > names.size() - 1 - numScopeVars; i--) {
		if (names[i] == name) {
			return true;
		}
	}
	return false;
}

void VarStack::addVar(Scope *currScope, SupportedType type, string name) {
	// names.insert(name);
	names.push_back(name);
	types[type].push_back(name);
	currScope->incVarCount(type);
}

string VarStack::newVar(Scope *currScope, SupportedType type) {
	string name;
	name += randChar();

	// while (names.count(name))
	// 	name += randChar();
	while (doesVarExist(currScope, name))
		name += randChar();

	addVar(currScope, type, name);
	return name;
}

string VarStack::newVar(Scope *currScope, SupportedType type, string name) {
	// add a number to the end of the proposed name
	int counter = 1;
	string newName = name;
	// while (names.count(newName))
	// 	newName = name + to_string(counter++);
	while (doesVarExist(currScope, name))
		newName = name + to_string(counter++);
	addVar(currScope, type, newName);
	return newName;
}

string VarStack::getVar(SupportedType type) {
	if (types[type].empty())
		throw runtime_error("VarStack has no variables of type " + type);

	int random = g_randGen.drawNumber(0, types[type].size() - 1);
	return types[type][random];
}

bool VarStack::popVars(Scope *currScope) {
	unsigned numScopeVars = currScope->getVarCount();
	if (names.size() < numScopeVars) {
		throw runtime_error("More scope variables than contained in VarStack somehow?!");
	}
	for (unsigned i = 0; i < numScopeVars; i++) {
		names.pop_back();
	}
	auto varTypeCounts = currScope->getVarTypeCounts();
	for (auto it : varTypeCounts) {
		SupportedType type = (SupportedType)it.first;
		unsigned numTypeVars = it.second;
		if (types[type].size() < numTypeVars) {
			throw runtime_error("More scope variables of a certain type than contained in VarStack somehow?!");
		}
		for (unsigned i = 0; i < numTypeVars; i++) {
			types[type].pop_back();
		}
	}
	return true;
}