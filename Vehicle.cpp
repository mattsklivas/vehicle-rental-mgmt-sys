// Vehicle class functions


#include "Date.h"
#include "Vehicle.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

// Default constructor
Vehicle::Vehicle()
{
	model = new string("");
	date = new Date;
	mileage = 0;
	id = new string("");

	// Vehicle rental availability intially set to available for all dates in the array
	for (int i = 0; i < months; i++) {
		for (int j = 0; j < days; j++) {
			rental[i][j] = true; // true = available to rent on a given date
		}
	}
}

// Constructor which sets information about a vehicle
Vehicle::Vehicle(const string& vehicle_model,const Date& vehicle_date,const int vehicle_mileage,const string& vehicle_id,const bool vehicle_rental[12][30])
{
	model = new string("");
	date = new Date;
	mileage = vehicle_mileage;
	id = new string("");

	for (int i = 0; i < months; i++) {
		for (int j = 0; j < days; j++) {
			rental[i][j] = vehicle_rental[i][j]; // true = available to rent on a given date
		}
	}

	*model = vehicle_model;
	date->setDate(vehicle_date.getDay(), vehicle_date.getMonth(), vehicle_date.getYear());
	*id = vehicle_id;
}

// Copy constructor
Vehicle::Vehicle(const Vehicle& vehicle)
{
	model = vehicle.model;
	date = vehicle.date;
	mileage = vehicle.mileage;
	id = vehicle.id;
	rental[months][days] = vehicle.rental; 
}

// Destructor
Vehicle::~Vehicle()
{
	delete model;
	delete date;
	delete id;
	cout << "Vehicle object successfully deleted." << endl;
}

// Sets the vehicle model
void Vehicle::setModel(string vehicle_model)
{
	*model = vehicle_model;
}

// Returns the vehicle model
string Vehicle::getModel() const
{
	return *model;
}

// Sets the date the vehicle joined the rental fleet using integers
void Vehicle::setDate(int day, int month, int year)
{
	date->setDate(day, month, year);
}

// Sets the date the vehicle joined the rental fleet using a date object
void Vehicle::setDate(Date *date1)
{
	date = date1;
}

// Returns the date the vehicle joined the rental fleet
Date Vehicle::getDate() const
{
	return *date;
}

// Returns the date the vehicle joined the rental fleet
void Vehicle::printDate() const
{
	date->getDate();
}

// Sets the vehicle mileage
void Vehicle::setMileage(int vehicle_mileage)
{
	mileage = vehicle_mileage;
}

// Returns the vehicle mileage
int Vehicle::getMileage() const
{
	return mileage;
}

// Sets the vehicle ID
void Vehicle::setID(string car_id)
{
	*id = car_id;
}

// Returns the vehicle ID
string Vehicle::getID() const
{
	return *id;
}

// Sets the vehicle's rental status for a certain date
void Vehicle::setRental(bool rent, int day, int month)
{
	if (day > 31 || day == 0) {
		cout << "Day entered is out of range" << endl;
		return;
	}
	else if (month > 13 || month == 0) {
		cout << "Month entered is out of range" << endl;
		return;
	}
	else {
		rental[month-1][day-1] = rent;
	}
}

// Checks the vehicle's rental status for a certain date
bool Vehicle::checkRental(int day, int month)
{
	return rental[month-1][day-1];
}

// Returns the dates the vehicle is rented out
void Vehicle::getRental() const
{
	cout << "Days rented:" << endl;
	for (int i = 0; i < months; i++) {
		for (int j = 0; j < days; j++) {
			if (rental[i][j] == false)
			{
				cout << j+1 << "/" << i+1 << "/" << date->getYear() << endl;
			}
			else continue;
		}
	}
}

