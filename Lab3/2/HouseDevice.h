#pragma once
#include <string>
class HouseDevice
{


public:


	const char* firma;
	const char* model;
	double ves;
	double temp;
	int rezhim;
	int year;
	double* array;
	double price;
	const char* color;



	virtual void  getprice();
	virtual void  getfirma();
	virtual void  setColor(const char* color);
	virtual void  getColor();


	

};

