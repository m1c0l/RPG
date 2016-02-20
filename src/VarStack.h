#ifndef VARSTACK_H
#define VARSTACK_H

#include <unordered_set>
#include <unordered_map>
// #include <map>
#include <vector>
#include <string>

#include "Type.h"

using namespace std;



class VarStack {
	private:
		unordered_set<string> names;
		// unordered_map won't take enums as keys so use an int, same thing
		unordered_map<int, vector<string>> types;

		void addVar(SupportedType type, string name);

	public:
		/* Returns the name of a new variable */
		string newVar(SupportedType type);

		/* Return a new variable name, and try to name the variable the
		 * given name */
		string newVar(SupportedType type, string name);

		/* Return a random variable name of the given type */
		string getVar(SupportedType type);

		/* Pop a number of variables from the stack,
		 * e.g., when we're finished with a scope  */
		bool popVars(unsigned numPop);
};
#endif