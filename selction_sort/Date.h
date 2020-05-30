#include <iostream>
#include <time.h>
using namespace std;



class Date {													//date class from lab
private:
	int day, month, year;
public:
	Date();
	Date(int, int, int);
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	int GetDay();
	int GetMonth();
	int GetYear();
	void PrintDate();
	void PrintMonthName();
	int MonthDaysNum();
	bool Meuberet();
	void NextDayDate();
	friend class Game;
	friend class Ligat_HaAl;
	bool operator < (const Date&);
	friend ostream& operator << (ostream & out, const Date& date);
};

