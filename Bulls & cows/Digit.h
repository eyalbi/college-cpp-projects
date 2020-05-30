#define ZERO 0
using namespace std;

class Digit {     //declaration of digit class
private:													//private varible int type
	int value;
	bool InArray(int num,int index,  Digit array[4]);    ///private method that check if number is an array allready
public:
	Digit():value(ZERO) {};						//default constroctor
	bool DEqual(const Digit &)const;				//checks if digit typ are equal (their values)
	int Get_Digit() { return value; };				// get function to value varible
	void Set_Digit(int num);							//set function 
	friend class Number;						// friends classes declaration
	friend class Game;
};