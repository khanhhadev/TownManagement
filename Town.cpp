#include "Town.h"
#include "Human.h"

int Town::householdcount = 0;
list<Town*> Town::myhometown;

Town::Town()
{
	householdcount++;
};

Town::Town(int HouseNum, int PeopleNum):m_housenum(HouseNum), m_peoplenum(PeopleNum)
{
	householdcount++;
};

//find household in town by house number, if have, return address of Town objects, if not, return nullptr
Town* Town::findHomeInfor(int houseNum)
{
	for (Town* House : myhometown)
	{
		if (House->m_housenum == houseNum) return House;
	} 
	return nullptr;
}

//information list of household members
void Town::addNewOne()
{
		string ID, Name, Job;
		int Year;

		fflush(stdin);
		cout << "Enter ID number of people number : ";
		getline(cin, ID);

		Human* HumanPtr = Human::findPeopleInfor(ID);

		if (HumanPtr == nullptr)
		{
			fflush(stdin);
			cout << "\nEnter name of people number : ";
			getline(cin, Name);

			fflush(stdin);
			cout << "\nEnter birth year of people number : ";
			cin >> Year;

			cout << "Enter job of people number : ";
			fflush(stdin);
			getline(cin, Job);
			HumanPtr = new Human(ID, Name, Year, Job, this);
			(myhometown.back()->m_listpeople).push_back(HumanPtr);
		}
};

//output Town object information
ostream& operator<<(ostream& output, const Town& town)
{
	output << "\nHouse number: " << town.m_housenum;
	output << "\nNumber of people: " << town.m_peoplenum;
	int i = 0;
	for (Human* humanIndex : town.m_listpeople)
	{
		cout << "\nInfor of family member number " << ++i;
		cout << *humanIndex;
	}
	return output;
};