#include "Scope.h"

using namespace std;

Scope::Scope() {
	numVars = 0;
}

void Scope::incVarCount(SupportedType type) {
	numVars++;
	if (!varTypeCounts.count(type)) {
		varTypeCounts[type] = 1;
	}
	else {
		varTypeCounts[type]++;
	}
	return;
}

unsigned Scope::getVarCount() {
	return numVars;
}

const unordered_map<int, unsigned> Scope::getVarTypeCounts() {
	return varTypeCounts;
}