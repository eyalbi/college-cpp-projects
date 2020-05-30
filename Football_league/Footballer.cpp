#include "Footballer.h"

Footballer::Footballer(const Footballer &player):Games(8)   //cctor
{
	Fname = player.Fname;
	Lname = player.Lname;
	Id = player.Id;
	Veteck = player.Veteck;
	PRole = player.PRole;
	ScoreAmount = player.ScoreAmount;


}

Footballer::~Footballer()
{
}

void Footballer::Print() const      //print
{
	cout << "Footballer: " << endl;
	Worker::Print();
	cout << "Goals scored: " << ScoreAmount << endl;
	cout << "Success rate: " << SuccessRate() << endl;

}

float Footballer::SuccessRate() const          //player success rate
{
	return (float)ScoreAmount / Games;
}

float Footballer::ReturnSalary() const          //player salary
{
	return 6500 + (SuccessRate() / 100) * 2000;
}

bool Footballer::checkspecial() const					//checks if player is a special worker
{
	if (SuccessRate() > 0.75) {
		return true;
	}
	return false;
}
