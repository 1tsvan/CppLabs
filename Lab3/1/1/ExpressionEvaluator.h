#pragma once
#include "ILoggable.h"
#include "IShuffle.h"
class ExpressionEvaluator :
    public ILoggable,
	public IShuffle
{

public:
	double* arr;
	ExpressionEvaluator();
	ExpressionEvaluator(int N);
	virtual void setOperand(size_t pos, double value) = 0;
	virtual void setOperands(double ops[], size_t n) = 0;

	 double virtual calculate() = 0;

	 virtual ~ExpressionEvaluator();

};

