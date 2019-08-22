// Header file for the class Truck, derived from the class Vehicle

#pragma once

#include "Vehicle.h"
#include <iostream>
using namespace std;

class Truck : public Vehicle
{
public:
	Truck(); // Default Constructor
    
	Truck(string& truck_model, Date& truck_date, int truck_mileage, string& truck_id, bool truck_rental[12][30], int maxweight);                                  // Constructor which sets information about a truck object
    
	Truck(const Truck&);                            // Copy constructor
	virtual ~Truck();                                // Destructor

	void setWeightlimit(int);                       // Sets the truck's weight limit
	int getWeightlimit() const;                     // Returns the truck's weight limit
	virtual void print() const;                     // Prints information about a truck object

private:
	int weightlimit;                                // Holds the truck's weight limit
};
