// Header file of the class FleetManager


#include <iostream>
#include "Date.h"
#include "Car.h"
#include "Truck.h"
#include "Customer.h"
#include "VehicleRentalContract.h"
#include "ReservationRequest.h"

class FleetManager                                      // class which manages the interactions between all the other classes
{
    
public:
    
    FleetManager();                                                         // Empty Constructor
    virtual ~FleetManager();                                                // Destructor
    
    int processRequestCash(ReservationRequest, CashPayment c);              // Processes the request of someone paying in cash
    int processRequestCredit(ReservationRequest, CreditCardPayment c);      // Processes the request of one paying in credit
    
    void printContractDetails(int reqNum);                                  // Prints all the details about a contract
    
    void requestCancel(int reqNum, Date today);                             // Cancels a reservation request
    
    void addRequest(ReservationRequest *req);                               // Adds a request to the array
    void addContract(VehicleRentalContract *cont);                          // Adds a contract to the array
    void addCar(Car *car);                                                  // Adds a car to the array
    void addTruck(Truck *truck);                                            // Adds a truck to the array
    void addCustomer(Customer *customer);                                   // Adds a customer to the array
    
    void returnCar(Car *c, int reqNum, int newMileage);                     // Processes the return of a rental car
    void returnTruck(Truck *t, int reqNum, int newMileage);                 // Processes the return of a rental truck
    
private:
    int requestAmount;                                                      // Amount of requests
    int contractAmount;                                                     // Amount of contracts
    int carAmount;                                                          // Amount of cars, equivalent of carfleet_size
    int truckAmount;                                                        // Amount of trucks, equivalent of truckfleet_size
    int customerAmount;                                                     // Amount of customers
    
    Car cars[10];                                                           // Array of cars
    Truck trucks[10];                                                       // Array of trucks
    Customer customers[10];                                                 // Array of customers
    VehicleRentalContract contracts[10];                                    // Array of contracts
    ReservationRequest requests[10];                                        // Array of requests
    
};
