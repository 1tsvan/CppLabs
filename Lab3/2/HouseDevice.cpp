#include "HouseDevice.h"
#include <iostream>

void HouseDevice::getprice()
{

	std::cout << price << '\n';

}

void HouseDevice::getfirma()
{

	std::cout << firma << '\n';

}

void HouseDevice::setColor(const char* c)
{

	color = c;

}

void HouseDevice::getColor()
{

	std::cout << color << '\n';

}
