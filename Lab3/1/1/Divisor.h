#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class Divisor :
    public ExpressionEvaluator,
	public IShuffle
{

	//double res_;
public:
	double calculate() override;
	/*void setOperands(double ops[], size_t n) override;
	void setOperand(size_t pos, double value) override;
	void logToFile(const std::string& filename) override;
	void logToScreen() override;*/
	virtual void shuffle();// override;
	//void shuffle(size_t i, size_t j) override;
	virtual void shuffle(size_t i, size_t j);

};

