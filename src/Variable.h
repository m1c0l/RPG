#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

class Variable {
	public:
		string mName;
		long long mValue;
		Variable(string aName, long long aVal) {
			mName = aName;
			mValue = aVal;
		}
};

#endif

