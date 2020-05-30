#include "Student.h"

bool Student::operator>(const Student & tstudent)
{
	if (average > tstudent.average) {
		return true;
	}
	return false;
}

bool Student::operator==(const Student & tstudent)
{
	if (Id == tstudent.Id) {
		return true;
	}
	return false;
}

Student & Student::operator=(const Student & other)
{
	Birth = other.Birth;
	fname = other.fname;
	lname = other.lname;
	Id = other.Id;
	GradeAmount = other.GradeAmount;
	average = other.average;
	return *this;
}

ostream & operator<<(ostream& out, const Student& talmid)
{ 
	 
	cout << "student name: " << talmid.lname << " " << talmid.fname << endl;
	cout << "student id: " << talmid.Id << endl;
	cout << "date of birth: " << talmid.Birth << endl;
	cout << "student avereage: " << talmid.average << endl;
	cout << "Grades amount : " << talmid.GradeAmount;
	return out;

}



