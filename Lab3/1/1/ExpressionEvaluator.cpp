#include "ExpressionEvaluator.h"
#include <fstream>
#include <iostream>
#include <string>






ExpressionEvaluator::ExpressionEvaluator() {
	arr = new double[20]{};
	for (int i = 0;i < sizeof(arr);++i) {
		arr[i] = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(int N) {
	arr = new double[N] {};
}

ExpressionEvaluator::~ExpressionEvaluator()
{

	delete[] arr;

}


