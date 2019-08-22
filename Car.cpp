// Car class that is derived from the Vehicle class

#include "Car.h"
#include <iostream>
using namespace std;

// Default constructor
Car::Car(): Vehicle()
{
	capacity = 0;
}

// Constructor which sets the passenger capacity and calls the constructor of the base class
Car::Car(string& car_model, Date& car_date, int car_mileage, string& car_id, bool car_rental[12][30], int car_capacity): Vehicle(car_model, car_date, car_mileage, car_id, car_rental)
{
	capacity = car_capacity;
}

// Copy constructor
Car::Car(const Car& car)
{
	capacity = car.capacity;
}

// Destructor
Car::~Car()
{
	cout << "Car object successfully deleted." << endl;
}

// Sets the passenger capacity
void Car::setCapacity(int car_capacity)
{
	capacity = car_capacity;
}

// Returns the passenger capacity
int Car::getCapacity() const
{
	return capacity;
}

// Prints information about a car object
void Car::print() const
{
    cout << "Vehicle Information:" << endl << endl;
    cout << "Model of the vehicle: " << getModel() << endl;
    cout << "Date of association to fleet: ";
    printDate();
    cout << "Mileage: " << getMileage() << endl;
    cout << "Vehicle ID: " << getID() << endl;
    getRental();
	cout << "Passenger capacity: " << getCapacity() << endl;
}
