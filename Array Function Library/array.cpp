#include<string>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<cctype>
#include<iostream>
using namespace std;


int locateMaximum(const  string  array[], int  n);
int countFloatingPointValues(const string array[], int  n);
bool hasNoCapitals(const string array[], int n);
bool identicalValuesTogether(const string array[], int n);
bool hasTwoOrMoreDuplicates(const string array[], int  n);
int shiftLeft(string array[], int n, int amount, string placeholder);
int replaceFirstAndLastOccurrences(string array[], int n, char charToFind, char charToReplace);


int main() {
	cout.setf(ios::boolalpha);
	return(0);
}










int locateMaximum(const  string  array[], int  n) // precondition: n must not exceed the actual declared size of the array
{													// postcondition: locates maximum according to the ASCII table, returns the position of the maximum value
	if (n <= 0)
	{
		return(-1);
	}

	string max = array[0];
	int position_of_max = 0;

	for (int i = 0; i < n; i++)					
	{
		if (array[i] > max)
		{
			max = array[i];
			position_of_max = i;

		}
	}
	return(position_of_max);
}












int countFloatingPointValues(const string array[], int  n) // precondition: n must not exceed the actual declared size of the array 
{															// returns the number of floating point values inside the array given
	if (n <= 0)
	{
		return(-1);
	}
	bool notafloatinpointvalue = false;
	int numberoffloatingpointvalues = 0, numberofdecimalpoints = 0, numberofnumbers = 0;
	for (int i = 0; i < n; i++)
	{
		notafloatinpointvalue = false;
		string Array_i = array[i];
		numberofdecimalpoints = 0, numberofnumbers = 0;
		for (size_t k = 0; k < Array_i.size(); k++)
		{
			if (isdigit(Array_i.at(k)))
			{
				numberofnumbers++;
			}
			if (Array_i.at(k) == '.')
			{
				numberofdecimalpoints++;
				if (numberofdecimalpoints > 1)
				{
					notafloatinpointvalue = true;
				}
			}
			else if (!(isdigit(Array_i.at(k))))
			{
				notafloatinpointvalue = true;
			}
		}
		if (numberofnumbers == 0) // && (numberofdecimalpoints == 0) if "." is a floatingpointvalue
		{
			notafloatinpointvalue = true;
		}
		if (notafloatinpointvalue == false)
		{
			numberoffloatingpointvalues++;
		}
	}
	return(numberoffloatingpointvalues);
}













bool hasNoCapitals(const string array[], int n) // precondition: n must not exceed the actual declared size of the array 
{												// postcondition: returns true if there are noCapitals and false if there are Capital letters in the array with a size of n
	if (n <= 0)
	{
		return(true);
	}

	for (int i = 0; i < n; i++)
	{
		string Array_i = array[i];
		for (size_t k = 0; k < Array_i.size(); k++)
		{
			if (isalpha(Array_i.at(k)) && isupper(Array_i.at(k)))
			{
				return(false);
			}
		}
	}
	return(true);
}











bool identicalValuesTogether(const string array[], int n) // precondition: n must not exceed the actual declared size of the array 
{														  // postcondition: if the same strings in the array are not adjacent or n <= 0 it returns false, if identical strings are adjacent it returns true
	if (n <= 0)
	{
		return(false);
	}

	for (int i = 0; i < n; i++)
	{
		string identicalvalue = array[i];		// we assume that we found an identical value every time, 
		for (int k = i + 1; k < n; k++)			//if there is no copy of it, nothing happens, if there is a copy,
		{										//  we check its placement
			if ((array[k] == identicalvalue) && (array[k-1] != identicalvalue))
			{
				return(false);
			}
		}
		
	}
	return(true);
}













bool hasTwoOrMoreDuplicates(const string array[], int  n) // precondition: n must not exceed the actual declared size of the array 
{														// postcondition: returns false if n <= 0 and if there are not at least 3 arrays with the same string  
	if (n <= 0)											//or at least 2 pairs of arrays with each array in a single pair containing the same string (different pairs can
	{													// contain different strings)
		return(false);
	}

	int numberofpairs = 0;
	for (int i = 0; i < n; i++)
	{
		int numberofsamethings = 1;
		string identicalvalue = array[i];
		for (int k = i + 1; k < n; k++)
		{
			if (array[k] == identicalvalue)
			{
				numberofsamethings++;
				if (numberofsamethings == 2) // a pair
				{
					numberofpairs++;
				}
				if (numberofsamethings == 3)		// three of a kind
				{
					return(true);
				}
			}
		}
	}

	if (numberofpairs >= 2)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}











int shiftLeft(string array[], int n, int amount, string placeholder) // precondition: n must not exceed the actual declared size of the array
{																	// postcondition: returns -1 if n <= 0, amount < 0 and shifts the given array to the left by amount and returns amount
	if (n <= 0)
	{
		return(-1);
	}

	if (amount < 0)
	{
		return(-1);
	}

	if (amount == 0)
	{
		return(0);
	}

	if (amount >= n)
	{
		for (int i = 0; i < n; i++)
		{
			array[i] = placeholder;
		}
		return(n);
	}
	string swap = "";
	for (int Amount = amount; Amount > 0; Amount--)
	{
		for (int i = 0; i < n-1; i++)
		{
			swap = array[i + 1];
			array[i] = swap;
		}
		array[n - 1] = placeholder;
	}
	return(amount);
}










int replaceFirstAndLastOccurrences(string array[], int n, char charToFind, char charToReplace) // precondition: n must not exceed the actual declared size of the array
{																								// postcondition: returns -1 if n <= 0 and replaces the first 
	if (n <= 0)																					// and last charToFind and returns the amount of characters changed
	{
		return(-1);
	}

	int numberoftimesreplaced = 0;
	int positioniffirstequalslast = 0;
	bool foundfirstchartofind = false, foundlastchartofind = false;
	for (int i = 0; i < n; i++)
	{
		foundfirstchartofind = false;
		string Array_i = array[i], swap = array[i];
		int size = static_cast<int>(Array_i.size());
		int k = 0;

		while ((k < size) && (foundfirstchartofind == false))
		{
			if (Array_i.at(k) == charToFind)
			{
				positioniffirstequalslast = k;
				swap.at(k) = charToReplace;
				array[i] = swap;
				numberoftimesreplaced++;
				foundfirstchartofind = true;
			}
			k++;
		}

		foundlastchartofind = false;
		int e = size - 1;

		while ((e >= 0) && (foundlastchartofind == false))
		{
			if ((Array_i.at(e) == charToFind) && (e != positioniffirstequalslast))
			{
				swap.at(e) = charToReplace;
				array[i] = swap;
				numberoftimesreplaced++;
				foundlastchartofind = true;
			}
			else if ((Array_i.at(e) == charToFind) && (e == positioniffirstequalslast))
			{
				foundlastchartofind = true;
			}
			e--;
		}

	}
	return(numberoftimesreplaced);
}