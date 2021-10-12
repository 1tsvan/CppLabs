#include "Multiplier.h"
#include <fstream>
#include <iostream>
#include <string>


double Multiplier::calculate() {
	ExpressionEvaluator::res_ = 1;
	for (int i = 0; i < sizeof(ExpressionEvaluator::arr) ; ++i) {
		
		if(*(ExpressionEvaluator::arr+ i) != 0)
			ExpressionEvaluator::res_ *= *(ExpressionEvaluator::arr + i);

	}
	return ExpressionEvaluator::res_;
}

void Multiplier::shuffle()
{
}

void Multiplier::shuffle(size_t i, size_t j)
{
}









//void Multiplier::logToFile(const std::string& filename) {
//
	/*std::ofstream vmdelet_out;                   
	vmdelet_out.open("file.txt", std::ios::app);
	for (int i = 0;i < sizeof(ExpressionEvaluator::arr)-1;++i) {
		if (ExpressionEvaluator::arr[i] != 0) {
			vmdelet_out << ExpressionEvaluator::arr[i] << "*" ;
		}
	}
	vmdelet_out << ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1];
	vmdelet_out << '\n' << "<Result  " << res_ << ">";
	vmdelet_out << '\n';
	vmdelet_out.close();*/
//
//}
//
//
//
//void Multiplier::setOperands(double ops[], size_t n)
//{
//	
//
	/*for (int i = 0;i < n ;++i) {
		ExpressionEvaluator::arr[i] = ops[i];
	}*/
//
//
//}
//
//void Multiplier::setOperand(size_t pos, double value) {
//
//
	/*static double res = 1;
	ExpressionEvaluator::arr[pos] = value;*/
//
//
//
//
//}
//
//void Multiplier::logToScreen()
//{
//
	//std::fstream f;                     
	//f.open("file.txt", std::ios::in);  
	//if (f)                              
	//{
	//	std::string buf;     
	//	std::cout << sizeof(ExpressionEvaluator::arr) << "operands: " << '\n';
	//	while (getline(f, buf))        
	//	{
	//		std::cout << buf << '\n';          
	//		
	//	}
	//}
//
//}
//

