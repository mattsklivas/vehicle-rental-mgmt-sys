// Header file of the ReservationRequest class

#pragma once
#include "Date.h"
#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;

class ReservationRequest
{
public:
    
	ReservationRequest(); // Default constructor
	ReservationRequest(const Customer&, const string&,Date,Date , Date, int);
    // Constructor which sets the information about a reservation request
    
	ReservationRequest(const ReservationRequest&);              // Copy Constructor
	virtual ~ReservationRequest();                              // Destructor

	void setCustomer(Customer*);                                // Sets a customer to the reservation request
	void getCustomer() const;                                   // Return customer object

	void setVehicle_type(string*);                              // Sets the vehicle type. Either "car" or "truck"
	string getVehicle_type() const;                             // Returns the vehicle type

	int getRes_num() const;                                     // Returns the reservation number

	void setRes_date(int, int, int);                            // Sets the reservation date
	Date getRes_date() const;                                   // Returns the reservation date
	void printRes_date() const;                                 // Prints the reservation date

	void setStart_date(int, int, int);                          // Sets the rental start date
	Date getStart_date() const;                                 // Returns the rental start date
	void printStart_date() const;                               // Prints the rental start date

	void setEnd_date(int, int, int);                            // Sets the rental end date
	Date getEnd_date() const;                                   // Returns the rental end date
	void printEnd_date() const;                                 // Prints the rental end date

	void setLimit(int);                                         // Sets either the car capacity or truck weight limit
	void getLimit() const;                                      // Returns either the car capacity or truck weight limit
    int getLimitNum() const;

	void print() const;                                         // Prints information about the reservation request
    

private:
    static int count;       // Counts the number of reservation questions. Used to generate a reservation request number
	Customer *customer;                                         // Customer who made the request
	string *vehicle_type;                                       // Type of vehicle rented
	int resNumber;                                              // Reservation request number
	Date resDate;                                              // Reservation request date
	Date startDate;                                            // Rental starting date
	Date endDate;                                              // Rental end date
	int limit;                                                  // Holds the car capacity or truck weight limit
};

