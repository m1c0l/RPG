#ifndef SCOPE_H
#define SCOPE_H

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Scope {
	private:
		unordered_set<string> names;
		unordered_map<string, vector<string>> types;

		void addVar(string type, string name);

	public:
		/* Returns the name of a new variable */
		string newVar(string type);

		/* Return a new variable name, and try to name the variable the
		 * given name */
		string newVar(string type, string name);

		/* Return a random variable name of the given type */
		string getVar(string type);
};

#endif
