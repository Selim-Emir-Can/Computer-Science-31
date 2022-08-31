#include<iostream>
#include<string>
#include"PlaneFlight.h"
using namespace std;

PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage)
{
	if (passengerName != "")
	{
		mName = passengerName;
	}

	if ((fromCity != toCity) && (fromCity != ""))
	{
		mFromCity = fromCity;
	}

	if ((toCity != fromCity) && (toCity != ""))
	{
		mToCity = toCity;
	}

	if (cost >= 0)
	{
		mCost = cost;
	}
	else
	{
		mCost = -1;
	}

	if (mileage > 0)
	{
		mMileage = mileage;
	}
	else
	{
		mMileage = -1;
	}
	
}

double PlaneFlight::getCost()
{
		return(mCost);
}

void PlaneFlight::setCost(double cost)
{
	if (cost >= 0)
	{
		mCost = cost;
	}
	else
	{
		mCost = -1;
	}
}

double PlaneFlight::getMileage()
{
		return(mMileage);
}

void PlaneFlight::setMileage(double mileage)
{
	if (mileage > 0)
	{
		mMileage = mileage;
	}
	else
	{
		mMileage = -1;
	}
}

string PlaneFlight::getName()
{
		return(mName);
}

void PlaneFlight::setName(string name)
{
	if (name != "")
	{
		mName = name;
	}
}

string PlaneFlight::getFromCity()
{
		return(mFromCity);
}

void PlaneFlight::setFromCity(string from)
{
	if ((from != "") && (from != mToCity))
	{
		mFromCity = from;
	}
}

string PlaneFlight::getToCity()
{
		return(mToCity);
}

void PlaneFlight::setToCity(string to)
{
	if (( to != "") && (to != mFromCity))
	{									
		mToCity = to;
	}
}