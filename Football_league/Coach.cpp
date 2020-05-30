#include "Coach.h"

Coach::Coach(const Coach &temp)       //cctor
{
	this->Fname = temp.Fname;
	Lname = temp.Lname;
	Id = temp.Id;
	Teamname = temp.Teamname;
	Veteck = temp.Veteck;
	FormerPlayer = temp.FormerPlayer;
	Championships = temp.Championships;


}

float Coach::ReturnSalary() const  //coach salary
{
	return (float)4500 + 200*Veteck + 500 *Championships;
}

bool Coach::checkspecial() const        //check if coach is a special worker
{
	if (Championships >= 2) {
		return true;
	}
	return false;
}

void Coach::Print() const        //print coach data
{
	cout << "coach: " << endl;
	Worker::Print();
	cout << "team: " << Teamname << endl;
	



}
