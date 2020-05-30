#include <iostream>
#include <string>
#include <ctime>
#define ZERO 0
using namespace std;

class Person {					// a class that define a person with first and last name strings and an id string
protected:
	string Fname;
	string Lname;
	string Id;
public:
	Person() { Fname[ZERO] = '\0'; Lname[ZERO] = '\0'; Id[ZERO] = '\0'; };
	Person(string name, string surname, string id):Fname(name),Lname(surname),Id(id) {};
	~Person() {};
	Person & operator = (const Person&);
	virtual bool checkspecial()const =  ZERO;           // a special method that makes this class a pure abstract class
	friend class Team;
};