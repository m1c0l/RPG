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
	bool isExprValid = false;
	string exprStr;
	while (!isExprValid) {
		ArithmeticOperator randArithmeticOp = (ArithmeticOperator)g_randGen.drawNumber(0, NUM_ARITHMETIC_OPERATORS - 1);
		switch(randArithmeticOp) {
			case NEGATE: {
				string randVal = getRandVarOrValue(type);
				if (randVal[0] == '-') {
					break;
				}
				exprStr = "-" + randVal;
				isExprValid = true;
				break;
			}
			case SUM:
				exprStr = getRandVarOrValue(type) + " + " + getRandVarOrValue(type);
				isExprValid = true;
				break;
			case DIFFERENCE:
				exprStr = getRandVarOrValue(type) + " - " + getRandVarOrValue(type);
				isExprValid = true;
				break;
			case MULTIPLY:
				exprStr = getRandVarOrValue(type) + " * " + getRandVarOrValue(type);
				isExprValid = true;
				break;
			case DIVIDE:
				exprStr = getRandVarOrValue(type) + " / " + getRandVarOrValue(type);
				isExprValid = true;
				break;
		}
	}
	return exprStr;
}

ExprGen g_exprGen;