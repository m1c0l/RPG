#ifndef VARNAME_H
#define VARNAME_H

#include <vector>
#include <string>

using namespace std;

class VarNameGen {
public:
	VarNameGen();
	string getRandVarName();
private:
	vector<string> varWords;
};

extern VarNameGen g_varNameGen;

#endif