// ReservationRequest class

#include "Date.h"
#include "Customer.h"
#include "ReservationRequest.h"
#include <iostream>
#include <string>
using namespace std;

int ReservationRequest::count = 1; // Initializes the static counter to 1

// Default constructor
ReservationRequest::ReservationRequest()
{
	customer = new Customer();
	vehicle_type = new string("");
	resNumber = count;
	Date resDate;
	Date startDate;
	Date endDate;
	limit = 0;
	++count;
}

// Constructor which sets the information about a reservation request
ReservationRequest::ReservationRequest(const Customer& customer1, const string& type, Date reservedate, Date startdate, Date enddate, int vehicle_limit)
{
	customer = new Customer();
	vehicle_type = new string("");
	resNumber = count;
	limit = vehicle_limit;
	
	*customer = customer1;
	*vehicle_type = type;
	resDate = reservedate;
	startDate = startdate;
	endDate = enddate;

	++count;
}

// Copy Constructor
ReservationRequest::ReservationRequest(const ReservationRequest& request)
{
	customer = request.customer;
	vehicle_type = request.vehicle_type;
	resNumber = request.resNumber;
	resDate = request.resDate;
	startDate = request.startDate;
	endDate = request.endDate;
	limit = request.limit;
}

// Destructor
ReservationRequest::~ReservationRequest()
{
	delete customer;
	delete vehicle_type;
	--count;
    cout << "The ReservationRequest object was successfully destroyed" << endl;
}

// Sets a customer to the reservation request
void ReservationRequest::setCustomer(Customer* customer1)
{
	customer = customer1;
}

// Returns the customer object
void ReservationRequest::getCustomer() const
{
	customer->print();
}

// Sets the vehicle type. Either "car" or "truck"
void ReservationRequest::setVehicle_type(string* type)
{
	if (*type != "car" && "truck")
		cout << "Invalid vehicle type" << endl;
	else
		vehicle_type = type;
}

// Returns the vehicle type
string ReservationRequest::getVehicle_type() const
{
	return *vehicle_type;
}

// Returns the reservation number
int ReservationRequest::getRes_num() const
{
	return resNumber;
}

// Sets the reservation date
void ReservationRequest::setRes_date(int day, int month, int year)
{
	resDate.setDate(day, month, year);
}

// Returns the reservation date
Date ReservationRequest::getRes_date() const
{
	return resDate;
}

// Prints the reservation date
void ReservationRequest::printRes_date() const
{
	resDate.getDate();
}

// Sets the rental start date
void ReservationRequest::setStart_date(int day, int month, int year)
{
	startDate.setDate(day, month, year);
}

// Returns the rental start date
Date ReservationRequest::getStart_date() const
{
	return startDate;
}

// Prints the rental start date
void ReservationRequest::printStart_date() const
{
	startDate.getDate();
}

// Sets the rental end date
void ReservationRequest::setEnd_date(int day, int month, int year)
{
	endDate.setDate(day, month, year);
}

// Returns the rental end date
Date ReservationRequest::getEnd_date() const
{
	return endDate;
}

// Prints the rental end date
void ReservationRequest::printEnd_date() const
{
	endDate.getDate();
}

// Sets either the car capacity or truck weight limit
void ReservationRequest::setLimit(int vehicle_limit)
{
	limit = vehicle_limit;
}

// Returns either the car capacity or truck weight limit
void ReservationRequest::getLimit() const
{
	if (*vehicle_type == "car")
		cout << "Passenger capacity: " << limit << " passengers" << endl;
	else
		cout << "Weight limit: " << limit << "lbs" << endl;
}

int ReservationRequest::getLimitNum() const
{
    return limit;
}

// Prints information about the reservation request
void ReservationRequest::print() const
{
	customer->print();
	cout << "Reservation details: " << endl << endl;
	cout << "Vehicle type: " << *vehicle_type << endl;
	cout << "Reservation request number: " << resNumber << endl;
	cout << "Reservation date: ";
	printRes_date();
	cout << "Rental start date: ";
	printStart_date();
	cout << "Rental end date: ";
	printEnd_date();
	getLimit();
	cout << endl;
}

