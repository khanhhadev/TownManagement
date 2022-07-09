#include "Source.h"

//Add new holdhouse to town database
void addNewTown()
{
	int houseHoldNum;
	cout << "\nEnter number of household that you want to add: ";	
	fflush(stdin);
	cin >> houseHoldNum;

	for (int houseIndex = 0; houseIndex < houseHoldNum; houseIndex++)
	{
		int houseNum, peopleNum = 0;
		fflush(stdin);
		cout << "\nEnter house number of household number " << houseIndex + 1 << " : ";
		cin >> houseNum;
		Town* TownPtr = Town::findHomeInfor(houseNum);

		//Check if housenum is exist, if not, create new household
		if (TownPtr == nullptr)
		{
			fflush(stdin);
			cout << "\nEnter number of people are there in household number " << houseIndex + 1 << " : ";
			cin >> peopleNum;
			TownPtr = new Town(houseNum, peopleNum);
			Town::myhometown.push_back(TownPtr);
		}

		for (int PeopleIndex = 0; PeopleIndex < peopleNum; PeopleIndex++)
		{
			TownPtr->addNewOne();
		}
	}
}

//find holdhouse information by person ID number
void findbyID()
{
	string ID;
	cout << "\nEnter ID number of people that you want to search: ";
	fflush(stdin);
	getline(cin, ID);
	Human* HumanPtr = Human::findPeopleInfor(ID);
	if (HumanPtr == nullptr) cout << "\nPeople not found!";
	else
	{
		cout << *(HumanPtr->getHouse());
	}
};

//find holdhouse information by address
void findbyAddress()
{
	int HouseNum;
	cout << "\nEnter House number that you want to search: ";	
	fflush(stdin);
	cin >> HouseNum;
	Town* TownPtr = Town::findHomeInfor(HouseNum);
	if (TownPtr == nullptr) cout << "\nHouse number not found!";
	else cout << *TownPtr;

};

//show all holdhouses information in the town
void showAllHome()
{
	cout << "\nAll information of " << Town::householdcount << " household in town are below:";
	for (Town* townIndex : Town::myhometown)
	{
		cout << *townIndex;
	}
};