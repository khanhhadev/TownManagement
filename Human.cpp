#include "Human.h"
#include "Town.h"

list<Human*> Human::listhuman;

Human::Human() {};
Human::Human(string ID, string Name, int Birthyear, string Job, Town* MyT):m_idcard(ID), m_name(Name), m_birthyear(Birthyear), m_job(Job), m_home(MyT)
{
	listhuman.push_back(this);
};

//find person in town by ID number, if have, return address of Human objects, if not, return nullptr
Human* Human::findPeopleInfor(string ID)
{
	for (auto Person: listhuman)
	{
		if (Person->m_idcard == ID) return Person;
	}
	return nullptr;
};

//return Town object that Person belong to
Town* Human::getHouse() const 
{
	return m_home;
};

//output Person information
ostream& operator<<(ostream& output, const Human& human)
{
	output << "\nID number: " << human.m_idcard;
	output << "\nName: " << human.m_name;
	output << "\nYear of birth: " << human.m_birthyear;
	output << "\nJob: " << human.m_job;
	return output;
}