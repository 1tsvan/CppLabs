#pragma once
#include <ostream>

class Frac
{
	
public:
	
	int  number;
	int n, d;

	static int count();
	Frac(int a=0, int b=1);
	int getNum();
	static void printAsFraction(char decimal_fraction[]);
	static void printAsFraction(double decimal_fraction);
	static int gcd(int n, int m);
	static void Reduce(int n1, int  n2);
	Frac operator + (const Frac& f);
	Frac operator - (const Frac& f);
	Frac operator * (const Frac& f);
	Frac operator / (const Frac& f);

};

