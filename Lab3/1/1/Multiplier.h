#pragma once
#include "ExpressionEvaluator.h"

class Multiplier :
    public ExpressionEvaluator//,
	//public IShuffle
{
	double res_;
public:
	//Multiplier() : ExpressionEvaluator() {}
	//Multiplier(int n) : ExpressionEvaluator(n) {};
	 double calculate() override;
	//double mul_;
	/*void setOperands(double ops[], size_t n) override;
	void setOperand(size_t pos, double value) override;
	void logToScreen() override;
	void logToFile(const std::string& filename) override;*/
	  void shuffle() override;
 
	  void shuffle(size_t i, size_t j) override;


};

