#include "Battleship.h"
#include <ctime>
typedef enum directions { vertical = 0, horizontal} directions;
enum culoms{A = 0,B,C,D,E,F,G,H,I,J};							//enum declration include direction to help the programmer
enum CULOMS1{a = 0,b,c,d,e,f,g,h,i,j};
class Game {       ///class declartion
private:
	char GameBoard[10][10];				//varibles declration a char matrix as game board and pointer to battleship class that will intialize as array dynamcly
	Battleship * Navy;
	int Navy_amount;
	static int Square_amount;
	void ClearBoard();											//intialize game board with "_" 
	bool CheckPlace(int num,int row,int culomn,int SubLenth);     //// check if a sub is capable of fiiting in a random place as game rules has been set
	bool check_coordinate(int num, int row, int column,int SubLenth);/// a function that help check place func to determaine whether you can place a submrine in a given place
	void BuildBoard();													//// a function that build the game board and placing the subs in a random place
	bool CheckHit(int row, int culom);							// a function that checks if user input hit a submarine
	bool CheckSunk(int row, int culom);						//a function that checks if a sub has been sunk
public:
	Game(int);									////a constroctor that gets navy size as input and build battle ship in the right amount and size
	~Game() {delete[] Navy;}							/// a destroctor that releases the dynamical allocation
	void PrintBoard();									// a function that prints the board but "hiding" the submarines every turn it updating with misses or hits
	void PrintOriginalBoard();					// a function that prints the board as it is
	void Play();								// a mangment function that creating and maneging the game
	
};
