// File which contains the functions for the class CashPayment

#include "cashPayment.h"
#include <iostream>
using namespace std;

// Empty Constructor
CashPayment::CashPayment()
{
    payment = 0.0;
}

// Constructor that sets the payment
CashPayment::CashPayment(float pay) : Payment(pay)
{
    // Empty because payment class already handles this initializiation
}

// Prints out the details of the payment
void CashPayment::paymentDetails() const
{
    cout << "The cash payment was of: " << payment << "$." << endl;
}

// Destructor
CashPayment::~CashPayment()
{
    cout << "The cash payment object was succesfully destroyed" << endl;
}

// Returns the payment 
float CashPayment::getPayment() const
{
    return payment;
}
