#include <limits.h>

#include "Function.h"
#include "Random.h"


Function::Function(string returnType, string functionName) {
	retType = returnType;
	name = functionName;
}


void Function::printBodyHeader() {
	coutLine(retType + " " + name + "() {");
	return;
}



void Function::printBodyFooter() {
	coutLine("}");
	return;
}

void Function::printPrototype() {
	// TODO
	return;
}

void Function::printBody() {
	// TODO: cleanup
	printBodyHeader();
	g_currentTabCount++;
	coutLine("cout << \"Hello world!\" << '\\n';");
	Random randGen;
	localScopes.push_back(Scope());
	Scope *scope = &localScopes.back();
	random_t tmpRand = randGen.drawNumber(LLONG_MIN, LLONG_MAX);
	coutLine("long long " + localVars.newVar("long long") + " = "
			+ to_string(tmpRand) + ";");
	scope->incVarCount();
	tmpRand = randGen.drawNumber(CHAR_MIN, CHAR_MAX);
	coutLine("char " + localVars.newVar("char") + " = "
			+ to_string(tmpRand) + ";");
	coutLine("return 0;");
	scope->incVarCount();
	g_currentTabCount--;
	printBodyFooter();
	cleanupCurrScope();
}

bool Function::cleanupCurrScope() {
	Scope currScope = localScopes.back();
	unsigned numScopeVars = currScope.getVarCount();
	localScopes.pop_back();
	return localVars.popVars(numScopeVars);
}