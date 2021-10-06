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



#include <iostream>
#include <random>
#include <string>
#include <sstream>


class Fraction {

	int chisl1, znam1, chisl2, znam2, number, n1,n2;
	int sum  , razn  , delen  , mnoj  ;
	//

	
public:
	static int count() {
		static int count = 0;
		return count++;
	}


	Fraction(double num = 0) : number(num)
	{
	}

	int getNum();

	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction &);
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&  );
	friend std::ostream& operator<< (std::ostream& out, const Fraction& n);
	friend std::istream& operator>> (std::istream& in, Fraction& n);

	static void Reduce(int chisl1,int  znam1) {
		if (znam1 != 0) {
			int gcd_op = gcd(chisl1, znam1);
			chisl1 = chisl1 / gcd_op;
			znam1 = znam1 / gcd_op;
			std::cout << chisl1 << "/" << znam1 << "\n";
		

			
		}

		count();
	}
	static int gcd(int n, int m) {
		while (m > 0) {
			int c = n % m;
			n = m;
			m = c;
		}
		
		
		return n;
	}
	static void printAsFraction(double decimal_fraction) {
		int i, c, z;
		int x;
		x = decimal_fraction;
		decimal_fraction -= x;
		  i = x;
		  c = decimal_fraction * 100;
		  z = 100;

		  for (int k = 0;k < 5;k++)
			  for (int j = 2;j <= c;j++)
				  if ((!(c % j)) && (!(z % j))) {
					  c /= j;
					  z /= j;
				  }
		  std::cout  << c << "/" << z;

		  count();
		  
	}
	

	static void printAsFraction(char decimal_fraction[]) {
		int i, c, z;
		double smth = atof(decimal_fraction);

		int x;
		
		x = smth;
		decimal_fraction -= x;
		i = x;
		c = smth * 100;
		z = 100;

		for (int k = 0;k < 5;k++)
			for (int j = 2;j <= c;j++)
				if ((!(c % j)) && (!(z % j))) {
					c /= j;
					z /= j;
				}
		std::cout << c << "/" << z;

		
	}

	

};

int Fraction:: getNum()  {
	return number;
}

std::ostream& operator<< (std::ostream& out, const Fraction& n)
{
	out << n.number;
	return out;
}
std::istream& operator>> (std::istream& in,  Fraction& n)
{
	in >> n.number;
	return in;
}

Fraction Fraction::operator*(const Fraction& n) {
	Fraction temp;
	temp.number = number * n.number;

	return temp;

}
Fraction Fraction::operator+(const Fraction& n) {
	Fraction temp;
	temp.number = number + n.number;
	return temp;

}
Fraction Fraction::operator-(const Fraction& n) {
	Fraction temp;
	temp.number = number - n.number;
	return temp;
}
Fraction Fraction::operator/(const Fraction & n) {

	Fraction temp;
	temp.number = number / n.number;

	return temp;

	
}



int main() {

	setlocale(LC_ALL, "");
	Fraction pita;
	Fraction num1 = 2,num2 = 4,num3 = 5,num4 = 10;
	pita.gcd(num1.getNum(), num2.getNum());
	pita.Reduce(num1.getNum(), num2.getNum());
	pita.printAsFraction(0.5);
	std::cout << '\n' << num1 * num2 << "	" << num2 - num1 << "	 ";
	std::cout << '\n' << num4 / num2 << "	" << num2 + num1 << "	 ";
	std::cout << '\n';
	std::cout << pita.count();


	
	return 0;
}