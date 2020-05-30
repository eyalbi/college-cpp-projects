#include "game1.h"

int Game::Cows()const
{
	int cows = ZERO;
	for (int i = ZERO; i < 4; i++) {
		for (int j = ZERO; j < 4; j++) {
			if (i != j && (computer->number)[i].value == (user->number)[j].value) {
				cows++;
			}
		}
	}
	return cows;
}

int Game::Bulls() const
{
	int bulls = ZERO;
	for (int i = ZERO; i < 4; i++) {
		if ((computer->number)[i].value == (user->number)[i].value) {
			bulls++;
		}

	}
	return bulls;
}

Game::Game()
{
	user = new Number;
	computer = new Number;
	computer->randomise();
	user->EnterValue();
}

Game::Game(const Game & obj)
{
	if (user == NULL && computer == NULL) {
		user = new Number;
		computer = new Number;
	}
	else
	{
		delete user;
		delete computer;
		user = new Number;
		computer = new Number;
	}
	for (int i = 0; i < 4; i++)
	{
		(user->number)[i].Set_Digit((obj.user)->number[i].Get_Digit());
		(computer->number)[i].Set_Digit((obj.computer)->number[i].Get_Digit());
	}
}

void Game::play()
{														
	char str;
	do
	{


		cout << "Number   B   C\n" << "---------------" << endl;
		while (this->CheckWin() == false) {
			this->PrintUser();
			cout << "    " << this->Bulls() << "   " << this->Cows() << endl;
			this->Set_user();
		}
		cout << "************\nYOU WIN !!!\n************" << endl;
		cout << "new game? Y/N" << endl;
		cin >> str;
		if (str != 'y') {
			cout << "have a good day" << endl;
		}
		else {
			this->Set_user();
		}
	}while (str == 'y');
}

bool Game::CheckWin() const
{
	for (int i = ZERO; i < 4; i++) {
		if ((computer->number)[i].value != (user->number)[i].value) {
			return false;
		}
	}
	return true;
}

void Game::PrintUser() const
{
	user->PrintNumber();
}

void Game::Set_user()
{
	user->EnterValue();
}



