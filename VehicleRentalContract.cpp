// VehicleRentalContract class functions

#include "VehicleRentalContract.h"
#include <iostream>
using namespace std;

// Empty constructor
VehicleRentalContract::VehicleRentalContract()
{
    car = new Car;
    truck = new Truck;
    cash = new CashPayment;
    credit = new CreditCardPayment;
    rentStatus = false;
    reservation = new ReservationRequest;
}

// Constructor that sets cash and car, then puts credit and truck to nullptr
VehicleRentalContract::VehicleRentalContract(const Car& v, const CashPayment& c, const ReservationRequest& rr)
{
    *cash = c;
    credit = nullptr;
    *reservation = rr;
    *car = v;
    truck = nullptr;
}

// Constructor that sets car and credit, then puts truck and cash to nullptr
VehicleRentalContract::VehicleRentalContract(const Car& v, const CreditCardPayment& c, const ReservationRequest& rr)
{
    cash = nullptr;
    *credit = c;
    *reservation = rr;
    *car = v;
    truck = nullptr;
}

// Constructor that sets truck and cash, then puts car and credit to nullptr
VehicleRentalContract::VehicleRentalContract(const Truck& v, const CashPayment& c, const ReservationRequest& rr)
{
    *cash = c;
    credit = nullptr;
    *reservation = rr;
    *truck = v;
    car = nullptr;
}

// Constructor that sets truck and credit, then puts car and cash to nullptr
VehicleRentalContract::VehicleRentalContract(const Truck& v, const CreditCardPayment& cc, const ReservationRequest& rr)
{
    cash = nullptr;
    *credit = cc;
    *reservation = rr;
    *truck = v;
    car = nullptr;
}

// Prints out the rental information
void VehicleRentalContract::print()
{
    if (car->getMileage() != 0)         // if its a car this print will occur
        car->print();
    if (truck->getMileage() != 0)       // if its a truck this print will occur
        truck ->print();
    cout << endl;
    if (cash->getPayment() != 0.0)      // if cash was used, this print will occur
        cash->paymentDetails();
    if (credit->getPayment() !=0.0)     // if credit was used, this print will occur
        credit->paymentDetails();
    cout << endl;
    reservation->print();               // reservation information is also apart of the rental information
}

// Returns the request number
int VehicleRentalContract::getRequestNumber()
{
    return reservation->getRes_num();   //gets it from the reservation data member
}

// Destructor
VehicleRentalContract::~VehicleRentalContract()
{
    delete car;
    delete cash;
    delete credit;
    delete reservation;
    delete truck;
    cout << "The VehicleRentalContract object was succesfully destroyed" << endl;
}

// Sets the cash payment
void VehicleRentalContract::setCashPayment(const CashPayment& P)
{
    *cash = P;
}

// Sets the credit payment
void VehicleRentalContract::setCreditPayment(const CreditCardPayment& P)
{
    *credit = P;
}

// Sets the car
void VehicleRentalContract::setCar(const Car& c)
{
    *car = c;
}

// Sets the truck
void VehicleRentalContract::setTruck(const Truck& t)
{
    *truck = t;
}

// Sets the reservation
void VehicleRentalContract::setReservation(const ReservationRequest& rr)
{
    *reservation = rr;
}

// Sets the rentStatus
void VehicleRentalContract::setStatus(bool status)
{
    rentStatus = status;
}
