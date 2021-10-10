#pragma once
#include "ExpressionEvaluator.h"
class CustomExpressionEvaluator :
    public ExpressionEvaluator
{

public:
	double res_;
	double calculate() override;
	void setOperands(double ops[], size_t n) override;
	void setOperand(size_t pos, double value) override;
	void logToScreen() override;
	void logToFile(const std::string& filename) override;
	void shuffle() override;
	void shuffle(size_t i, size_t j) override;
};

