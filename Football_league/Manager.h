#include "Referee.h"


class Manager : public Worker {          //inherited class from worker without extra data
public:
	Manager() :Worker() {};
	Manager(string name, string surname, string id, int TVeteck) :Worker(name, surname, id, TVeteck) {};
	Manager(const Manager&);
	~Manager() {};
	float ReturnSalary()const;
	bool checkspecial()const;
	void Print()const;
};
