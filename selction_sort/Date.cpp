#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

Date::Date() {
	//time_t rawtime;
	//struct tm * timeinfo;
	//time(&rawtime);
	//timeinfo = localtime(&rawtime);
	day = rand() % 31 + 1;          //timeinfo->tm_mday;
	month = rand() % 12 + 1;            //timeinfo->tm_mon + 1;
	year = 2019;          //timeinfo->tm_year + 1900;
}

Date::Date(int day, int month, int year) :day(day), month(month), year(year) {}

void Date::SetDay(int d) {
	day = d;
}

void Date::SetMonth(int m) {
	month = m;
}

void Date::SetYear(int y) {
	year = y;
}

int Date::GetDay() { return day; }

int Date::GetMonth() { return month; }

int Date::GetYear() { return year; }

void Date::PrintDate() {
	cout << day << "/" << month << "/" << year << endl;
}

void Date::PrintMonthName() {
	switch (month) {
	case 1:
		cout << "January" << endl;
		break;
	case 2:
		cout << "February" << endl;
		break;
	case 3:
		cout << "March" << endl;
		break;
	case 4:
		cout << "April" << endl;
		break;
	case 5:
		cout << "May" << endl;
		break;
	case 6:
		cout << "June" << endl;
		break;
	case 7:
		cout << "July" << endl;
		break;
	case 8:
		cout << "August" << endl;
		break;
	case 9:
		cout << "September" << endl;
		break;
	case 10:
		cout << "October" << endl;
		break;
	case 11:
		cout << "November" << endl;
		break;
	case 12:
		cout << "December" << endl;
		break;
	default:
		cout << "No month in number: " << month << "." << endl;
	}
}

int Date::MonthDaysNum() {
	int num;
	enum Month {
		January = 1, February, March, April, May, June,
		July, August, September, October, November, December
	};

	if ((month == January) || (month == March) || (month == May) || (month == July) || (month == August) || (month == October) || (month == December)) {
		num = 31;
	}
	if ((month == April) || (month == June) || (month == September) || (month == November)) {
		num = 30;
	}
	if (month == February) {
		num = 28;
	}
	return num;
}

bool Date::Meuberet() {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}

void Date::NextDayDate() {
	if (day < MonthDaysNum())
		day++;
	if (day == MonthDaysNum() && month < 12) {
		day = 1;
		month++;
	}
	if (day == MonthDaysNum() && month == 12) {
		day = 1;
		month = 1;
		year++;
	}
}

bool Date::operator < (const Date &obj)
{
	if (this->year < obj.year) {
		return true;
	}
	else if (this->year > obj.year) {
		return false;
	}
	else if (this->year == obj.year) {
		if (month < obj.month)
		{
			return true;
		}
		else if(month > obj.month)
		{
			return false;
		}
		else if (month == obj.month)
		{
			if (day < obj.day) {
				return true;
			}
			else if (day > obj.day) {
				return false;
			}
			else if(day == obj.day)
			{
				return false;
			}
		}
	}
	return false;
}

ostream & operator<<(ostream & out, const Date & date)
{
	cout << date.day << "/" << date.month << "/" << date.year;
	return out;
}
