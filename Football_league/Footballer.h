#include "Worker.h"
typedef enum {Goalkeeper,defender,Back,Midfielder,Forward} Role;

class Footballer :public Worker {   // a inherited class from person has a team name,role,goal and games amount extra data
private:
	string TeamName;
	Role PRole;
	int ScoreAmount;
	const int Games;
public:
	Footballer():Worker(), TeamName('\0'), ScoreAmount(ZERO),Games(8){};
	Footballer(string name, string surname, string id, int TVeteck, string Team, Role temp, int score):Worker(name, surname,id,TVeteck), Games(8), ScoreAmount(score), TeamName(Team), PRole(temp) {};
	Footballer(const Footballer&) ;
	~Footballer();
	void Print()const;
	float SuccessRate()const;
	float ReturnSalary()const;
	bool checkspecial()const;
	void Goal() { ScoreAmount++; };
	friend class Ligat_HaAl;
	friend class Game;






};
