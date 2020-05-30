#include <iostream>
#include "student.h"
#include <string>
using namespace std;
int main() {				// הגדרת שני אובייקטים מטיפוס סטודנט איתחולם וחישוב שכר לימודם
	char TName[51];
	long TId;
	int TMilga, TCourseNum;
	cout << "enter student name" << endl;
	cin.getline(TName, 51);
	cout << "enter student ID" << endl;
	cin >> TId;
	cout << "enter the student's number of courses" << endl;
	cin >> TCourseNum;
	cout << "enter scolarship fees" << endl;
	cin >> TMilga;
	Student S1(TName, TId, TCourseNum, TMilga);
	S1.PrintSData();
	getchar();
	cout << "enter student name" << endl;
	cin.getline(TName, 51);
	cout << "enter student ID" << endl;
	cin >> TId;
	cout << "enter the student's number of courses" << endl;
	cin >> TCourseNum;
	cout << "enter scolarship fees" << endl;
	cin >> TMilga;
	Student S2(TName, TId, TCourseNum, TMilga);
	S2.PrintSData();
	int U;
	cout << "update student 1 num of courses:" << endl;
	cin >> U;
	S1.Set_CourseNum(U);
	S1.PrintSData();
	
	return ZERO;
}

