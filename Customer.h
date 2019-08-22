// Header file for the class Customer

#pragma once
#include "Date.h" 
#include <iostream>
#include <string>
using namespace std;

class Customer
{
public:
	Customer(); // Default constructor
	Customer(const string& customer_name, const string& drivers_license, Date dateofbirth); // Constructor which sets information about a customer
	Customer(const Customer&); // Copy constructor
	virtual ~Customer(); // Destructor

	void setName(string*); // Sets customer name
	string getName() const; // Returns customer name

	void setLicense(string*); // Sets the customer's driver's license
	string getLicense() const; // Returns driver's license

	void setDOB(int, int, int); // Sets the customer's date of birth using integers
	void setDOB(Date); // Sets the customer's date of birth using a date object
	Date getDOB() const; // Returns the customer's date of birth
	void printDOB() const; // Prints the customer's date of birth

	void print() const; // Prints information about a customer

private:
	string *name; // Customer name
	string *license; // Customer's driver's license
	Date DOB; // Customer's date of birth
};
