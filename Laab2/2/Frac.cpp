#include "Frac.h"
#include <iostream>

using namespace std;



int Frac::gcd(int n, int m)
{
	while (m > 0) {
		int c = n % m;
		n = m;
		m = c;
	}


	return n;
}

void Frac::Reduce(int n1, int n2)
{
	if (n2 != 0) {
		int gcd_op = gcd(n1, n2);
		n1 = n1 / gcd_op;
		n2 = n2 / gcd_op;
		std::cout << n1 << "/" << n2 << "\n";



	}

	count();
}

Frac Frac::operator+(const Frac& f)
{
	int chisl = ((n * f.d) + (f.n * d));
	int znam = (d * f.d);

	return Frac(chisl, znam);
}

Frac Frac::operator-(const Frac& f)
{
	int chisl = ((n * f.d) - (f.n * d));
	int znam = (d * f.d);

	return Frac(chisl, znam);
}

Frac Frac::operator*(const Frac& f)
{
	int chisl = n * f.n;
	int znam = d * f.d;

	return Frac(chisl, znam);
}

Frac Frac::operator/(const Frac& f)
{
	int chisl = n * f.d;
	int znam = d * f.n;
	return Frac(chisl, znam);
}

int Frac::count()
{
	static int count = 0;
	return count++;
}

Frac::Frac(int a , int b ) {
	n = a;
	d = b; 
}


int Frac::getNum()
{
	return number;
}

void Frac::printAsFraction(char decimal_fraction[])
{
	int i, c, z;
	double smth = atof(decimal_fraction);

	int x;
	x = smth;
	smth -= x;

	int rang = 0;
	int n = smth;
	while (int(smth) != smth) {
		smth *= 10;
		++rang;
	}
	i = x;
	c = smth;
	z = 100;


	std::cout << c << "/" << pow(10, rang);

	count();

}

void Frac::printAsFraction(double decimal_fraction)
{
	int i, c, z;
	int x;
	x = decimal_fraction;
	decimal_fraction -= x;
	
	int rang = 0;
	int n = decimal_fraction;
	while (int(decimal_fraction) != decimal_fraction) {
		decimal_fraction *= 10;
		++rang;
	}
	i = x;
	c = decimal_fraction;
	z = 100;


	std::cout << c << "/" << pow(10,rang);

	count();
}


