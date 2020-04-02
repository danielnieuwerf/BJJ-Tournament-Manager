#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
	int day;	// 0 to 31
	int month;	// 0 to 12
	int year;	// year since 1900

public:
	Date() {
		day = 1;
		month = 1;
		year = 1900;
	}
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	void setDay(int d)
	{
		if (d < 1 && d > 31)
			cout << "The day is invalid" << endl;
		else
			day = d;
	}
	void setMonth(int m)
	{
		if (m < 1 && m > 12)
			cout << "The month is invalid" << endl;
		else
			month = m;
	}
	void setYear(int y)
	{
		if (y < 1900 && y > 2020)
			cout << "The year is invalid" << endl;
		else
			year = y;
	}
	void showDate1()
	{
		cout << month << "/" << day << "/" << year << endl;
	}
	void showDate2()
	{
		string monthName[] = { "January", "February", "March",
			"April", "May", "June", "July",
			"August", "September", "October",
			"November", "December" };
		cout << day << " " << monthName[month - 1] << " " << year << endl;
	}
};