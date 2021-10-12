#pragma once
#include "HouseDevice.h"
#include "IControllable.h"
class Cond :
    public HouseDevice,
	public IControllable
{

	

	double defaultTemp = 23.5;

public:


//	void control(int tempreture) override;
	virtual void control(double tempreture);
	Cond(const char* firm, const char* modelC, double vesC, double tempC, int rezhimC, int yearC);
	Cond(const char* firm, const char* modelC, double vesC, int yearC);
	Cond();
	void setcond(const char firm[], const char setmodel[], double setves, double settemp, int setrezhim, int setyear);
	void getCond();
	void serialize();
	void deserialize();
	void serialize(const std::string& filename);
	void deserialize(const std::string& filename);
	



};

