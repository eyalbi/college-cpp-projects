#define ZERO 0
#include "game1.h"
int main() {
	cout << "==========================================\n" << "hello, this is the game 'bulls and cows' . " << endl;
	cout << "==========================================" << endl;
	cout << "the computer concieved 4 - digits number (all digits are different and without 0)." << endl;
	cout << "your task - guess it threw number inputs." << endl;
	cout << "if the digit is identical, but it's at another location - this is a 'cow'\nif the digit is in the right place - its a 'bull'" << endl;
	Game PLAY;
	
	PLAY.play();
	return 0;
}