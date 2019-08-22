// File which contains the header file of the class CreditCardPayment

#pragma once
#include "payment.h"
#include <string>
using namespace std;

class CreditCardPayment : public Payment {                          // Class that deals with payments made with credit card
    
private:
    string nameCard;                                                // holds the name of the card holder
    string cardNumber;                                              // hold the number of the card
    
public:
    CreditCardPayment();                                            // Empty constructor
    CreditCardPayment(string name, string number, float pay);       // Constructor that initializes all the data members
    float getPayment() const;                                       // Retuns the payment
    virtual ~CreditCardPayment();                                   // Destructor
    
    virtual void paymentDetails() const;                            // Prints out all the details of the payment 
};
