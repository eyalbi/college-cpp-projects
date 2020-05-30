#include "Game.h"
int Game::Square_amount = ZERO;
Game::Game(int num)
{
	if (num < 1 || num > 5) {
		Navy = new Battleship;
		Navy_amount = 1;
	}
	else
	{
		Navy = new Battleship[num];
		Navy_amount = num;
	}
	switch (num)
	{
	default:
		Square_amount = 5;
		break;
	case 1:
		Square_amount = 5;
		break;
	case 2:
		Square_amount = 9;
		break;
	case 3:
		Square_amount = 12;
		break;
	case 4:
		Square_amount = 14;
		break;
	case 5:
		Square_amount = 17;
		break;
	}
}

void Game::ClearBoard()
{
	for (int i = ZERO; i < 10; i++) {
		for (int j = ZERO; j < 10; j++) {
			GameBoard[i][j] = '_' ;
		}
	}
}

void Game::PrintBoard()
{
	cout << "    A B C D E F G H I J" << endl;
	for (int i = ZERO; i < 10; i++) {
		if (i != 9) {
			cout << i + 1 << "   ";
			for (int j = 0; j < 10; j++) {
				if (GameBoard[i][j] == 'S') {
					cout << '_' << " ";
				}
				else {
					cout << GameBoard[i][j] << " ";

				}
			}
			cout << "\n";
		}
		else {
			cout << i + 1 << "  ";
			for (int j = 0; j < 10; j++) {
				if (GameBoard[i][j] == 'S') {
					cout << '_' << " ";
				}
				else {
					cout << GameBoard[i][j] << " ";

				}
			}
			cout << "\n";
		}

	}
}

