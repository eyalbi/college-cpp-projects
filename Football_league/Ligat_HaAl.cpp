#include "Ligat_HaAl.h"
Ligat_HaAl::Ligat_HaAl()      //ctor
{
	srand(time(NULL));
	string names[17] = { "eyal","omer","rotem","tal","ben","netanel","gargir","shay","ella","tamar","ruth","dogi","shiran","shahar","yoni","maayan","gal" };
	string ids[17] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17" };
	string ids2[17] = { "18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34" };
	string ids3[17] = { "35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51" };
	string ids4[17] = { "52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68" };
	string ids5[17] = { "69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85" };
	string refid[4] = { "308200203","408200203","508200203","608200203" };
	League = new Team*[5];
	for (int i = ZERO; i < 5; i++) {
		League[i] = new Team;
	}
	League[ZERO]->BuildTeam(names, ids);
	League[1]->BuildTeam(names, ids2);
	League[2]->BuildTeam(names, ids3);
	League[3]->BuildTeam(names, ids4);
	League[4]->BuildTeam(names, ids5);
	EmployessAmount = 5 * 17;
	Referee ** temprefs = new Referee*[4];
	Employees = new Worker*[EmployessAmount];
	int seniority, tmistake;
	int lname, fname, i;
	for (i = ZERO; i < 4; i++) {
		seniority = rand() % 5;
		tmistake = rand() % 7;
		lname = rand() % 17;
		fname = rand() % 17;
		temprefs[i] = new Referee(names[fname], names[lname], refid[i], seniority, tmistake);
		Employees[i] = &(*(temprefs[i]));
	}
	for (int j = ZERO; j < 5; j++) {
		for (int k = ZERO; k < 15; k++) {
			Employees[i++] = &(*(League[j]->Players[k]));
		}
		Employees[i++] = &(*(League[j]->coach));
		Employees[i++] = &(*(League[j]->manager));
	}
	int k = ZERO;
	Fixtures = new Game*[20];
	for (int i = ZERO; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			int tempref = rand() % 4;
			switch (tempref)
			{
			default:
				break;
			case 0:
				Fixtures[k] = new Game;
				Fixtures[k++]->buildGame(*League[i], *League[j], *temprefs[1], *temprefs[2], *temprefs[3]);
				temprefs[1]->GamesUpdate();
				temprefs[2]->GamesUpdate();
				temprefs[3]->GamesUpdate();
				Fixtures[k] = new Game;
				Fixtures[k++]->buildGame(*League[j], *League[i], *temprefs[1], *temprefs[2], *temprefs[3]);
				temprefs[1]->GamesUpdate();
				temprefs[2]->GamesUpdate();
				temprefs[3]->GamesUpdate();
				break;
			case 1:
				Fixtures[k] = new Game;
				Fixtures[k++]->buildGame(*League[i], *League[j], *temprefs[0], *temprefs[2], *temprefs[3]);
				temprefs[ZERO]->GamesUpdate();
				temprefs[2]->GamesUpdate();
				temprefs[3]->GamesUpdate();
				Fixtures[k] = new Game;
				Fixtures[k++]->buildGame(*League[j], *League[i], *temprefs[ZERO], *temprefs[2], *temprefs[3]);
				temprefs[ZERO]->GamesUpdate();
				temprefs[2]->GamesUpdate();
				temprefs[3]->GamesUpdate();
				break;
			case 2:
				Fixtures[k] = new Game;
				Fixtures[k++]->buildGame(*League[i], *League[j], *temprefs[ZERO], *temprefs[1], *temprefs[3]);
				temprefs[ZERO]->GamesUpdate();
				temprefs[1]->GamesUpdate();
				temprefs[3]->GamesUpdate();
				Fixtures[k] = new Game;
				Fixtures[k++]->buildGame(*League[j], *League[i], *temprefs[ZERO], *temprefs[1], *temprefs[3]);
				temprefs[ZERO]->GamesUpdate();
				temprefs[1]->GamesUpdate();
				temprefs[3]->GamesUpdate();
				break;
			case 3:
				Fixtures[k] = new Game;
				Fixtures[k++]->buildGame(*League[i], *League[j], *temprefs[ZERO], *temprefs[1], *temprefs[2]);
				temprefs[ZERO]->GamesUpdate();
				temprefs[1]->GamesUpdate();
				temprefs[2]->GamesUpdate();
				Fixtures[k] = new Game;
				Fixtures[k++]->buildGame(*League[j], *League[i], *temprefs[ZERO], *temprefs[1], *temprefs[2]);
				temprefs[ZERO]->GamesUpdate();
				temprefs[1]->GamesUpdate();
				temprefs[2]->GamesUpdate();
				break;
			}
			
		}
	}
}

