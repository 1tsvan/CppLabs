/*
Написать класс Fraction для представления обыкновенных дробей (как отношения
двух целых чисел x/y). Перегрузить операторы +, -, *, / для дробей. Реализовать метод
void reduce() для сокращения дроби, а также статические методы:
 int gcd(int n, int m)
функция для нахождения наибольшего общего делителя чисел n и m;
 void printAsFraction(double decimal_fraction)
 void printAsFraction(char* decimal_fraction)
перегруженные методы вывода десятичной дроби в виде обыкновенной
(например, при значении decimal_fraction = 0.43 на экране должно
вывестись 43/100, при 0.25 – 1/4 и т.д.).
Также реализовать в виде статического члена класса счетчик всех созданных на
данный момент в программе экземпляров дробей.
Продемонстрировать работу созданного класса. Создать несколько объектов дробей.
Произвести операции сложения, вычитания, умножения и деления дробей. Вывести
на экран результаты. Показать также результаты работы статических методов класса
*/


#include "Frac.h"
#include <iostream>
#include <random>
#include <string>
#include <sstream>

using namespace std;


ostream& operator<<(ostream& stream, Frac obj)
{
	stream << obj.n << '/' << obj.d;
	return stream;
}

int main() {

	Frac f1(1, 2), f2(3, 4);


	std::cout << f1 + f2 << '\n';
	std::cout << f1 - f2 << '\n';
	std::cout << f1 * f2 << '\n';
	std::cout << f1 / f2 << '\n';
	Frac f;
	f.gcd(10,20);
	f.Reduce(4, 6);
	f.printAsFraction(0.2);
	std::cout << f1.count();
	
	
	return 0;
}