#include "Scope.h"

using namespace std;

Scope::Scope() {
	numVars = 0;
}

void Scope::incVarCount() {
	numVars++;
}

unsigned Scope::getVarCount() {
	return numVars;
}