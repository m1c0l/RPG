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
	coutLine(g_typeStrings[LLONG] + " " + localVars.newVar(scope, LLONG) + " = "
			+ getRandValue(LLONG) + ";");
	coutLine(g_typeStrings[CHAR] + " " + localVars.newVar(scope, CHAR) + " = "
			+ getRandValue(CHAR) + ";");
	coutLine("return 0;");
	g_currentTabCount--;
	printBodyFooter();
	cleanupCurrScope();
}

bool Function::cleanupCurrScope() {
	Scope *currScope = &localScopes.back();
	bool ret = localVars.popVars(currScope);
	localScopes.pop_back();
	return ret;
}
