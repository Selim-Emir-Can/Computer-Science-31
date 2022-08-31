#include<iostream>
#include<string>
#include"PlaneFlight.h"
#include"FrequentFlyerAccount.h"
using namespace std;

FrequentFlyerAccount::FrequentFlyerAccount(string name)
{
	if (name != "")
	{
		mName = name;
	}
	mBalance = 0;
}

double FrequentFlyerAccount::getBalance()
{
		return(mBalance);
}

string FrequentFlyerAccount::getName()
{
		return(mName);
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight)
{
	if ((flight.getName() == mName) && (flight.getName() != "") && (mName != "")
		&& (flight.getFromCity() != flight.getToCity()) && (flight.getFromCity() != "")
		&& (flight.getToCity() != "") && (mBalance != -1) && (flight.getCost() > 0) && (flight.getMileage() > 0))
	{
		mBalance = mBalance + flight.getMileage();
		return(true);
	}
	else
	{
		return(false);
	}
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage)
{
	if ((mBalance >= mileage) && (mBalance != -1) && (mileage > 0))
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight)
{
	if (canEarnFreeFlight(mileage) && (from != to) && (from != "") && (to != "")) // because we want to create the desired PlaneFlight
	{																			// we do not check if the flight provided is valid
		string swap = "#Swapping";												// since we will adjust the everything as long as other parameters are valid
		flight.setFromCity(swap);
		flight.setToCity(to);
		flight.setFromCity(from);
		flight.setMileage(mileage);
		flight.setCost(0);
		flight.setName(mName);
		mBalance = mBalance - flight.getMileage();
		return(true);
	}
	else
	{
		return(false);
	}
}