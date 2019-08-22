// File which contains the header file of the class CashPayment

#pragma once 
#include "payment.h"

class CashPayment : public Payment {            // class that deals with Payments that were made in cash
    
public:
    CashPayment();                              // Empty constructor 
    CashPayment(float pay);                     // Constructor that sets the payment
    virtual ~CashPayment();                     // Destructor
    float getPayment() const;                   // Returns the payment
    
    virtual void paymentDetails() const;        // Prints out the details of the payment 
};
