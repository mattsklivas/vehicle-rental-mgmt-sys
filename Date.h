// File which contains the header file of the class Date

#pragma once
#include <iostream>

class Date {

public:
	Date();
	Date(int, int, int);
	Date(const Date & date2);
	void setDate(int, int, int);
	void getDate() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	virtual ~Date();

private:
	int month;
	int day;
	int year;

};
