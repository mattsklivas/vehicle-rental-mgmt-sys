// Truck class that is derived from the Vehicle class

#include "Truck.h"
#include <iostream>
using namespace std;

// Default constructor
Truck::Truck() : Vehicle()
{
	weightlimit = 0;
}

// Constructor which sets the weight limit and calls the constructor of the base class 'Vehicle'
Truck::Truck(string& truck_model, Date& truck_date, int truck_mileage, string& truck_id, bool truck_rental[12][30], int max_weight) : Vehicle(truck_model, truck_date, truck_mileage, truck_id, truck_rental)
{
	weightlimit = max_weight;
}

// Copy constructor
Truck::Truck(const Truck& truck) 
{
	weightlimit = truck.weightlimit;
}

// Destructor
Truck::~Truck()
{
	cout << "Truck object successfully deleted." << endl;
}

// Sets the weight limit
void Truck::setWeightlimit(int max_weight)
{
	weightlimit = max_weight;
}

// Returns the weight limit
int Truck::getWeightlimit() const
{
	return weightlimit;
}

// Prints information about a truck object
void Truck::print() const
{
    cout << "Vehicle Information:" << endl << endl;
    cout << "Model of the vehicle: " << getModel() << endl;
    cout << "Date of association to fleet: ";
    printDate();
    cout << "Mileage: " << getMileage() << endl;
    cout << "Vehicle ID: " << getID() << endl;
    getRental();
	cout << "Weight limit: " << getWeightlimit() << "lbs" << endl;
}
