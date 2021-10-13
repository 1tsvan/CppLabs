#pragma once
#include "ILoggable.h"
#include "IShuffle.h"
class ExpressionEvaluator :
    public ILoggable,
	public IShuffle
{

	
public:
	int res_ = 0;
	double* arr;
	ExpressionEvaluator();
	ExpressionEvaluator(int N);
	

	virtual double  calculate() = 0;


	 void logToScreen();

	 void logToFile(const std::string& filename);


	 void setOperand(int pos, double value);

	 void setOperands(double ops[], int n);


	 virtual ~ExpressionEvaluator();

};

