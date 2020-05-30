#include "Stadium.h"


class Team {       //team class team name stadiom pointer players array and size cocach and manger pointers and manger flag
private:
	string TeamName;
	Stadium* stadium;
	Footballer** Players;
	int PlayersAmount;
	Coach* coach;
	Manager* manager;
	bool managerFlag;
public:
	Team() :stadium(NULL), Players(NULL), PlayersAmount(ZERO), coach(NULL), manager(NULL), managerFlag(false) {};
	~Team();
	void BuildTeam(string names[], string ids[]);
	bool checkId(int index,string & id);
	Team& operator +=(Footballer* player);
	Team& operator +=(Manager* manager);
	Team& operator +=(Coach* coach);
	Footballer* GetPlayer(int index);
	void Print()const;
	string GetTeamname() { return TeamName; };
	friend class Game;
	friend class Ligat_HaAl;

};
