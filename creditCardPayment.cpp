// File which contains the functions of the class CreditCardPayment

#include "creditCardPayment.h"
#include <string>
using namespace std;

// Empty Constructor
CreditCardPayment::CreditCardPayment()
{
    nameCard = " ";
    cardNumber = " ";
    payment = 0;
}

// Constructor that initializes the data members
CreditCardPayment::CreditCardPayment(string name, string number, float pay) : Payment(pay)
{
    nameCard = name;
    cardNumber = number;
}

// Prints out the details of the payment
void CreditCardPayment::paymentDetails() const
{
    cout << "The credit card payment was of: " << payment << "$. By " << nameCard << ", card number: " << cardNumber << endl;
}

// Destructor
CreditCardPayment::~CreditCardPayment()
{
    cout << "The CreditCardPayment object was succesfully destroyed" << endl;
}

// Returns the payment 
float CreditCardPayment::getPayment() const
{
    return payment;
}
