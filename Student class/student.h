#include <iostream>
#include <string>
#define ZERO 0
using namespace std;
class Student{					//הכרזת מחלקה
private:
	char FName[51];				//נתונית מחלקה
	long Id;
	int CourseNum;
	int ScolarShip;
public:
	Student(char *, long, int, int);		//  בנאי המקבל פרמטרים ומאתחל את נתוני המחלקה
	Student(const Student & obj);	// בנאי מעתיק
	char* Get_Name() { return FName; }					//פונקציות לקבלת נתוני המחלקה
	long Get_Id() { return Id; }
	int Get_CourseNum() { return CourseNum; }
	int Get_Scolar() { return ScolarShip; }
	void Set_Name(char *);									// פונקציות לעריכת נתוני המחלקה
	void Set_Id(long);
	void Set_CourseNum(int);
	void Set_Scolar(int);
	int StudentFees();						//פונקצייה לחישוב שכר לימוד של תלמיד
	void PrintSData();						//פונקציה להדפסת נתוני תלמיד
};
