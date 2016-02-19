#ifndef SCOPE_H
#define SCOPE_H

using namespace std;


class Function;

class Scope {
	private:
		/* Number of variables only in this current scope;
		 * doesn't include variables in other scopes within this scope */
		unsigned numVars;
		/* Function that this scope resides in */
		Function *ownerFunction;

	public:
		Scope();
		/* Increment this scope's number of variables by 1 */
		void incVarCount();
		/* Return numVars */
		unsigned getVarCount();
		
};

#endif
