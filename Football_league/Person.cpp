#include "Person.h"

Person & Person::operator=(const Person &temp) // a copy ctor
{
	Fname = temp.Fname;
	Lname = temp.Lname;
	Id = temp.Id;
	return *this;
}



