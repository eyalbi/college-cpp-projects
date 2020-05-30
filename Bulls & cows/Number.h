#include <iostream>
#include <ctime>
#include "Digit.h"
#define ZERO 0
using namespace std;

class Number							//class declaration
{
private:
	Digit number[4];									// an array of 4 digits type
public:
	Number();												// default constroctor
	void randomise();												// a function that randomise number
	void EnterValue();												// a function that help user enter a 4 digit number into the array
	int Get_Value(int num);								// a function that return a chosen value from the array
	void PrintNumber();												// a function that prints the array
	friend class Game;									//declaration of friend class
};
