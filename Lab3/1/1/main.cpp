
#include "Multiplier.h"

#include <iostream>
#include "Divisor.h"
#include "ExpressionEvaluator.h"

#include "CustomExpressionEvaluator.h"


int main() {



	ExpressionEvaluator* ex[3];


	ex[0] = new Multiplier();
	double operands1[] = { 1.5, 4, -2.5, -8, -15 };
	ex[0]->setOperands(operands1, 5);
	ex[0]->shuffle();
	ex[0]->calculate();
	ex[0]->logToFile("file.txt");
	ex[0]->logToScreen();

	ex[1] = new Divisor();
	double operands2[] = { 150, -3, 10, -2.5 };
	ex[1]->setOperands(operands2, 4);
	ex[1]->shuffle();
	ex[1]->calculate();
	ex[1]->logToFile("file.txt");
	ex[1]->logToScreen();


	ex[2] = new CustomExpressionEvaluator();
	double operands3[] = { 50, 40, -10, -2 };
	ex[2]->setOperands(operands3, 4);
	ex[2]->calculate();
	ex[2]->logToFile("file.txt");
	ex[2]->logToScreen();
}