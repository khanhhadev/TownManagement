#pragma once
#include <iostream>
#include <string>
#include <list>
#include <cstdio>
using namespace std;

class Town;
class Human {
protected:
	string m_idcard, m_name, m_job;
	int m_birthyear;
	Town* m_home;

	//information list of Person in town
	static list<Human*> listhuman;
public:
	Human();
	Human(string ID, string Name, int Birthyear, string Job, Town* MyT);

	//find person in town by ID number, if have, return address of Human objects, if not, return nullptr
	static Human* findPeopleInfor(string ID);

	//return Town object that Person belong to
	Town* getHouse() const;

	//output Person information
	friend ostream& operator<<(ostream& output, const Human& human);

	//friend class Town;
};