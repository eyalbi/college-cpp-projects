#include "Referee.h"
int Referee::MaxMistakes = ZERO;
Referee::Referee(const Referee &temp)    //cctor
{
	this->Fname = temp.Fname;
	this->Lname = temp.Lname;
	this->Id = temp.Id;
	this->Mistakes = temp.Mistakes;
	this->Veteck = temp.Veteck;
	Games = 8;
}
float Referee::ReturnSalary() const       //refs salary 
{
	if (Mistakes >= MaxMistakes) {
		if (MaxMistakes < Mistakes) {
			MaxMistakes = Mistakes;
		}
		return (float)4500 + 30 * Games - 500;
	}
	return (float)4500 + 30 * Games;
}

bool Referee::checkspecial() const    //check if a ref is a special worker
{
	if (Mistakes <= 0.5 * MaxMistakes) {
		return true;
	}
	return false;
}

void Referee::AddMistakes(int mistake)      //add mistakes to ref record
{
	Mistakes += mistake;
	if (Mistakes > MaxMistakes) {
		MaxMistakes = Mistakes;
	}


}

bool Referee::checkId(int index, Referee ** refs,string&id)    //check if a ref is include in refs array with id up to specipc index
{
	for (int i = ZERO; i < index; i++) {
		if (refs[i]->Id == id) {
			return true;
		}
	}
	return false;
}
