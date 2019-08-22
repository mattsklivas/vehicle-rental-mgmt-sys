// Functions for the class FleetManager


#include "FleetManager.h"
#include "VehicleRentalContract.h"
#include "ReservationRequest.h"
#include "Car.h"
#include <iostream>
using namespace std;

// Empty constructor
FleetManager::FleetManager()
{
    requestAmount = 0;
    contractAmount = 0;
    truckAmount = 0;
    carAmount = 0;
    customerAmount = 0;
    
}

// Prints out all the details about a contract based on request number
void FleetManager::printContractDetails(int reqNum)
{
    for (int i{0}; i < 10; i++)
        if (contracts[i].getRequestNumber() == reqNum)       // if the given number is the same as a request in a contract
        {
            cout << "Rental Contract Details: " << endl;
            contracts[i].print();
            return;
        }
    
    cout << "This request number is not valid." << endl;
}

// Adds a request to the array of requests
void FleetManager::addRequest(ReservationRequest *req)
{
    if (requestAmount < 10) // we chose to limit our array to 10 members
    {
        requests[requestAmount] = *req;
        requestAmount++;    // must increment so that the next request will not replace the one just added
    }
    else
        cout << "There is no more space for another reservation: " << endl;
}

// Destructor
FleetManager::~FleetManager()
{
    cout << "The fleet manager object was successfully destroyed." << endl;
}

// Adds a contract to the array of contracts
void FleetManager::addContract(VehicleRentalContract *cont)
{
    if (contractAmount < 10)
    {
        contracts[contractAmount] = *cont;
        contractAmount++;
    }
    else
        cout << "There is no more space for another contract: " << endl;
}

// Adds a car to the array of cars
void FleetManager::addCar(Car *car)
{
    if (carAmount < 10)
    {
        cars[carAmount] = *car;
        carAmount++;
    }
    else
        cout << "There is no more space for another car: " << endl;
}

// Adds a truck to the array of trucks
void FleetManager::addTruck(Truck *truck)
{
    if (truckAmount < 10)
    {
        trucks[truckAmount] = *truck;
        truckAmount++;
    }
    else
        cout << "There is no more space for another truck: " << endl;
}

// Adds a customer to the array of customers
void FleetManager::addCustomer(Customer *customer)
{
    if (customerAmount < 10)
    {
        customers[customerAmount] = *customer;
        customerAmount++;
    }
    
    else
        cout << "There is no more space for another customer: " << endl;
}

// Returns a car
void FleetManager::returnCar(Car *c, int reqNum,  int newMileage)
{
    for (int i{0}; i < 10; i++)
        if (cars[i].getID() == c->getID())                  // If this car is identical to one in the fleet
        {
            if (newMileage >= cars[i].getMileage())         // Can't return a car will less mileage then when it was rented
            {
                cars[i].setMileage(newMileage);                 // Set the new mileage
                c->setMileage(newMileage);
                cars[i].setRental(true, cars[i].getDate().getDay(), cars[i].getDate().getMonth());
                //set rental status to available
                cout << "The car has succesfully been returned" << endl;
                return;
                
            }
            else
            {
                cout << "The car cannot be returned with less mileage than it was rented with." << endl;
                return;
            }
        }
    cout << "This vehicle is not with the fleet." << endl;
    return;
}

// Returns a truck
void FleetManager::returnTruck(Truck *t, int reqNum,  int newMileage)
{
    for (int i{0}; i < 10; i++)
        if (trucks[i].getID() == t->getID())
        {
            if (newMileage >= trucks[i].getMileage())
            {
                trucks[i].setMileage(newMileage);
                t->setMileage(newMileage);
                trucks[i].setRental(true, trucks[i].getDate().getDay(), trucks[i].getDate().getMonth());
                cout << "The truck has succesfully been returned" << endl;
                return;
            }
            else
            {
                cout << "The truck cannot be returned with less mileage than it was rented with." << endl;
                return;
            }
        }
    cout << "This vehicle is not with the fleet." << endl;
    return;
}

// Cancels a request
void FleetManager::requestCancel(int reqNum, Date today)
{
    for (int i{0}; i < 10; i++)
        if (requests[i].getRes_num() == reqNum)
        {
            cout << "The request number " << reqNum <<" has been cancelled" << endl;
            for (int j = i; j < 10 - 1; j++)
                // Need to shift the members of the array left to fill the gap of the removed member
            {
                requests[j] = requests[j+1];
            }
            return;
        }
    
    cout << "This reservation number is not valid." << endl;
}

// Process a request payed in cash
int FleetManager::processRequestCash(ReservationRequest rr,CashPayment c)
{
    if (rr.getVehicle_type() == "car")              // if requesting a car
    {
        for (int i{0}; i < 10; i++)
        {
            if (rr.getLimitNum() <= cars[i].getCapacity())  // finds car with capacity greater or equal to demand
            {
                VehicleRentalContract *v;           // creates a new rental contract
                v = new VehicleRentalContract();
                v->setReservation(rr);              // gives it this request
                v->setCashPayment(c);               // gives it the payment
                v->setCar(cars[i]);                 // gives it the car
                addContract(v);                     // adds the contract to the array of contracts
                cout << "The request number " << rr.getRes_num() << " has been succesfully processed." << endl;
                return rr.getRes_num();
            
            }
        }
    }
    
    else        // if trying to add a truck
    {
        for (int i{0}; i < 10; i++)
        {
            if (rr.getLimitNum() <= trucks[i].getWeightlimit())
            {
                VehicleRentalContract *v;
                v = new VehicleRentalContract();
                v->setReservation(rr);
                v->setCashPayment(c);
                v->setTruck(trucks[i]);
                addContract(v);
                cout << "The request number " << rr.getRes_num() << " has been succesfully processed." << endl;
                return rr.getRes_num();
            }
        }
    }
    
    cout << "This request cannot be processed." << endl;
    return 0;
}

// Processing payed in credit
int FleetManager::processRequestCredit(ReservationRequest rr,CreditCardPayment c)
{
    for (int i{0}; i < 10; i++)
    {
        if (rr.getRes_num() == requests[i].getRes_num())
        {
            cout << "This request is already existing." << endl;
            return 0;
        }
    }
    
    if (rr.getVehicle_type() == "car")
    {
        for (int i{0}; i < 10; i++)
        {
            if (rr.getLimitNum() < cars[i].getCapacity())
            {
                VehicleRentalContract *v;
                v = new VehicleRentalContract();
                v->setReservation(rr);
                v->setCreditPayment(c);
                v->setCar(cars[i]);
                addContract(v);
                cout << "The request number " << rr.getRes_num() << " has been succesfully processed." << endl;
                return rr.getRes_num();
            }
        }
    }
    
    else
    {
        for (int i{0}; i < 10; i++)
        {
            if (rr.getLimitNum() < trucks[i].getWeightlimit())
            {
                VehicleRentalContract *v;
                v = new VehicleRentalContract();
                v->setReservation(rr);
                v->setCreditPayment(c);
                v->setTruck(trucks[i]);
                addContract(v);
                cout << "The request number " << rr.getRes_num() << " has been succesfully processed." << endl;
                return rr.getRes_num();
            }
        }
    }
    
    cout << "This request cannot be processed." << endl;
    return 0;
}

