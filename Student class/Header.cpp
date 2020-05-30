#include <iostream>
#include "student.h"
#include <string>
#define ZERO 0


Student::Student(char * name, long id, int courseNum, int milga)
{
	Set_Name (name);
	Set_Id (id);
	Set_CourseNum (courseNum);
	Set_Scolar(milga);
}

Student::Student(const Student & obj)
{
	strcpy_s(FName, 51, obj.FName);
	Set_Id(obj.Id);
	Set_CourseNum(obj.CourseNum);
	Set_Scolar(obj.ScolarShip);
}

void Student::Set_Name(char * name)
{
	strcpy_s(FName,51, name);
	
}

void Student::Set_Id(long id)
{
	Id = id;
}

void Student::Set_CourseNum(int num)
{
	if (num > ZERO) {
		CourseNum = num;
	}
	else {
		CourseNum = ZERO;
	}
}

void Student::Set_Scolar(int milga)
{

	if (milga < ZERO) {
		ScolarShip = ZERO;
	}
	else {
		ScolarShip = milga;
	}
}

int Student::StudentFees()
{
	if ((CourseNum * 1500) - ScolarShip > ZERO) {
		return (CourseNum * 1500) - ScolarShip;
	}
	else
	{
		return ZERO;
	}
}

void Student::PrintSData()
{
	cout << "student name: " << FName << ", ID: " << Id << ", NO. of Courses: " << CourseNum << "\nscolarship:" << ScolarShip << ", Tuition fees: " << StudentFees() << endl;
}
