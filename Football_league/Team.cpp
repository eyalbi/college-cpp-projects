#include "Team.h"



Team::~Team()     //dtor
{
	for (int i = ZERO; i < PlayersAmount; i++) {
		delete Players[i];
	}
	delete[] Players;
	delete stadium;
	delete coach;
	delete manager;

}

void Team::BuildTeam(string names[], string ids[])    //build team with 15 players manager and coach with a givvens names and ids array
{
	srand(time(NULL));
	PlayersAmount = 15;
	bool former;
	int i = ZERO;
	string tempid;
	int coachChampion;
	int size, seniority;
	Role temp;
	string Sname, city;
		cout << "Please enter Team's name" << endl;
		getline(cin,TeamName) ;
		cout << "please enter the Team's home city" << endl;
		getline(cin, city);
		cout << "please enter stadium name" << endl;
		getline(cin, Sname);
		cout << "please enter stadium capacity" << endl;
		cin >> size;
		getchar();
		stadium = new Stadium(Sname, city, size);
		Players = new Footballer*[PlayersAmount];
		temp = Goalkeeper;
		seniority = rand() % 5 + 1;
		Players[i] = new Footballer(names[i], names[i], ids[i], seniority, TeamName, temp, ZERO);
		for (i = 1; i < 2; i++) {
			seniority = rand() % 5 + 1;
			if (checkId(i, ids[i]) == true) {
				tempid = (char)rand() % 1000;
				Players[i] = new Footballer(names[i], names[i], tempid, seniority, TeamName, temp, ZERO);
			}
			else {
				Players[i] = new Footballer(names[i], names[i], ids[i], seniority, TeamName, temp, ZERO);

			}
		}
		temp = Forward;
		for (; i < 5; i++) {
			seniority = rand() % 5 + 1;
			if (checkId(i, ids[i]) == true) {
				tempid = (char)rand() % 1000;
				Players[i] = new Footballer(names[i], names[i], tempid, seniority, TeamName, temp, ZERO);
			}
			else {
				Players[i] = new Footballer(names[i], names[i], ids[i], seniority, TeamName, temp, ZERO);
			}
			
		}
		temp = Midfielder;
		for (; i < 9; i++) {
			seniority = rand() % 5 + 1;
			if (checkId(i, ids[i]) == true) {
				tempid = (char)rand() % 1000;
				Players[i] = new Footballer(names[i], names[i], tempid, seniority, TeamName, temp, ZERO);
			}
			else {
				Players[i] = new Footballer(names[i], names[i], ids[i], seniority, TeamName, temp, ZERO);
			}
			
		}
		temp = Back;
		for (; i < 12; i++) {
			seniority = rand() % 5 + 1;
			if (checkId(i, ids[i]) == true) {
				tempid = (char)rand() % 1000;
				Players[i] = new Footballer(names[i], names[i], tempid, seniority, TeamName, temp, ZERO);
				}
				else {
					Players[i] = new Footballer(names[i], names[i], ids[i], seniority, TeamName, temp, ZERO);
				}
			
		}
		temp = defender;
		for (; i < 15; i++) {
			seniority = rand() % 5 + 1;
			if (checkId(i, ids[i]) == true) {
		   		tempid = (char)rand() % 1000;
				Players[i] = new Footballer(names[i], names[i], tempid, seniority, TeamName, temp, ZERO);
			}
			else {
				Players[i] = new Footballer(names[i], names[i], ids[i], seniority, TeamName, temp, ZERO);
			}
			
		}
		former = rand() % 2;
		coachChampion = rand() % 11;
		seniority = rand() % 5 + 1;
		if (checkId(i, ids[i]) == true) {
			tempid = (char)rand() % 1000;
			coach = new Coach(names[i], names[i], tempid, seniority, TeamName, former, coachChampion);
		}
		else {
			coach = new Coach(names[i], names[i], ids[i], seniority, TeamName, former, coachChampion);
			
		}
		i++;
		
		seniority = rand() % 5 + 1;
		if (checkId(i, ids[i]) == true ) {
			tempid = (char)rand() % 1000;
			manager = new Manager(names[i], names[i], tempid, seniority);
		}
		else {
			manager = new Manager(names[i], names[i], ids[i], seniority);
		}
		managerFlag = true;
		
}


bool Team::checkId(int index, string&id)        //checks if a player with a speciphic id allready exist in the players array
{
	if (index == ZERO) {
		if (Players[ZERO]->Id == id) {
			return true;
		}
		else {
			return false;
		}
	}
	for (int i = ZERO; i < index && i < 15 ; i++) {
		if (Players[i]->Id == id) {
			return true;
		}
	}

	return false;
}

Team & Team::operator+=(Footballer * player)  //add player to the team
{
	if (this->checkId(PlayersAmount, player->Id)) {
		return *this;
	}
	int i;
	Team temp;
	temp.PlayersAmount = PlayersAmount;
	temp.Players = new Footballer*[temp.PlayersAmount];
	for (i = ZERO; i < PlayersAmount; i++) {
		(temp.Players)[i] = new Footballer(*(this->Players)[i]);
	}
	for (i = ZERO; i < PlayersAmount; i++) {
		delete Players[i];
	}
	delete[] Players;
	PlayersAmount = temp.PlayersAmount + 1;
	Players = new Footballer *[PlayersAmount];
	for (i = ZERO; i < temp.PlayersAmount; i++) {
		Players[i] = new Footballer(*((temp.Players)[i]));
	}
	Players[i] = new Footballer(*player);
	return *this;
}

Team & Team::operator+=(Manager* manager)   //add manager to the team
{
	if (this->managerFlag) {
		cout << "this team allready has a manager" << endl;
		return *this;
	}
	if (this->checkId(PlayersAmount, manager->Id) || coach->Id == manager->Id) {
		cout << "this id allready exists" << endl;
		return *this;
	}
	this->manager = new Manager(*manager);
	return *this;
}

Team & Team::operator+=(Coach * tcoach)     //add coach
{
	if (this->coach == NULL) {
		coach = new Coach(*tcoach);
	}
	else {
		cout << "this team allready have a coach" << endl;
	}
	return *this;
}

Footballer * Team::GetPlayer(int index)          //get player pointer
{
	if (index < ZERO || index > PlayersAmount - 1) {
		return nullptr;
	}

	return Players[index];
}

void Team::Print() const              //print team players manager and coach
{
	cout << "Team: \n" << TeamName << endl;
	stadium->print();
	manager->Print();
	coach->Print();
	cout << "Team players: \n";
	for (int i = ZERO; i < PlayersAmount; i++) {
		cout << i + 1 << ".\n";
		Players[i]->Print();
	}
}

