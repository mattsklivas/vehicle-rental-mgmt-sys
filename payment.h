// Header file of the class Payment

#include <iostream>
#include <string>
#pragma once

class Payment                  // Base Payment class
{
    
protected:
    float payment;            // Stores the amount of the payment

public:
    Payment();                      // Empty constructor
    Payment(float pay);             // Constructor that sets the payment
    virtual ~Payment();                     // Destructor
    
    virtual void paymentDetails() const = 0;          // Prints the amount of the payment
    
    void setPayment(float pay);     // Sets the amount of the payment
    float getPayment() const;       // Returns the amount of the payment
};
