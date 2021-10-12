#include "ExpressionEvaluator.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Divisor.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"






ExpressionEvaluator::ExpressionEvaluator() {
	arr = new double[20]{};
	for (int i = 0;i < sizeof(arr);++i) {
		arr[i] = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(int N) {
	arr = new double[N] {};
}

void ExpressionEvaluator::logToScreen()
{
	if (typeid(*this) == typeid(Divisor)) {
		std::fstream f;
		f.open("file.txt", std::ios::in);
		if (f)
		{
			std::string buf;
			while (getline(f, buf))
			{
				std::cout << buf << '\n';

			}
		}
	}
	if (typeid(*this) == typeid(Multiplier)) {
		std::fstream f;
		f.open("file2.txt", std::ios::in);
		if (f)
		{
			std::string buf;
			while (getline(f, buf))
			{
				std::cout << buf << '\n';

			}
		}
	}
	if (typeid(*this) == typeid(CustomExpressionEvaluator)) {
		std::fstream f;
		f.open("file3.txt", std::ios::in);
		if (f)
		{
			std::string buf;
			while (getline(f, buf))
			{
				std::cout << buf << '\n';

			}
		}
	}
}

void ExpressionEvaluator::logToFile(const std::string& filename)
{

	std::ofstream vmdelet_out;
	vmdelet_out.open("file.txt", std::ios::app);
	if (typeid(*this) == typeid(Divisor)) {
		vmdelet_out << '\n';
		vmdelet_out << sizeof(ExpressionEvaluator::arr) << "operands: " << '\n';
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


		vmdelet_out << '\n' << "<Result  " << calculate() << ">";
		vmdelet_out << '\n';
		vmdelet_out.close();
	}

	if (typeid(*this) == typeid(Multiplier)) {
		std::ofstream vmdelet_out;
		vmdelet_out.open("file2.txt", std::ios::app);
		vmdelet_out << '\n';
		vmdelet_out << sizeof(ExpressionEvaluator::arr) << "operands: " << '\n';
		for (int i = 0;i < sizeof(ExpressionEvaluator::arr) - 1;++i) {
			if (ExpressionEvaluator::arr[i] != 0 && ExpressionEvaluator::arr[i] > 0) {
				vmdelet_out << ExpressionEvaluator::arr[i] << "*";
			}
			else if (ExpressionEvaluator::arr[i] != 0 && ExpressionEvaluator::arr[i] < 0) {
				vmdelet_out << "(" << ExpressionEvaluator::arr[i] << ")" << "*";
			}
		}
		if (ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1] > 0) {
			vmdelet_out << ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1];
		}
		else if (ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1] < 0) {
			vmdelet_out << "(" << ExpressionEvaluator::arr[sizeof(ExpressionEvaluator::arr) - 1] << ")";
		}
		vmdelet_out << '\n' << "<Result  " << calculate() << ">";
		vmdelet_out << '\n';
		vmdelet_out.close();
	}

	if (typeid(*this) == typeid(CustomExpressionEvaluator)) {
		std::ofstream vmdelet_out;
		vmdelet_out.open("file3.txt", std::ios::app);
		bool b = true;
		vmdelet_out << '\n';
		vmdelet_out << sizeof(ExpressionEvaluator::arr) << "operands: " << '\n';
		for (int i = 0;i < sizeof(arr) - 1;++i) {
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


		if (arr[sizeof(arr) - 1] > 0) {
			vmdelet_out << arr[sizeof(arr) - 1];
		}
		else if (arr[sizeof(arr) - 1] < 0) {
			vmdelet_out << "(" << arr[sizeof(arr) - 1] << ")";
		}



		vmdelet_out << '\n' << "<Result  " << res_ << ">";
		vmdelet_out.close();
	}

}

void ExpressionEvaluator::setOperand(int pos, double value)
{
	static double res = 1;
	ExpressionEvaluator::arr[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], int n)
{
	for (int i = 0;i < n;++i) {
		ExpressionEvaluator::arr[i] = ops[i];
	}
}

ExpressionEvaluator::~ExpressionEvaluator()
{

	delete[] arr;

}


