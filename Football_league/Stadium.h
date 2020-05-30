#include "Manager.h"


class Stadium {        //stadium class with stadium name,location and capacity
private:	
	string StadiumName;
	string City;
	int Seats;
public:
	Stadium(string  name, string  city, int seatsamount) :StadiumName(name), City(city), Seats(seatsamount) {};
	~Stadium() {};
	void print()const;
};
