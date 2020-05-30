#include "Game.h"

class Ligat_HaAl {    //league class with team array games array and workers array
private:
	Team ** League;
	Game ** Fixtures;
	Worker** Employees;
	int EmployessAmount;
public:
	Ligat_HaAl();
	~Ligat_HaAl();
	void Menu();
	bool checkid(int index,const string&id);

};