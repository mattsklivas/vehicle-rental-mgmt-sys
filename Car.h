// Header file for the class Car, derived from the class Vehicle

#pragma once

#include "Vehicle.h"
#include <iostream>
using namespace std;

class Car : public Vehicle
{
public:
	Car(); // Default Constructors
    
	Car(string& car_model, Date& car_date, int car_mileage, string& car_id, bool car_rental[12][30], int car_capacity);
        // Constructor which sets information about a Car
    
	Car(const Car &car);                // Copy constructor
	virtual ~Car();                     // Destructor

	void setCapacity(int);              // Sets the passenger capacity
	int getCapacity() const;            // Returns the passenger capacity
	virtual void print() const;         // Prints information about a Car object

private:
	int capacity;                       // Holds the passenger capacity
};
