#include <stdexcept>

#include "VarStack.h"
#include "Random.h"
#include "Scope.h"

using namespace std;


char randChar() {
	return g_randGen.drawNumber('a', 'z');
}

bool VarStack::doesVarExist(string name) {
	unsigned numScopeVars = currScope->getVarCount();
	if (names.size() < numScopeVars) {
		throw runtime_error("More scope variables than contained in VarStack somehow?!");
	}
	if (names.size()) {
		for (int i = names.size() - 1; i >= (int)(names.size() - numScopeVars); i--) {
			if (names[i] == name) {
				return true;
			}
		}
	}
	return false;
}

void VarStack::addVar(SupportedType type, string name) {
	// names.insert(name);
	names.push_back(name);
	types[type].push_back(name);
	currScope->incVarCount(type);
}

string VarStack::newVar(SupportedType type) {
	string name = g_varNameGen.getRandVarName();
	while (doesVarExist(name)) {
		string newWord;
		do {
			newWord = g_varNameGen.getRandVarName();
		} while (name.find(newWord) != string::npos);
		name += "_" + newWord;
	}

	addVar(type, name);
	return name;
}

string VarStack::newVar(SupportedType type, string name) {
	// add a number to the end of the proposed name
	int counter = 1;
	string newName = name;
	while (doesVarExist(name))
		newName = name + to_string(counter++);
	addVar(type, newName);
	return newName;
}

string VarStack::getVar(SupportedType type) {
	if (types[type].empty())
		throw runtime_error("VarStack has no variables of type " + type);

	int random = g_randGen.drawNumber(0, types[type].size() - 1);
	return types[type][random];
}

unsigned VarStack::getVarCount(SupportedType type) {
	return types[type].size();
}

void VarStack::setScope(Scope *newScope) {
	currScope = newScope;
}

bool VarStack::popVars() {
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