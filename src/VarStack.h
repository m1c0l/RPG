#ifndef VARSTACK_H
#define VARSTACK_H

// #include <unordered_set>
#include <unordered_map>
// #include <map>
#include <vector>
#include <string>

#include "Type.h"

using namespace std;

class Scope;

class VarStack {
	private:
		vector<string> names;
		// unordered_map won't take enums as keys so use an int, same thing
		unordered_map<int, vector<string>> types;

		/* Returns whether a variable name exists in current scope */
		bool doesVarExist(Scope *currScope, string name);

		void addVar(Scope *currScope, SupportedType type, string name);


	public:
		/* Returns the name of a new variable */
		string newVar(Scope *currScope, SupportedType type);

		/* Return a new variable name, and try to name the variable the
		 * given name */
		string newVar(Scope *currScope, SupportedType type, string name);

		/* Return a random variable name of the given type */
		string getVar(SupportedType type);

		/* Pop a number of variables from the stack
		 * when we're finished with a scope  */
		bool popVars(Scope *currScope);
};
#endif