Ligat_HaAl::~Ligat_HaAl() //dtor
{
	for (int i = ZERO; i < 5; i++) {
		delete League[i];
	}
	delete[]League;
	for (int i = ZERO; i < 20; i++) {
		delete Fixtures[i];
	}
	delete[] Fixtures;
	for (int i = ZERO; i < EmployessAmount; i++) {
		delete Employees[i];
	}
	delete Employees;
}
bool Ligat_HaAl::checkid(int index, const string&id)      //check if there is a worker in the workers array with given id
{
	if (index == ZERO) {
		return false;
	}
	for (int i = ZERO; i < index; i++) {
		if (Employees[i]->Id == id) {
			return true;
		}
	}
	return false;
}
void Ligat_HaAl::Menu()   //menu with all the option for the league
{
	string tempTeamName;
	string Tid;
	//int team1goal, team2goal, team3goal, team4goal, team5goal;
	int Choice;
	cout << "welcome to La Liga !" << endl;
	do {
		cout << "1.Add Footballer\n2.Add Referee\n3.Print Team details\n4.Print Referee details\n5.Print Future games detailes" << endl;
		cout << "6.Print Worker Salary\n7.Add Goal\n8.Add judgment Errors\n9.Print outstanding pepole\n10.Print table\n11.Print footballer details with smallest salary" << endl;
		cout << "12.Exit" << endl;
		cin >> Choice;
		string lname, fname, id;
		int prole;
		Role temp1;
		int seniority;
		int team;
		int index = ZERO;
		switch (Choice)
		{
		default:
			cout << "invalid input try agian !" << endl;
			break;
		case 1: {
			do {
				if (index > ZERO) {
					cout << "invalid input try agian" << endl;
				}
				cout << "1." << League[ZERO]->TeamName << endl;
				cout << "2." << League[1]->TeamName << endl;
				cout << "3." << League[2]->TeamName << endl;
				cout << "4." << League[3]->TeamName << endl;
				cout << "5." << League[4]->TeamName << endl;
				cin >> team;
				index++;
			} while (team < 1 || team >5);
			cout << "enter player first name" << endl;
			cin >> fname;
			cout << "enter player last name" << endl;
			cin >> lname;
			cout << "enter player id" << endl;
			cin >> id;
			if (checkid(EmployessAmount, id) == true) {
				cout << "an employee with this id allready exists !" << endl;
				break;
			}
			else {
				cout << "enter player seniority" << endl;
				cin >> seniority;
				cout << "1.Goalkeeper\n2.defender\n3.Back\n4.Midfielder\n5.Forward\n(enter a number 1-5)" << endl;
				cin >> prole;
				switch (prole)
				{
				default:
					cout << "invalid role" << endl;
					break;
				case 1:
					temp1 = Goalkeeper;
					break;
				case 2:
					temp1 = defender;
					break;
				case 3:
					temp1 = Back;
					break;
				case 4:
					temp1 = Midfielder;
					break;
				case 5:
					temp1 = Forward;
					break;
				}
				int i = 5;
				Worker ** temp = Employees;
				Footballer* player = new Footballer(fname, lname, id, seniority, League[team - 1]->TeamName, temp1, ZERO);
				*League[team - 1] += player;
				EmployessAmount += 1;
				Employees = new Worker*[EmployessAmount];
				for (i = ZERO; i < EmployessAmount - 1; i++) {
					Employees[i] = &(*temp[i]);
				}
				Employees[i] = &(*player);
				
			}
			break;
		}
		case 2: {
			cout << "Enter referee data please\nEnter referee first name" << endl;
			cin >> fname;
			cout << "Enter referee last name" << endl;
			cin >> lname;
			cout << "Enter referee id" << endl;
			cin >> id;
			if (checkid(EmployessAmount, id) == true) {
				cout << "an employee with this id allready exists !" << endl;
				break;
			}
			else {
				cout << "Enter referee seniority" << endl;
				cin >> seniority;
				Referee* tempref = new Referee(fname, lname, id, seniority, ZERO);
				int i;
				Worker ** temp = Employees;
				EmployessAmount += 1;
				Employees = new Worker*[EmployessAmount];
				for (i = ZERO; i < EmployessAmount - 1; i++) {
					Employees[i] = &(*temp[i]);
				}
				Employees[i] = &(*tempref);
			}
			break;
		}
		case 3: {
			int teamTemp;
			int index1 = ZERO;
			do {
				if (index1 > ZERO) {
					cout << "invalid index try again" << endl;
				}
				cout << "witch team do you want to see\n1." << League[ZERO]->TeamName << endl;
				cout << "2." << League[1]->TeamName << endl;
				cout << "3." << League[2]->TeamName << endl;
				cout << "4." << League[3]->TeamName << endl;
				cout << "5." << League[4]->TeamName << endl;
				cout << "(enter index between 1-5)" << endl;
				cin >> teamTemp;
				index1++;
			} while (teamTemp < 1 || teamTemp > 5);
			League[teamTemp - 1]->Print();
			break;
		}
		case 4: {
			int i, j, k, index2;
			for (i = ZERO; i < EmployessAmount; i++) {
				Referee * temp = dynamic_cast<Referee*>(Employees[i]);
				if (temp) {
					index2 = ZERO;
					temp->Print();
					cout << "Games refereed: " << endl;
					for (k = ZERO; k < 20; k++) {
						for (j = ZERO; j < 3; j++) {
							if (temp->Id == Fixtures[k]->Refs[j]->Id) {
								Fixtures[k]->date->PrintDate();
								cout << Fixtures[k]->Team1->TeamName << " vs " << Fixtures[k]->Team2->TeamName << endl;
								index2++;
							}
						}
					}
					if (index2 == ZERO) {
						cout << "this refeere didnt refereed any game" << endl;
					}
				}
			}
			break;
		}
		case 5: {
			int day, month, year = 2019;
			cout << "Enter a date to check upcomings games(the year is 2019)" << endl;
			cout << "lets start with a day(enter number between 1- 31)" << endl;
			cin >> day;
			cout << "Enter a month" << endl;
			cin >> month;
			int i, j = 1;
			for (i = ZERO; i < 20; i++) {
				if (Fixtures[i]->date->month > month) {
					cout << "Game " << j++ << ": " << endl;
					Fixtures[i]->Print();
				}
				else if (Fixtures[i]->date->month == month) {
					if (Fixtures[i]->date->day > day) {
						cout << "Game " << j++ << ": " << endl;
						Fixtures[i]->Print();
					}
				}
			}
			break;
		}
		case 6: {
			//string Tid;
			cout << "Enter id to get worker salary" << endl;
			cin >> Tid;
			for (int i = ZERO; i < EmployessAmount; i++) {
				if (Employees[i]->Id == Tid) {
					cout << Employees[i]->ReturnSalary() << endl;
				}
			}
			break;
		}
		case 7: {
			int game;
			//string Tid;
			cout << "choose a game to add goal please" << endl;
			for (int i = ZERO; i < 20; i++) {
				cout << i + 1 << ": " << Fixtures[i]->Team1->TeamName << " vs " << Fixtures[i]->Team2->TeamName << endl;
			}
			cout << "enter a desire game number" << endl;
			cin >> game;
			while (game < 1 || game > 20) {
				cout << "try again" << endl;
				cin >> game;
			}
			cout << "Enter goal scoring player id" << endl;
			cin >> Tid;
			Fixtures[game - 1]->GoalUpdate(Tid);
			if (Fixtures[game - 1]->Team1->PlayersAmount > 15 || Fixtures[game - 1]->Team2->PlayersAmount > 15){
				for (int i = ZERO; i < EmployessAmount; i++) {
					if (Employees[i]->Id == Tid) {
						Footballer* temp = dynamic_cast <Footballer*>(Employees[i]);
						temp->Goal();
					}
				}
			}	
			break;
		}
		case 8: {
			//string Tid;
			cout << "Enter Referee id" << endl;
			cin >> Tid;
			for (int i = ZERO; i < EmployessAmount; i++) {
				if (Employees[i]->Id == Tid) {
					Referee *temp = dynamic_cast<Referee*>(Employees[i]);
					if (temp) {
						int mistake;
						cout << "Enter mistakes amount" << endl;
						cin >> mistake;
						temp->AddMistakes(mistake);
					}
					else
					{
						cout << "this id belong to a worker who is not a referee" << endl;
						break;
					}
				}
			}
			break;
		}
		case 9: {
			for (int i = ZERO; i < EmployessAmount; i++) {
				if (Employees[i]->checkspecial() == true) {
					Referee * ref = dynamic_cast <Referee*>(Employees[i]);
					if (ref) {
						ref->Print();
						cout << "Mistakes amount: " << ref->Mistakes << endl;
						continue;
					}
					Footballer * player = dynamic_cast <Footballer*>(Employees[i]);
					if (player) {
						player->Print();
						continue;
					}
					Coach* head = dynamic_cast <Coach*>(Employees[i]);
					if (head) {
						head->Print();
						if (head->FormerPlayer == true) {
							cout << "the coach is a former player" << endl;
						}
						else {
							cout << "the coach isn't a former player" << endl;
						}
						cout << "championships: " << head->Championships << endl;
						continue;
					}
					Manager * mang = dynamic_cast <Manager*>(Employees[i]);
					if (mang) {
						mang->Print();
						continue;
					}
				}
			}
			break;
		}
		case 10: {
			int team1points = ZERO, team2points = ZERO, team3points = ZERO, team4points = ZERO, team5points = ZERO;
			for (int i = ZERO; i < 20; i++) {
				if (Fixtures[i]->winners != "Tie") {
					if (Fixtures[i]->winners == League[ZERO]->TeamName) {
						team1points += 3;
					}
					if (Fixtures[i]->winners == League[1]->TeamName) {
						team2points += 3;
					}
					if (Fixtures[i]->winners == League[2]->TeamName) {
						team3points += 3;
					}
					if (Fixtures[i]->winners == League[3]->TeamName) {
						team4points += 3;
					}
					if (Fixtures[i]->winners == League[4]->TeamName) {
						team5points += 3;
					}
				}
				else {
					tempTeamName = Fixtures[i]->Team1->TeamName;
					if (tempTeamName == League[ZERO]->TeamName) {
						team1points++;
					}
					if (tempTeamName == League[1]->TeamName) {
						team2points++;
					}
					if (tempTeamName == League[2]->TeamName) {
						team3points++;
					}
					if (tempTeamName == League[3]->TeamName) {
						team4points++;
					}
					if (tempTeamName == League[4]->TeamName) {
						team5points++;
					}
					tempTeamName = Fixtures[i]->Team2->TeamName;
					if (tempTeamName == League[ZERO]->TeamName) {
						team1points++;
					}
					if (tempTeamName == League[1]->TeamName) {
						team2points++;
					}
					if (tempTeamName == League[2]->TeamName) {
						team3points++;
					}
					if (tempTeamName == League[3]->TeamName) {
						team4points++;
					}
					if (tempTeamName == League[4]->TeamName) {
						team5points++;
					}
				}
			}
			int points[5] = { team1points,team2points,team3points,team4points,team5points };
			int leaders = points[ZERO];
			int Lindex = ZERO;
			int i;
			for (i = 1; i < 5; i++) {
				if (points[i] > leaders) {
					leaders = points[i];
					Lindex = i;
				}
			}
			cout << League[ZERO]->TeamName << " points: " << points[ZERO] << endl;
			cout << League[1]->TeamName << " points: " << points[1] << endl;
			cout << League[2]->TeamName << " points: " << points[2] << endl;
			cout << League[3]->TeamName << " points: " << points[3] << endl;
			cout << League[4]->TeamName << " points: " << points[4] << endl;

			cout << "leagues leaders is : " << League[Lindex]->TeamName << endl;;
			break;
		}
		case 11: {
			int i;
			float temp_salary;
			for (i = ZERO; i < EmployessAmount; i++) {
				Footballer* temp = dynamic_cast<Footballer*>(Employees[i]);
				if (temp) {
					temp_salary = temp->ReturnSalary();
					i++;
					break;
				}
			}
			for (; i < EmployessAmount; i++) {
				Footballer* temp = dynamic_cast<Footballer*>(Employees[i]);
				if (temp) {
					if (temp->ReturnSalary() < temp_salary) {
						temp_salary = temp->ReturnSalary();
					}
				}
			}
			for (i = ZERO; i < EmployessAmount; i++) {
				Footballer* temp = dynamic_cast<Footballer*>(Employees[i]);
				if (temp) {
					if (temp->ReturnSalary() == temp_salary) {
						temp->Print();
					}
				}
			}
			break;
		}
		case 12:
			cout << "have a nice day" << endl;
			break;
	}
}while (Choice != 12);






}