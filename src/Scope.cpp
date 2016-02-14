#include <unordered_set>
#include <string>
#include <cstdlib>
using namespace std;

struct Variable {
	string type;
	string name;
	Variable(string type);
	Variable(string type, string name);
	bool operator==(const Variable& other) const;
	static char randChar();
};

Variable::Variable(string type) {
	type = type;
	name = "";
}

Variable::Variable(string type, string name) {
	type = type;
	name = name;
}

bool Variable::operator==(const Variable& other) const {
	return name == other.name;
}

char Variable::randChar() {
	return (rand() % ('z' - 'a')) + 'a';
}

namespace std {
	template <>
	struct hash<Variable>
	{
		std::size_t operator()(const Variable & t) const
		{
			return hash<string>{}(t.name);
		}
	};
}


class Scope {
	private:
		unordered_set<Variable> variables;

	public:
		string newVariable(string type);
		string newVariable(string type, string name);
		string getVariable(string type);
};

string Scope::newVariable(string type) {
	Variable var = Variable(type);
	var.name = Variable::randChar();
	while (variables.count(var))
		var.name += Variable::randChar();
	variables.insert(var);
	return var.name;
}

string Scope::getVariable(string type) {
	if (variables.empty())
		throw runtime_error("Scope has no variables of type " + type);

	int random = rand() % variables.size();
	for (Variable var : variables) {
		if (random-- == 0)
			return var.name;
	}
	return "";
}

#include <iostream>
int main() {
	srand((int)time(0));
	Scope scope;
	while(1) {
		cout << scope.newVariable("int") << '\n';
		cout << scope.getVariable("") << '\n';
		cin.ignore();
	}
}
