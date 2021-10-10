#include "Multiplier.h"
#include <fstream>
#include <iostream>
#include <string>


double Multiplier::calculate() {
	 res_ = 1;
	for (int i = 0; i < sizeof(ExpressionEvaluator::arr) ; ++i) {
		
		if(*(ExpressionEvaluator::arr+ i) != 0)
			res_ *= *(ExpressionEvaluator::arr + i);

	}
	return res_;
}

void Multiplier::logToFile(const std::string& filename) {

	std::ofstream vmdelet_out;                   
	vmdelet_out.open("file.txt", std::ios::app);
	for (int i = 0;i < sizeof(ExpressionEvaluator::arr)-1;++i) {
		if (ExpressionEvaluator::arr[i] != 0) {
			vmdelet_out << ExpressionEvaluator::arr[i] << "*" ;
		}
	}
	vmdelet_out << ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1];
	vmdelet_out << '\n' << "-> " <<  res_;
	vmdelet_out << '\n';
	vmdelet_out.close();

}

void Multiplier::shuffle()
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

void Multiplier::shuffle(size_t i, size_t j)
{

	if (ExpressionEvaluator::arr[i] != round(ExpressionEvaluator::arr[i]) ||
		ExpressionEvaluator::arr[j] != round(ExpressionEvaluator::arr[j])) 
							std::swap(ExpressionEvaluator::arr[i], ExpressionEvaluator::arr[j]);
	

}

void Multiplier::setOperands(double ops[], size_t n)
{
	

	for (int i = 0;i < n ;++i) {
		ExpressionEvaluator::arr[i] = ops[i];
	}


}

void Multiplier::setOperand(size_t pos, double value) {


	static double res = 1;
	ExpressionEvaluator::arr[pos] = value;
	//res *= arr[pos];



}

void Multiplier::logToScreen()
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


