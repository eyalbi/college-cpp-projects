#include "Game.h"
#define ZERO 0
int main() {
	int num;
	cout << "how many battleships do you want?(between 1-5)" << endl;  
	cin >> num;
	Game sub(num);					////create game type with user input
	sub.Play();								//start playing have fun//
	return ZERO;
}