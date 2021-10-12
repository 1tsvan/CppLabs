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
	/*virtual void setOperand(size_t pos, double value) = 0;
	virtual void setOperands(double ops[], size_t n) = 0;*/

	virtual double  calculate() = 0;


	 void logToScreen();

	 void logToFile(const std::string& filename);


	 void setOperand(int pos, double value);

	 void setOperands(double ops[], int n);


	 virtual ~ExpressionEvaluator();

};