void Game::PrintOriginalBoard()
{
	cout << "    A B C D E F G H I J" << endl;
	for (int i = ZERO; i < 10; i++) {
		if (i != 9) {
			cout << i + 1 << "   ";
			for (int j = 0; j < 10; j++) {
				cout << GameBoard[i][j] << " ";
			}
			cout << "\n";
		}
		else {
			cout << i + 1 << "  ";
			for (int j = 0; j < 10; j++) {
				cout << GameBoard[i][j] << " ";
			}
			cout << "\n";
		}

	}
}
void Game::Play()
{
	BuildBoard();
	int index = ZERO;
	int sub_amount = Navy_amount;
	int hitAMOUNT = ZERO;
	char letter, culomn;
	int row ;
	cout << "do you want a hint Y/N?" << endl;
	cin >> letter;
	if (letter == 'Y' || letter == 'y') {
		this->PrintOriginalBoard();
	}
	do {
		index++;

		this->PrintBoard();
		cout << "enter guess : x y (x = letter,y = number,to exit enter 0 0)" << endl;
		cout <<  "enter culomn letter : ";
		cin >> culomn;
		cout << "enter number: ";
		cin >> row;
		if (row > 0 && row <= 10) {
			switch (culomn)
			{
			default:
				cout << "wrong input try again" << endl;
				break;
			case 'A': 
				if (this->CheckHit(row - 1, a)) {
					if (CheckSunk(row - 1, a)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'a':
				if (this->CheckHit(row - 1, a)) {
					if (CheckSunk(row - 1, a)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'B':
				if (this->CheckHit(row - 1, b)) {
					if (CheckSunk(row - 1, b)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'b':
				if (this->CheckHit(row - 1, b)) {
					if (CheckSunk(row - 1, b)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'C':
				if (this->CheckHit(row - 1, c)) {
					if (CheckSunk(row - 1, c)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'c':
				if (this->CheckHit(row - 1, c)) {
					if (CheckSunk(row - 1, c)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'D':
				if (this->CheckHit(row - 1, d)) {
					if (CheckSunk(row - 1, d)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'd':
				if (this->CheckHit(row - 1, d)) {
					if (CheckSunk(row - 1, d)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'E':
				if (this->CheckHit(row - 1, e)) {
					if (CheckSunk(row - 1, e)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'e':
				if (this->CheckHit(row - 1, e)) {
					if (CheckSunk(row - 1, e)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'F':
				if (this->CheckHit(row - 1, f)) {
					if (CheckSunk(row - 1, f)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'f':
				if (this->CheckHit(row - 1, f)) {
					if (CheckSunk(row - 1, f)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'G':
				if (this->CheckHit(row - 1, g)) {
					if (CheckSunk(row - 1, g)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'g':
				if (this->CheckHit(row - 1, g)) {
					if (CheckSunk(row - 1, g)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'H':
				if (this->CheckHit(row - 1, h)) {
					if (CheckSunk(row - 1, h)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'h':
				if (this->CheckHit(row - 1, h)) {
					if (CheckSunk(row - 1, h)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'I':
				if (this->CheckHit(row - 1, i)) {
					if (CheckSunk(row - 1, i)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'i':
				if (this->CheckHit(row - 1, i)) {
					if (CheckSunk(row - 1, i)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'J':
				if (this->CheckHit(row - 1, j)) {
					if (CheckSunk(row - 1, j)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			case 'j':
				if (this->CheckHit(row - 1, j)) {
					if (CheckSunk(row - 1, j)) {
						cout << "BattleShip sunk !!!" << endl;
						sub_amount--;
					}
				}
				break;
			}
		}
		else {
		cout << "wrong input try again" << endl;
		}

		
	}while (sub_amount > ZERO);
	cout << "WIN!!\n" << "you have played " << index << " rounds" << endl;
	PrintOriginalBoard();

}
bool Game::CheckPlace(int num, int row, int culomn, int SubLenth)
{
	if (check_coordinate(num, row, culomn, SubLenth) == true) {
		if (num == vertical) {
			if (culomn == ZERO) {
				if (check_coordinate(num, row, culomn + 1, SubLenth) == true) {
					return true;
				}
				else {
					return false;
				}
			}
			else if (culomn == 9) {
				if (check_coordinate(num, row, culomn - 1, SubLenth) == true) {
					return true;
				}
				else {
					return false;
				}
			}
			else if (culomn > ZERO && culomn < 9) {
				if (check_coordinate(num, row, culomn - 1, SubLenth) == true && check_coordinate(num, row, culomn + 1, SubLenth) == true) {
					return true;
				}
				else {
					return false;
				}
			}
		}
		else if (num == horizontal) {
			if (row == ZERO) {
				if (check_coordinate(num, row + 1, culomn, SubLenth) == true) {
					return true;
				}
				else {
					return false;
				}

			}
			else if (row == 9) {
				if (check_coordinate(num, row - 1, culomn, SubLenth) == true) {
					return true; 
				}
				else {
					return false;
				}
			}
			else if (row > ZERO && row < 9) {
				if (check_coordinate(num, row - 1, culomn, SubLenth) == true && check_coordinate(num, row + 1, culomn, SubLenth) == true) {
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}

bool Game::check_coordinate(int num, int row, int column, int SubLenth)
{
	int i, j;
	if (num == vertical) {
		if (10 - row < SubLenth) {
			return false;
		}
		if (row == ZERO) {
			for (i = row ; i < SubLenth + 1; i++)
			{
				if (GameBoard[i][column] != '_') {
					return false;
				}
			}
			return true;
		}
		if (row != ZERO) {
			for (i = row - 1; i < row + SubLenth + 1 || i < 10; i++) {
				if (GameBoard[i][column] != '_') {
					return false;
				}
			}
			return true;
		}
	}
	if (num == horizontal) {
		if (10 - column < SubLenth) {
			return false;
		}
		if (column == ZERO) {
			for (j = column; j < SubLenth + 1; j++) {
				if (GameBoard[row][j] != '_') {
					return false;
				}
			}
			return true;
		}
		if(column != ZERO){
			for (j = column - 1; j < column + SubLenth + 1 || j < 10; j++) {
				if (GameBoard[row][j] != '_') {
					return false;
				}
			}
			return true;
		}
	}
}

void Game::BuildBoard()
{
	int i = ZERO, column, row, Kivun,flag;
	this->ClearBoard();
	srand(time(NULL));
	for (i = ZERO; i < Navy_amount; i++) {
		do {
			flag = ZERO;
			column = rand() % 10;
			row = rand() % 10;
			Kivun = rand() % 2;
			
			if (CheckPlace(Kivun, row, column, Navy[i].ShipLenth) == true) {
				if (Kivun == horizontal) {
					flag = 1;
					for (int k = column; k < column + Navy[i].ShipLenth; k++) {
						GameBoard[row][k] = 'S';
					}
				}
				if (Kivun == vertical) {
					int l;
					flag = 1;
					for (l = row; l < row + Navy[i].ShipLenth; l++) {
						GameBoard[l][column] = 'S';
					}
				}
			}
			
		} while (flag == 0);

	}
}

bool Game::CheckHit(int row, int culom)
{
	if (GameBoard[row][culom] == '@' || GameBoard[row][culom] == 'X')
	{
		cout << "you have allready chose this place" << endl;
		return false;
	}
	if (GameBoard[row][culom] == 'S') {
		cout << "HIT!!" << endl;
		GameBoard[row][culom] = '@';
		return true;
	}
	else {
		GameBoard[row][culom] = 'X';
		cout << "MISS" << endl;
		return false;
	}
}

bool Game::CheckSunk(int row, int culom)
{
	int i, j;
		for (j = culom + 1; j < 10 && GameBoard[row][j] != '_'; j++) {
			if (GameBoard[row][j] == 'S') {
				return false;
			}
		}
		for (j = culom - 1; j > -1 && GameBoard[row][j] != '_'; j--) {
			if (GameBoard[row][j] == 'S') {
				return false;
			}
		}
		for (i = row + 1; i < 10 && GameBoard[i][culom] != '_'; i++) {
			if (GameBoard[i][culom] == 'S') {
				return false;
			}
		}
		for(i = row - 1 ; i > -1 && GameBoard[i][culom] != '_'; i--) {
			if (GameBoard[i][culom] == 'S') {
				return false;
			}
		}
		return true;
}
		

