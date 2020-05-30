#include "Person.h"


class Worker : public Person {        // a inherited class from person that adds seniority data
protected:
	int Veteck;
public:
	Worker() :Person(), Veteck(ZERO) {};
	Worker(string name, string surname, string id, int TVeteck) :Person(name,surname,id), Veteck(TVeteck) {};
	~Worker();
	virtual float ReturnSalary()const = ZERO;       //pure abstract class
	virtual void Print()const;
	friend class Ligat_HaAl;
	friend class Team;
};
