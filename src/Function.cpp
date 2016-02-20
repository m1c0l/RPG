#include <limits.h>

#include "Function.h"
#include "Random.h"
#include "util.h"
#include "Type.h"


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
	localScopes.push_back(Scope());
	Scope *scope = &localScopes.back();
	// random_t tmpRand = g_randGen.drawNumber(LLONG_MIN, LLONG_MAX);
	coutLine(g_typeStrings[LLONG] + " " + localVars.newVar(LLONG) + " = "
			+ getRandValue(LLONG) + ";");
	scope->incVarCount();
	// tmpRand = g_randGen.drawNumber(CHAR_MIN, CHAR_MAX);
	coutLine(g_typeStrings[CHAR] + " " + localVars.newVar(CHAR) + " = "
			+ getRandValue(CHAR) + ";");
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
