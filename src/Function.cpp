#include <limits.h>

#include "Function.h"
#include "Random.h"
#include "util.h"
#include "Type.h"
#include "ExprGen.h"


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
	g_exprGen.setVarStack(&localVars);
	g_currentTabCount++;
	coutLine("cout << \"Hello world!\" << '\\n';");
	localScopes.push_back(Scope());
	localVars.setScope(&localScopes.back());
	for (unsigned i = 0; i < 10; i++) {
		SupportedType randType = getRandType();
		coutLine(g_typeStrings[randType] + " " + localVars.newVar(randType) + " = "
			+ getRandValue(randType) + ";");
	}
	for (unsigned i = 0; i < 20; i++) {
		SupportedType randType = getRandType();
		string arithmicExprStr = g_exprGen.genArithmeticExpr(randType);
		coutLine(g_typeStrings[randType] + " " + localVars.newVar(randType) + " = "
			+ arithmicExprStr + ";");
	}
	coutLine("return 0;");
	g_currentTabCount--;
	printBodyFooter();
	cleanupCurrScope();
}

bool Function::cleanupCurrScope() {
	bool ret = localVars.popVars();
	localScopes.pop_back();
	if (localScopes.size()) {
		localVars.setScope(&localScopes.back());
	}
	return ret;
}
