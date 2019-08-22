// Functions for the class Date

#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(const Date & date2)
{
	day = date2.day;
	month = date2.month;
	year = date2.year;
}

Date::Date(int d, int m, int y)
{
	day = (d >= 0 && d <= 31) ? d : 0;
	month = (m >= 0 && m <= 12) ? m : 0;
	year = (y >= 0) ? y : 0;
}

void Date::setDate(int d, int m, int y)
{
	day = (d >= 0 && d <= 31) ? d : 0;
	month = (m >= 0 && m <= 12) ? m : 0;
	year = (y >= 0) ? y : 0;
}

void Date::getDate() const
{
	cout << day << "/" << month << "/" << year << endl;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

Date::~Date()
{

}
