#include "Footballer.h"

class Coach :public Worker {						// inherited class from worker with team name,former player and champiosships amount data
private:
	string Teamname;						
	bool FormerPlayer;
	int Championships;
public:
	Coach() :Worker(), Championships(ZERO) {};
	Coach(string name, string surname, string id, int TVeteck, string team, bool former, int champion) :Worker(name, surname, id, TVeteck), Teamname(team), FormerPlayer(former), Championships(champion) {};
	Coach(const Coach&);
	~Coach() {};
	float ReturnSalary()const;
	bool checkspecial()const;
	void Print()const;
	friend class Ligat_HaAl;
};
