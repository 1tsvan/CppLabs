#pragma once
#include "HouseDevice.h"
#include "IControllable.h"
class Heater :
    public HouseDevice,
	public IControllable
{

	double defaultTemp = 25;

public:


	//void control(int tempreture) override;
	virtual void control(double tempreture);
	Heater(const char* firm, const char* modelC, double vesC, double tempC, int rezhimC, int yearC);
	Heater(const char* firm, const char* modelC, double vesC, int yearC);
	Heater();
	

	void setHeater(const char firm[], const char setmodel[], double setves, double settemp, int setrezhim, int setyear);
	void getHeater();
	void serializeHeater();
	void deserializeHeater();
	void serializeHeater(const std::string& filename);
	void deserializeHeater(const std::string& filename);
	


};

