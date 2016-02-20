#ifndef SCOPE_H
#define SCOPE_H

#include <unordered_map>

#include "Type.h"

using namespace std;


class Function;

class Scope {
	private:
		/* Number of variables only in this current scope;
		 * doesn't include variables in other scopes within this scope */
		unsigned numVars;
		/* Function that this scope resides in */
		Function *ownerFunction;
		/* Use an int in place of SupportedType
		 * so this maps SupportedType -> count of variables of that type */
		unordered_map<int, unsigned> varTypeCounts;

	public:
		Scope();
		/* Increment this scope's number of variables by 1 */
		void incVarCount(SupportedType type);
		/* Return numVars */
		unsigned getVarCount();

		const unordered_map<int, unsigned> getVarTypeCounts();
};

#endif
