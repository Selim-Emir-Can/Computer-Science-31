#include<iostream>
#include<string>
using namespace std;

int main() {

	string input_Month, day_of_the_week;
	int input_Day=0, input_Year=0, month_code=0, century_value=0, century_code=0, year_code=0, day_code=0;

	cout << "Provide a month: "; 
	getline(cin, input_Month);
	cout << "Provide a day: ";
	cin >> input_Day;
	cout << "Provide a year: ";
	cin >> input_Year;

	cout.setf(ios::boolalpha);
	bool leap_year = false;
	if (input_Year % 400 == 0)				//leap year calculation
	{
		leap_year = true;
	}
	else if ((input_Year % 100 == 0))
	{
		leap_year = false;
	}
	else if (input_Year % 4 == 0)
	{
		leap_year = true;
	}

	bool invalid_Month = false;
	if (input_Month == "January")
	{
		if (leap_year == true)
		{
			month_code = 0;
		}
		else if (leap_year == false)
		{
			month_code = 1;
		}
	}
	else if (input_Month == "February")
	{
		if (leap_year == true)
		{
			month_code = 3;
		}
		else if (leap_year == false)			// month code calculation
		{
			month_code = 4;
		}
	}
	else if (input_Month == "March")
		month_code = 4;
	else if (input_Month == "April")
		month_code = 0;
	else if (input_Month == "May")
		month_code = 2;
	else if (input_Month == "June")
		month_code = 5;
	else if (input_Month == "July")
		month_code = 0;
	else if (input_Month == "August")
		month_code = 3;
	else if (input_Month == "September")
		month_code = 6;
	else if (input_Month == "October")
		month_code = 1;
	else if (input_Month == "November")
		month_code = 4;
	else if (input_Month == "December")
		month_code = 6;
	else
	{
		invalid_Month = true;
		cout << "Invalid month!" << endl;										// ensures Invalid Month! is printed given that the month typed by the user is invalid
		return(0);
	}

	bool invalid_Day = false;
	if ((invalid_Month == false) && ((input_Day < 1) || (input_Day > 31)))		//fixes invalid output precedence			
	{
		invalid_Day = true;
		cout << "Invalid day!";
		return(0);
	}
	else if ((invalid_Month == false) && (invalid_Day == false) && ((input_Year < 1) || (input_Year > 3000)))
	{
		cout << "Invalid year!"<<endl;
		return(0);
	}
	else
	{
		century_value = ((input_Year / 100) % 4);
		if (century_value == 0)
			century_code = -2;
		else if (century_value == 1)
			century_code = 3;
		else if (century_value == 2)																// century code calculation
			century_code = 1;
		else if (century_value == 3)
			century_code = -1;
		else
		{
			;
		}

		year_code = (((input_Year % 100) / 4) + (input_Year % 100));							// year code calculation

		day_code = ((century_code + input_Day + year_code + month_code) % 7);
		if (day_code == 0)
		{
			day_of_the_week = "Sunday";
		}
		if ((day_code == 1) || (day_code == -6))
		{
			day_of_the_week = "Monday";												// day code calculation
		}
		if ((day_code == 2) || (day_code == -5))
		{
			day_of_the_week = "Tuesday";
		}
		if ((day_code == 3) || (day_code == -4))
		{
			day_of_the_week = "Wednesday";
		}
		if ((day_code == 4) || (day_code == -3))
		{
			day_of_the_week = "Thursday";
		}
		if ((day_code == 5) || (day_code == -2))
		{
			day_of_the_week = "Friday";
		}
		if ((day_code == 6) || (day_code == -1))
		{
			day_of_the_week = "Saturday";
		}
		else
		{
			;
		}
		cout << input_Month << " " << input_Day << ", " << input_Year << " was a " << day_of_the_week << "!"<<endl;
		return(0);
	}
}