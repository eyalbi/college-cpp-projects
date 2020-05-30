#include "Number.h"
#define ZERO 0
using namespace std;
class Game {					// class declaration
private:
	Number *user = NULL, *computer = NULL;				//private variable declartion pointers to numbers class
	int Cows()const;
	int Bulls()const;
public:																	
	Game();											// default constroctor allocates memory
	Game(const Game & obj);								// copy constroctor
	~Game() { delete user; delete computer; };					///destroctor to free dynamic memory
	void play();												// play method that runs and manges the game
	bool CheckWin()const;									// function that checks if the game is over
	void PrintUser()const;									// function that prints user number array
	void Set_user();											// a function to intialize user number in every turn
};
