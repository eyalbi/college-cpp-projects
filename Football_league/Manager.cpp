#include "Manager.h"

Manager::Manager(const Manager &temp)         //cctor
{
	this->Fname = temp.Fname;
	Lname = temp.Lname;
	Id = temp.Id;
	Veteck = temp.Veteck;


}

float Manager::ReturnSalary() const      //manager salary
{
	return (float)4500*3 + Veteck*500;
}

bool Manager::checkspecial() const      //check if manager is a special worker
{
	if (Veteck > 4) {
		return true;
	}
	return false;
}

void Manager::Print() const    //prints manager data
{
	cout << "Manager: " << endl;
	Worker::Print();
	
}
