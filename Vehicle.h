#pragma once
// Vehicle class header


#include "Date.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Vehicle {

public:
	Vehicle(); // Default constructor
	Vehicle(const string& vehicle_model,const Date& vehicle_date,const int vehicle_mileage,const string& vehicle_id,const bool vehicle_rental[12][30]);                        // Constructor which sets information about a vehicle object
	Vehicle(const Vehicle& vehicle);                    // Copy constructor
	virtual ~Vehicle();                                 // Destructor

	void setModel(string);                              // Sets the vehicle model
	string getModel() const;                            // Returns the vehicle model

	void setDate(int, int, int);                        // Sets the date the vehicle joined the rental fleet using integers
	void setDate(Date*);                                // Sets the date the vehicle joined the rental fleet using a date object
	Date getDate() const;                               // Returns the date the vehicle joined the rental fleet
	void printDate() const;                             // Prints the date the vehicle joined the rental fleet

	void setMileage(int);                               // Sets the vehicle mileage
	int getMileage() const;                             // Returns the vehicle mileage

	void setID(string);                                 // Sets the vehicle ID
	string getID() const;                               // Returns the vehicle ID

	void setRental(bool, int, int);                     // Sets the vehicle's rental status for a certain date
	bool checkRental(int, int);                         // Checks the vehicle's rental status for a certain date
	void getRental() const;                             // Returns the dates the vehicle is rented out

	virtual void print() const = 0;                     // Prints information about a vehicle object
    
private:
	string *model;                                      // Vehicle model
	Date *date;                                         // Date the vehicle joined the rental fleet
	int mileage;                                        // Vehicle mileage
	string *id;                                         // Vehicle ID
    
	static const unsigned int months = 12;              // Fixed amount of months in a year
	static const unsigned int days = 30;                // Fixed amount of days in a month
	bool rental[months][days]; // Array which holds information about a vehicle's rental status for every day in a given year
};
