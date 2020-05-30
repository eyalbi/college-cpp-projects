#include <iostream>
#include <string>
#define ZERO 0
using namespace std;
class Student{					//����� �����
private:
	char FName[51];				//������ �����
	long Id;
	int CourseNum;
	int ScolarShip;
public:
	Student(char *, long, int, int);		//  ���� ����� ������� ������ �� ����� ������
	Student(const Student & obj);	// ���� �����
	char* Get_Name() { return FName; }					//�������� ����� ����� ������
	long Get_Id() { return Id; }
	int Get_CourseNum() { return CourseNum; }
	int Get_Scolar() { return ScolarShip; }
	void Set_Name(char *);									// �������� ������ ����� ������
	void Set_Id(long);
	void Set_CourseNum(int);
	void Set_Scolar(int);
	int StudentFees();						//�������� ������ ��� ����� �� �����
	void PrintSData();						//������� ������ ����� �����
};
