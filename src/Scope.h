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
		string newVar(string type);
		string newVar(string type, string name);
		string getVar(string type);
};

#endif
