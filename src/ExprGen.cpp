#include "ExprGen.h"
#include "Random.h"
#include "VarStack.h"

ExprGen::ExprGen() {
}

void ExprGen::setVarStack(VarStack *vStack) {
	variableStack = vStack;
}

string ExprGen::getRandVarOrValue(SupportedType type) {
	/* first see if there are variables of the specified type */
	if (!variableStack->getVarCount(type)) {
		/* if not, return a random value of that type */
		return getRandValue(type);
	}
	bool useExistingVar = g_randGen.drawNumber(0, 1);
	if (useExistingVar) {
		string randVarName = variableStack->getVar(type);
		return randVarName;
	}
	else {
		/* use random value of the type */
		return getRandValue(type);
	}
}

string ExprGen::genArithmeticExpr(SupportedType type) {
	ArithmeticOperator randArithmeticOp = (ArithmeticOperator)g_randGen.drawNumber(0, NUM_ARITHMETIC_OPERATORS - 1);
	string exprStr;
	switch(randArithmeticOp) {
		case NEGATE:
			exprStr = "-" + getRandVarOrValue(type);
			break;
		case SUM:
			exprStr = getRandVarOrValue(type) + " + " + getRandVarOrValue(type);
			break;
		case DIFFERENCE:
			exprStr = getRandVarOrValue(type) + " - " + getRandVarOrValue(type);
			break;
		case MULTIPLY:
			exprStr = getRandVarOrValue(type) + " * " + getRandVarOrValue(type);
			break;
		case DIVIDE:
			exprStr = getRandVarOrValue(type) + " / " + getRandVarOrValue(type);
			break;
	}
	return exprStr;
}

ExprGen g_exprGen;