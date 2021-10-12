#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class CustomExpressionEvaluator :
    public ExpressionEvaluator,
	public IShuffle
{

public:
	
	double calculate() override;
	virtual void shuffle(); 
	virtual void shuffle(size_t i, size_t j);
};

