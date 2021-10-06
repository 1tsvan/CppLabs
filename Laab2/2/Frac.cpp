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

void Frac::printAsFraction(double decimal_fraction)
{
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
	std::cout << c << "/" << z;

	count();
}


