// VehicleRentalContract class header

#pragma once

#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "cashPayment.h"
#include "creditCardPayment.h"
#include "ReservationRequest.h"

class VehicleRentalContract {                       // Class that handles the contracts
    
public:
    VehicleRentalContract();                                                                 // Empty Constructor
    virtual ~VehicleRentalContract();                                                        // Destructor
    
    void setReservation(const ReservationRequest&);                                         // Sets the reservation
    void setCashPayment(const CashPayment & P);                                             // Sets the cash payment
    void setCreditPayment(const CreditCardPayment & P);                                     // Sets the credit card payment
    void setCar(const Car& c);                                                              // Sets the car
    void setTruck(const Truck& t);                                                          // Sets the truck
    void setStatus(bool);                                                                   // Sets rentStatus
    
    VehicleRentalContract(const Car&, const CashPayment&, const ReservationRequest&);           // Constructor car and cash
    VehicleRentalContract(const Car&, const CreditCardPayment&, const ReservationRequest&);     // Constructor car and credit
    VehicleRentalContract(const Truck&, const CashPayment&, const ReservationRequest&);         // Constructor truck and cash
    VehicleRentalContract(const Truck&, const CreditCardPayment&, const ReservationRequest&);   // Constructor truck and credit
    
    int getRequestNumber();                                                                 // returns the request number
    
    void print();                                                                      // prints all the rental information
    
private:
    Car *car;                                               // Holds the car
    Truck *truck;                                           // Holds the truck
    CashPayment *cash;                                      // Holds the cash
    CreditCardPayment *credit;                              // Holds the credit
    bool rentStatus;                                        // Holds the rental status
    ReservationRequest *reservation;                        // Holds the reservation
};
