#include "Game.h"

Game::~Game()     //dtor
{
	for (int i = ZERO; i < 3; i++) {
		delete Refs[i];
	}
	delete[] Refs;
	delete date;
	delete Team1;
	delete Team2;
}

void Game::buildGame(Team& team1, Team& team2, Referee& ref1, Referee& ref2, Referee& ref3)   //build game with teams and referees
{
	int day, mounth, year;
	srand(time(NULL));
	year = 2019;
	mounth = rand() % 13;
	day = rand() % 32;
	date = new Date(day, mounth, year);
	Team1 = &team1;
	Team2 = &team2;
	Team1Goals = ZERO;
	Team2Goals = ZERO;
	this->UpdateWinners();
	Refs = new Referee*[3];
	Refs[ZERO] = new Referee(ref1);
	Refs[1] = new Referee(ref2);
	Refs[2] = new Referee(ref3);
	
	
	
}

void Game::GoalUpdate(string& Tid)   ///update goal with player id
{
	if (Team1->checkId(Team1->PlayersAmount, Tid)) {
		Team1Goals++;
		for (int i = ZERO; i < Team1->PlayersAmount; i++) {
			if (Team1->Players[i]->Id == Tid) {
				Team1->Players[i]->Goal();
			}
		}
	}
	if (Team2->checkId(Team2->PlayersAmount, Tid)) {
		Team2Goals++;
		for (int i = ZERO; i < Team2->PlayersAmount; i++) {
			if (Team2->Players[i]->Id == Tid) {
				Team2->Players[i]->Goal();
			}
		}
	}
	this->UpdateWinners();


}

void Game::UpdateWinners()     //update winners
{
	if (Team1Goals > Team2Goals) {
		winners = Team1->TeamName;
	}
	else if (Team2Goals > Team1Goals) {
		winners = Team2->TeamName;
	}
	else if (Team1Goals == Team2Goals) {
		winners = "Tie";
	}


}

void Game::Print()      //prints game
{
	date->PrintDate();
	cout << "Game referees is : " << endl;
	for (int i = ZERO; i < 3; i++) {
		cout << "ref " << i + 1 << ":\n";
		Refs[i]->Print();
	}

	cout << "the first team is :\n" << Team1->TeamName << endl;
	cout << "head coach:\n";
	Team1->coach->Print();
	cout << "the second team is :\n" << Team2->TeamName << endl;
	cout << "head coach:\n";
	Team2->coach->Print();
	cout << "Game score :\n" << Team1->TeamName << " " << Team1Goals << " : " << Team2Goals << " " << Team2->TeamName << endl;
	cout << "******************************" << endl;
	cout << "winners: " << winners << endl;
	cout << "******************************" << endl;
}
