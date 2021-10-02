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
private:
	int chisl1, znam1, chisl2, znam2, number, n1,n2;
	int sum = 0, razn = 0, delen = 0, mnoj = 0;
	int i, c, z;

	
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

	void Reduce(int chisl1,int  znam1) {
		if (znam1 != 0) {
			int gcd_op = gcd(chisl1, znam1);
			chisl1 = chisl1 / gcd_op;
			znam1 = znam1 / gcd_op;
			std::cout << chisl1 << "/" << znam1 << "\n";
		

			
		}

		count();
	}
	int gcd(int n, int m) {
		while (m > 0) {
			int c = n % m;
			n = m;
			m = c;
		}
		
		
		return n;
	}
	void printAsFraction(double decimal_fraction) {
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
	

	void printAsFraction(char decimal_fraction[]) {

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

	void summa() {
		Fraction c1, c2, z1, z2;
		std::cin >> c1;
		std::cin >> z1;
		std::cin >> c2;
		std::cin >> z2;

		std::cout << c1.getNum() * z2.getNum() + c2.getNum() * z1.getNum() << " / " << z1.getNum() * z2.getNum();

		count();
	}
	void raznost() {
		Fraction c1, c2, z1, z2;
		std::cin >> c1;
		std::cin >> z1;
		std::cin >> c2;
		std::cin >> z2;

		std::cout << c1.getNum() * z2.getNum() - c2.getNum() + z1.getNum() << " / " << z1.getNum() * z2.getNum();

		count();
	}

	void proizv() {
		Fraction c1, c2, z1, z2;
		std::cin >> c1;
		std::cin >> z1;
		std::cin >> c2;
		std::cin >> z2;

		std::cout << c1.getNum() * c2.getNum() << " / " << z1.getNum() * z2.getNum();

		count();
	}

	void delenie() {
		Fraction c1, c2, z1, z2;
		std::cin >> c1;
		std::cin >> z1;
		std::cin >> c2;
		std::cin >> z2;

		std::cout << c1.getNum() * z2.getNum()  << " / " << z1.getNum() * c2.getNum();

		count();
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
	temp.mnoj = mnoj * n.mnoj;

	return temp;

	
}
Fraction Fraction::operator+(const Fraction& n) {
	Fraction temp;
	temp.sum = sum + n.sum;
	return temp;

}
Fraction Fraction::operator-(const Fraction& n) {
	Fraction temp;
	temp.razn += razn - n.razn;
	return temp;
}
Fraction Fraction::operator/(const Fraction & n) {

	Fraction temp;
	temp.delen += delen / n.delen;

	return temp;

	
}



int main() {

	setlocale(LC_ALL, "");
	Fraction pita;

	std::cout<< "1 - сложение, 2 - умножение \n 3 - вычитание, 4 - деление \n 5 - сократить, 6 - НОД \n 7 - правильная дробь \n 8 - кол-во дробей \n 0 - Выход \n";
	int num = 1;
	while (num!=0)
	{
		std::cout << "Номер операции: \n";
		std::cin >> num;
		if (num == 1) {
			pita.summa();
		}
		else if(num == 2)
		{
			pita.proizv();
		}
		else if (num == 3)
		{
			pita.raznost();
		}
		else if (num == 4)
		{
			pita.delenie();
		}
		else if (num == 5)
		{
			Fraction c, z;
			std::cout << "Введите числитель и знаменатель: ";
			std::cin >> c;
			std::cin >> z;
			pita.Reduce(c.getNum(), z.getNum());
		}
		else if (num == 6)
		{
			Fraction c, z;
			std::cout << "Введите 2 числа: ";
			std::cin >> c;
			std::cin >> z;
			std::cout<<pita.gcd(c.getNum(), z.getNum());
		}
		else if (num == 7)
		{
			
			double d;
			std::cout << "Введите десятичное число: ";
			std::cin >> d;
			 pita.printAsFraction(d);
			
		}
		else if (num == 8)
		{
			std::cout << pita.count();

		}
		
	}
	
	
	return 0;
}