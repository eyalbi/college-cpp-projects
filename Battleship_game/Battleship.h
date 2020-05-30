#include <iostream>
#define ZERO 0
using namespace std;

class Battleship {   //class declaration
private:
	int ShipLenth;                     //declaring private variables lenth and amount that is static
	static  int ShipAmount;
public:
	static int Get_Amount() { return ShipAmount; }        //static method to get static value
	void Set_Lenth(int num) { ShipLenth = num; }		//set func for lenth variable
	int Get_lenth() { return ShipLenth; }
	Battleship();                                // default constroctor
	friend class Game;                            //friend class declaration

};
