#include "CustomExpressionEvaluator.h"
#include <fstream>
#include <iostream>
#include <string>





double CustomExpressionEvaluator::calculate() {

	 res_ = 1;
	bool b = true;
	for (int i = 0; i < sizeof(arr) -1 ; ++i) {
		if (*(ExpressionEvaluator::arr + i) != 0) {
			if (b == true) {
				res_ += *(arr + i);

			}
			if (b == false) {
				res_ *= *(arr + i);
			}
			b = !b;
		}
	}
	return res_;

}

void CustomExpressionEvaluator::setOperands(double ops[], size_t n)
{
	for (int i = 0;i < n;++i) {
		arr[i] = ops[i];
	}


}

void CustomExpressionEvaluator::setOperand(size_t pos, double value) {

	arr[pos] = value;

}

void CustomExpressionEvaluator::logToScreen()
{

	std::fstream f;                   
	f.open("file.txt", std::ios::in);   
	if (f)                             
	{
		std::string buf;
		std::cout << sizeof(ExpressionEvaluator::arr) << "operands: " << '\n';
		while (getline(f, buf))        
		{
			std::cout << buf << '\n';         
			    
		}
	}

}

void CustomExpressionEvaluator::logToFile(const std::string& filename)
{

	std::ofstream vmdelet_out;                  
	vmdelet_out.open("file.txt", std::ios::app);
	bool b = true;

	for (int i = 0;i < sizeof(arr)- 1;++i) {
		if (b) {
			if (arr[i] != 0 && arr[i] > 0) {
				vmdelet_out << arr[i] << "+";
			}
			else if (arr[i] != 0 && arr[i] < 0) {
				vmdelet_out << "(" << arr[i] << ")" << "+";
			}
		}
		if (b == false) {
			if (arr[i] != 0 && arr[i] > 0) {
				vmdelet_out << arr[i] << "*";
			}
			else if (arr[i] != 0 && arr[i] < 0) {
				vmdelet_out << "(" << arr[i] << ")" << "*";
			}
		}
		b = !b;

	}
	
	
		if ( arr[sizeof(arr) - 1] > 0) {
			vmdelet_out << arr[sizeof(arr) - 1]  ;
		}
		else if ( arr[sizeof(arr) - 1] < 0) {
			vmdelet_out << "(" << arr[sizeof(arr) - 1] << ")" ;
		}
	


	vmdelet_out << '\n' << "->" << res_;
	vmdelet_out.close();

}

void CustomExpressionEvaluator::shuffle()
{

	for (int startIndex = 0; startIndex < sizeof(ExpressionEvaluator::arr - 1); ++startIndex)
	{
		
		int smallestIndex = startIndex;

		
		for (int currentIndex = startIndex + 1; currentIndex < sizeof(ExpressionEvaluator::arr - 1); ++currentIndex)
		{
			
			if (ExpressionEvaluator::arr[currentIndex] < ExpressionEvaluator::arr[smallestIndex])
				
				smallestIndex = currentIndex;
		}

		
		std::swap(ExpressionEvaluator::arr[startIndex], ExpressionEvaluator::arr[smallestIndex]);
	}

}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{

	if (ExpressionEvaluator::arr[i] != round(ExpressionEvaluator::arr[i]) ||
		ExpressionEvaluator::arr[j] != round(ExpressionEvaluator::arr[j]))
		std::swap(ExpressionEvaluator::arr[i], ExpressionEvaluator::arr[j]);

}

