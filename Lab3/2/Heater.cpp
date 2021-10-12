#include "Heater.h"
#include <iostream>
#include "fstream"

void Heater::control(double tempreture)
{
	if (tempreture > 45)
		std::cout << "Heater OFF" << '\n';
	else
		temp = defaultTemp;
}

Heater::Heater(const char* firm, const char* modelC, double vesC, double tempC, int rezhimC, int yearC)
{

	firma = firm;
	model = modelC;
	ves = vesC;
	temp = tempC;
	rezhim = rezhimC;
	year = yearC;

	

}

Heater::Heater(const char* firm, const char* modelC, double vesC, int yearC)
{

	firma = firm;
	model = modelC;
	ves = vesC;
	year = yearC;

	


}

Heater::Heater()
{

	firma = "Ford";
	model = "S5";
	ves = 63.7;
	temp = 5.7;
	rezhim = 1;
	year = 2021;



}

void Heater::setHeater(const char firm[], const char setmodel[], double setves, double settemp, int setrezhim, int setyear)
{
	firma = firm;
	model = setmodel;
	ves = setves;
	temp = settemp;
	rezhim = setrezhim;
	year = setyear;
}

void Heater::getHeater()
{
	std::cout << firma << "\n";
	std::cout << model << "\n";
	std::cout << ves << "\n";
	if (temp != 0)
		std::cout << temp << "\n";
	if (rezhim != 0)
		std::cout << rezhim << "\n";
	std::cout << year << "\n";
}

void Heater::serializeHeater()
{
	std::ofstream out("D:\\file2.txt", std::ios::app);
	if (out.is_open())
	{


		out << firma << std::endl;
		out << model << std::endl;
		out << ves << std::endl;
		if (temp != 0)
			out << temp << std::endl;
		if (rezhim != 0)
			out << rezhim << std::endl;
		out << year << std::endl;
	}
	out.close();
}

void Heater::deserializeHeater()
{
	std::string line;

	std::ifstream in("D:\\file2.txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();
}

void Heater::serializeHeater(const std::string& filename)
{
	std::ofstream out(filename, std::ios::app);
	if (out.is_open())
	{


		out << firma << std::endl;
		out << model << std::endl;
		out << ves << std::endl;
		if (temp != 0)
			out << temp << std::endl;
		if (rezhim != 0)
			out << rezhim << std::endl;
		out << year << std::endl;
	}
	out.close();
}

void Heater::deserializeHeater(const std::string& filename)
{
	std::string line;

	std::ifstream in(filename);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();
}
