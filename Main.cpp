#include "Source.h"


int main()
{
	//list<Town*>& MyHomeTown = Town::MyHomeTown;

	while (true)
	{
		int number;
		cout << "\n\nEnter number of function that you want to choose:"
			<< endl << "1. Add new household"
			<< endl << "2. Find household information by human name"
			<< endl << "3. Find household information by address"
			<< endl << "4. Show all household information"
			<< endl << "0. End program"
			<< endl << "Function: "; 
		fflush(stdin);
		cin >> number;

		switch (number)
		{
			case 1:
			{
				addNewTown();
			}
				break;
			case 2:
			{
				findbyID();
			}
				break;
			case 3:
			{
				findbyAddress();
			}
			break; 
			case 4:
			{
				showAllHome();
			}
			break;
			case 0:
			{
				return 0; 
			}
				break;
			default:
			{
				cout << "Invalid input";
			}
				break;
		}
		cout << "\n";
	}
	return 0;
}