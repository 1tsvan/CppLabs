#include "Cond.h"
#include "Heater.h"
#include "HouseDevice.h"
#include "typeinfo"

int main() {



	Cond cond1 = Cond();
	HouseDevice& h = cond1;
	Cond& c1 = dynamic_cast<Cond&>(h);


	c1.control(c1.temp);
	c1.price = 1234;
	c1.getprice();
	c1.serialize();
	c1.deserialize();


	Cond cond2 = Cond();
	HouseDevice& h2 = cond2;
	Cond& c2 = dynamic_cast<Cond&>(h2);

	c2.setcond("BNaikjnbdfs", "0204", 23.2, 21, 1, 2020);
	c2.color = "Red";
	c2.price = 123;
	c2.getColor();
	c2.serialize();
	c2.deserialize();



	Heater heat = Heater();
	HouseDevice& h3 = heat;
	Heater& heater = dynamic_cast<Heater&>(h3);

	

	heater.firma = "Next Door - Everything is 300$";
	heater.temp = 23;
	heater.setColor("Black");
	heater.getColor();
	heater.control(heater.temp);
	heater.serializeHeater();
	heater.deserializeHeater();

	


	return 0;
}