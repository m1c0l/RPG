#include <string>

#include "Type.h"

class VarStack;

enum ArithmeticOperator {
	NEGATE = 0,
	SUM,
	DIFFERENCE,
	MULTIPLY,
	DIVIDE
};

#define NUM_ARITHMETIC_OPERATORS 5

enum LogicOperator {
	LESS_THAN = 0,
	LESS_THAN_OR_EQUAL,
	EQUAL,
	GREATER_THAN_OR_EQUAL,
	GREATER_THAN
};

#define NUM_LOGIC_OPERATORS 5

class ExprGen {
public:
	ExprGen();
	void setVarStack(VarStack *vStack);
	string genArithmeticExpr(SupportedType type);
private:
	VarStack *variableStack;
	string getRandVarOrValue(SupportedType type);
};

extern ExprGen g_exprGen;
