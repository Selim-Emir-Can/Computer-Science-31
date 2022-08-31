#include<iostream>
#include<string>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include <cctype>
using namespace std;

int extractNumber(string commands, size_t& index, bool& isValid);
bool isValidResultString(string results);
int positiveTests(string results);
int negativeTests(string results);
int totalTests(string results);
int batches(string results);

int main()
{
	cout.setf(ios::boolalpha);
	cout << "Enter the COVID-19 test results: ";
	string Test;

	getline(cin, Test);
	cout << "The COVID-19 test results you entered ";
	isValidResultString(Test);

	if (isValidResultString(Test) == true)
		{
			cout << "were valid." << endl << "isValidResultString output: " << isValidResultString(Test)
				<< endl << "positiveTests output: " << positiveTests(Test) << endl << "negativeTests output: "
				<< negativeTests(Test) << endl << "totalTests ouput: " << totalTests(Test) << endl
				<< "batches output: " << batches(Test);
		}
		else
		{
			cout << "were not valid" << endl << "isValidResultString output: " << isValidResultString(Test)
				<< endl << "positiveTests output: " << positiveTests(Test) << endl << "negativeTests output: "
				<< negativeTests(Test) << endl << "totalTests ouput: " << totalTests(Test) << endl
				<< "batches output: " << batches(Test);
		}
		return(0);
}














bool isValidResultString(string results)		// Precondition: need a string for an input
{												// Postcondition: outputs true if the string is valid and outputs false if the string is not valid
	bool True = true;
	int totalCases_Batch = 0, totalCases = 0, totalNegativeResults = 0, totalPositiveResults = 0, positiveResults_Batch = 0, negativeResults_Batch = 0, numberOfRs = 0, numberOfplus = 0, numberOfminus = 0;
	int size = results.size();
	if (results.size() < 6)
	{
		return(false);
	}
	if (!isdigit(results[size - 1]))	// STRING MUST START WITH AN R AND END WITH A DIGIT
	{
		return(false);
	}
	if (!(results.at(0) == 'R'))
	{
		return false;
	}

	for (size_t i = 1; i < (results.size() - 1); i++)
	{

		if (isalpha(results[i]))
		{
			if (results.at(i) != 'R')			// NO LETTERS OTHER THAN R ALLOWED
			{
				return(false);
			}

		}

		if (results.at(i) == 'R' || results.at(i) == '+' || results.at(i) == '-')			// -, +, R SYMBOLS MUST HAVE DIGITS BETWEEN THEM
		{
			if (!(isdigit(results[i - 1])))
			{
				return(false);
			}
			if (!(isdigit(results[i + 1])))
			{
				return(false);
			}

		}

		if (results.at(i) == '0' && (results.at(i - 1) == '+' || results.at(i - 1) == '-' || results.at(i - 1) == 'R'))		// NO LEADING ZEROES ALLOWED
		{
			if (isdigit(results[i + 1]))
			{
				return(false);
			}
		}
	}

	for (size_t k = 0; k < (results.size() - 1); k++)          //CHECKS IF THE NUMBERS MAKE SENSE PER BATCH
	{														// ALSO CHECKS IF R, -, AND + SIGNS ARE USED PROPERLY
		if (((numberOfminus - numberOfplus) > 1) || (numberOfplus - numberOfminus) > 1)
		{
			return(false);
		}
		if ((results.at(k) == 'R') && (numberOfRs == numberOfminus) && (numberOfRs == numberOfplus) && (numberOfRs != 0))
		{
			if (totalCases_Batch != (negativeResults_Batch + positiveResults_Batch))
			{
				return(false);
			}
		}
		if (results.at(k) == 'R')
		{
			numberOfRs++;
			k = k + 1;
			totalCases_Batch = extractNumber(results, k, True);
			if (totalCases_Batch == 0)
			{
				return(false);
			}
			totalCases = totalCases + totalCases_Batch;
			k = k - 1;

		}
		if (results.at(k) == '-')
		{
			numberOfminus++;
			k = k + 1;
			negativeResults_Batch = extractNumber(results, k, True);
			totalNegativeResults = totalNegativeResults + negativeResults_Batch;
			k = k - 1;
		}
		if (results.at(k) == '+')
		{
			numberOfplus++;
			k = k + 1;
			positiveResults_Batch = extractNumber(results, k, True);
			totalPositiveResults = totalPositiveResults + positiveResults_Batch;
			k = k - 1;
		}
	}
	if (totalCases != (totalNegativeResults + totalPositiveResults))		// CHECKS IF TOTAL RESULTS MAKE SENSE
	{
		return(false);
	}
	if ((numberOfminus != numberOfplus) || (numberOfRs != numberOfminus))	// CHECKS IF THERE ARE AN EQUAL AMOUNT OF R, -, + SYMBOLS
	{
		return(false);
	}
	return(true);
}























int extractNumber(string commands, size_t& index, bool& isValid)
{																	
	// track the integer value found
	int quantity(0);
	// the number can't start with a zero!
	if (commands.at(index) >= '1' && commands.at(index) <= '9')
	{
		// the number should be made up of digits
		while (index < commands.length() &&
			(commands.at(index) >= '0' && commands.at(index) <= '9'))
		{
			// extract one digit and add it to the cumulative value
			// held in quantity "123" ---> 123
			int digit = commands.at(index) - '0';
			quantity = quantity * 10 + digit;
			index = index + 1;
		}
	}
	// once we run out of digits to consume, the cumulative quantity
	// must not still be zero
	isValid = (quantity != 0);
	return(quantity);
}










int positiveTests(string results)	// precondition: isValidResultString(string results)
{									// postcondition: returns -1 if precondition is false and the total number of positive tests if it is true
	int totalPositiveResults = 0;
	bool execute = isValidResultString(results);
	if (execute == true)
	{
		for (size_t k = 0; k < results.size(); k++)
		{
			if (results.at(k) == '+')
			{
				k++;
				totalPositiveResults = totalPositiveResults + extractNumber(results, k, execute);
			}
		}
		return(totalPositiveResults);
	}
	else
	{
		return(-1);
	}
}








int negativeTests(string results)			// precondition: isValidResultString(string results)
{											// postcondition: returns -1 if precondition is false and the total number of negative tests if it is true
	int totalNegativeResults = 0;
	bool execute = isValidResultString(results);
	if (execute == true)
	{
		for (size_t k = 0; k < results.size(); k++)
		{
			if (results.at(k) == '-')
			{
				k++;
				totalNegativeResults = totalNegativeResults + extractNumber(results, k, execute);
			}
		}
		return(totalNegativeResults);
	}
	else
	{
		return(-1);
	}
}








int totalTests(string results)				//precondition: isValidResultString(string results)
{											// postcondition: returns -1 if precondition is false and the total number of tests if it is true
	int totalResults = 0;
	bool execute = isValidResultString(results);
	if (execute == true)
	{
		for (size_t k = 0; k < results.size(); k++)
		{
			if (results.at(k) == 'R')
			{
				k++;
				totalResults = totalResults + extractNumber(results, k, execute);
			}
		}
		return(totalResults);
	}
	else
	{
		return(-1);
	}
}









int batches(string results)				//precondition: isValidResultString(string results)
{										// postcondition: returns -1 if precondition is false and the total number of batches if it is true
	int totalBatches = 0;
	bool execute = isValidResultString(results);
	if (execute == true)
	{
		for (size_t k = 0; k < results.size(); k++)
		{
			if (results.at(k) == 'R')
			{
				totalBatches++;
			}
		}
		return(totalBatches);
	}
	else
	{
		return(-1);
	}
}

