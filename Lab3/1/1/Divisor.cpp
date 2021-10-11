#include "Divisor.h"
#include <fstream>
#include <iostream>
#include <string>


double Divisor::calculate() {
	res_ = ExpressionEvaluator::arr[0];
	
	for (int i = 1; i < sizeof(ExpressionEvaluator::arr) ; ++i) {
		
		if(*(ExpressionEvaluator::arr + i) != 0)
			res_ /= *(ExpressionEvaluator::arr + i);

	}
	return res_;
}

void Divisor::logToFile(const std::string& filename) {


	std::ofstream vmdelet_out;                    
	vmdelet_out.open("file.txt", std::ios::app);  
	for (int i = 0;i < sizeof(ExpressionEvaluator::arr) - 1;++i) {
		
		if (ExpressionEvaluator::arr[i] != 0 && ExpressionEvaluator::arr[i] > 0) {
			vmdelet_out << ExpressionEvaluator::arr[i] << "/";
		}
		else if (ExpressionEvaluator::arr[i] != 0 && ExpressionEvaluator::arr[i] < 0) {
			vmdelet_out << "(" << ExpressionEvaluator::arr[i] << ")" << "/";
		}
	}

	if (ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1] > 0) {
		vmdelet_out << ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1];
	}
	else if (ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1] < 0) {
		vmdelet_out << "(" << ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1] << ")";
	}

		
	
	vmdelet_out << '\n' << "<Result  " << res_ << ">";
	vmdelet_out << '\n';
	vmdelet_out.close();

}

void Divisor::logToScreen()
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

void Divisor::shuffle()
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

void Divisor::shuffle(size_t i, size_t j)
{


	if (ExpressionEvaluator::arr[i] != round(ExpressionEvaluator::arr[i]) ||
		ExpressionEvaluator::arr[j] != round(ExpressionEvaluator::arr[j]))
		std::swap(ExpressionEvaluator::arr[i], ExpressionEvaluator::arr[j]);

}

void Divisor::setOperands(double ops[], size_t n)
{

	
	for (int i = 0; i < n ;++i) {
		ExpressionEvaluator::arr[i] = ops[i];
	}


}

void Divisor::setOperand(size_t pos, double value) {


	ExpressionEvaluator::arr[pos] = value;

	

}


