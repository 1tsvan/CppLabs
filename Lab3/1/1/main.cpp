
#include "Multiplier.h"

#include <iostream>
#include "Divisor.h"
#include "ExpressionEvaluator.h"

#include "CustomExpressionEvaluator.h"


int main() {



	ExpressionEvaluator* ex[3];


	ex[0] = new Multiplier();
	double sum_operands[] = { 5, 2.5, 3.5 };
	ex[0]->setOperands(sum_operands, 3);
	ex[0]->shuffle();
	ex[0]->calculate();
	ex[0]->logToFile("file.txt");
	ex[0]->logToScreen();

	ex[1] = new Divisor();
	double sum_operands2[] = { 150, -3, 10, -2.5 };
	ex[1]->setOperands(sum_operands2, 4);
	ex[1]->shuffle();
	ex[1]->calculate();
	ex[1]->logToFile("file.txt");
	ex[1]->logToScreen();
	

	ex[2] = new CustomExpressionEvaluator();
	double sum_operands3[] = { 4,3,2, 7 };
	ex[2]->setOperands(sum_operands3, 4);
	ex[2]->calculate();
	ex[2]->logToFile("file.txt");
	ex[2]->logToScreen();
}