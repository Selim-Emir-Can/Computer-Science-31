#include<iostream>
#include<string>
using namespace std;

#ifndef PLANEFLIGHT_H
#define PLANEFLIGHT_H

class PlaneFlight
{
public:
	PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);

	double getCost();
	void setCost(double cost);

	double getMileage();
	void setMileage(double mileage);
	
	string getName();
	void setName(string name);

	string getFromCity();
	void setFromCity(string from);

	string getToCity();
	void setToCity(string to);

private:
	double mCost;
	string mFromCity;
	string mToCity;
	string mName;
	double mMileage;
};

#endif