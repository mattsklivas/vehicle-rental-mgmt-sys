// Functions of the class Payment

#include "payment.h"
#include <iostream>
using namespace std;

// Empty Constructor
Payment::Payment()
{
    payment = 0.0;
}

// Sets the payment and constructs the object
Payment::Payment(float pay)
{
    payment = pay;
}

// Destructor
Payment::~Payment()
{
    
}

// Sets the payment
void Payment::setPayment(float pay)
{
    payment = pay;
}

// Returns the payment 
float Payment::getPayment() const
{
    return payment;
}
