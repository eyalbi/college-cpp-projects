#include "Battleship.h"
int Battleship::ShipAmount = ZERO;
Battleship::Battleship()///constroctor that uses the ship amount static variable to intialize ship lenth in order of creation
{
	if (ShipAmount > 4) {
		ShipLenth = 2;
		ShipAmount++;
	}
	else if (ShipAmount >= ZERO && ShipAmount < 4){
		ShipLenth = 5 - ShipAmount;
		ShipAmount++;
	}
	else if(ShipAmount == 4) {
		ShipLenth = 3;
		ShipAmount++;
	}
}
