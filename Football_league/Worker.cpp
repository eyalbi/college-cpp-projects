#include "Worker.h"

Worker::~Worker()
{
	
}

void Worker::Print() const       //print method
{
	cout << Lname << " " << Fname << endl;
	cout << "ID number: " << Id << endl;
	cout << "seniority:" << Veteck << " years" << endl;
	cout << "Salary: " << ReturnSalary() << endl;
	


}
