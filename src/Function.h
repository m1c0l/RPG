#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <string>

#include "Scope.h"
#include "VarStack.h"
#include "util.h"

unsigned g_currentTabCount = 0;

using namespace std;

class Function {
private:
	string name, retType;
	vector<Scope> localScopes;
	VarStack localVars;
	
	void printBodyHeader();
	void printBodyFooter();

	/* Clean up current scope, e.g., pop its variables off stack */
	bool cleanupCurrScope();
	// TODO: add vector of parameters
public:
	Function(string returnType, string functionName);

	void printPrototype();
	void printBody();
};

#endif