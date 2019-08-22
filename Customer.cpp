// Customer class

#include "Date.h"
#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Customer::Customer()
{
	name = new string("");
	license = new string("");
	Date DOB;
}

// Constructor which sets information about a customer
Customer::Customer(const string& customer_name, const string& drivers_license, Date dateofbirth)
{
	name = new string("");
	license = new string("");
	*name = customer_name;
	*license = drivers_license;
	DOB.setDate(dateofbirth.getDay(), dateofbirth.getMonth(), dateofbirth.getYear());
}

// Copy constructor
Customer::Customer(const Customer& customer)
{
	name = customer.name;
	license = customer.license;
	DOB = customer.DOB;
}

// Destructor
Customer::~Customer()
{
	delete name;
	delete license;
	cout << "Customer object successfully deleted." << endl;
}

// Sets customer name
void Customer::setName(string* customer_name)
{
	name = customer_name;
}

// Returns customer name
string Customer::getName() const
{
	return *name;
}

// Sets the customer's driver's license
void Customer::setLicense(string* drivers_license)
{
	license = drivers_license;
}

// Returns driver's license
string Customer::getLicense() const
{
	return *license;
}

// Sets the customer's date of birth using integers
void Customer::setDOB(int day, int month, int year)
{
	DOB.setDate(day,month,year);
}

void Customer::setDOB(Date date1) // Sets the customer's date of birth using a date object
{
	DOB = date1;
}

// Returns the customer's date of birth
Date Customer::getDOB() const
{
	return DOB;
}

// Prints the customer's date of birth
void Customer::printDOB() const
{
	DOB.getDate();
}

// Prints information about a customer
void Customer::print() const
{
	cout << "Customer information: " << endl << endl;
	cout << "Name: " << getName() << endl;
	cout << "Driver's license: " << getLicense() << endl;
	cout << "Date of birth: ";
	printDOB();
	cout << endl;
}
