#pragma once
#include "Human.h"

class Town
{
private:
	int m_peoplenum, m_housenum;

	//information list of household members
	list<Human*> m_listpeople;
public:
	Town();
	Town(int, int);

	//number of households in town
	static int householdcount;

	//information list of households in town
	static list<Town*> myhometown;

	//find household in town by house number, if have, return address of Town objects, if not, return nullptr
	static Town* findHomeInfor(int);

	//information list of household members
	void addNewOne();

	//output print Town object information
	friend ostream& operator<<(ostream& output, const Town& town);

	//friend class Human;
};