#include "Date.h"
class Game {         //a game class with a date teams pointers winners strings and goals data
private:
	Date* date;
	Team* Team1, *Team2;
	string winners;
	int Team1Goals, Team2Goals;
	Referee ** Refs;
public:
	Game() :date(NULL), Team1(NULL), Team2(NULL), winners("Tie"), Team1Goals(ZERO), Team2Goals(ZERO),Refs(NULL){};
	~Game();
	void buildGame(Team& team1,Team& team2,Referee& ref1,Referee& ref2, Referee& ref3);
	void GoalUpdate(string&);
	void UpdateWinners();
	void Print();
	friend class Team;
	friend class Ligat_HaAl;

};
