// Driver file for the vehicle renting system

#include "payment.h"
#include "cashPayment.h"
#include "creditCardPayment.h"
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Customer.h"
#include "ReservationRequest.h"
#include "FleetManager.h"
#include <string>
#include <array>
#include <iostream>
using namespace std;

int main()
{

    // Creating a Car
    
    string* vehicle_model;
    vehicle_model = new string("model_name");
    
    int vehicle_mileage = 10000;
    
    string* vehicle_id;
    vehicle_id = new string("4009");
    
    Date* vehicle_date;
    vehicle_date = new Date(12, 12, 2019);
    
    bool vehicle_rental[12][30];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 30; j++) {
            vehicle_rental[i][j] = true; // true = available to rent on a given date
        }
    }
    vehicle_rental[5][5] = false; //date 6/6
    
    // Testing the constructor which sets information about a vehicle object
    Car *vehicle2;
    vehicle2 = new Car(*vehicle_model, *vehicle_date, vehicle_mileage, *vehicle_id, vehicle_rental, 4);
    
    cout << "***Testing the construction of car***" << endl << endl;
    vehicle2->print();
    cout << endl << endl;
    
    // Empty vehicle constructor test
    Car *vehicle1;
    vehicle1 = new Car();
    cout << "***Testing the empty constructor of car***" << endl << endl;
    vehicle1->print();
    cout << endl << endl;
    string *vehicle_model2;
    vehicle_model2 = new string("model_name2");

    string *vehicle_id2;
    vehicle_id2 = new string("4010");
    
    vehicle1->setModel(*vehicle_model2); // Sets the vehicle model
    vehicle1->setDate(13, 11, 2019); // Sets the date the vehicle joined the rental fleet
    vehicle1->setMileage(2000); // Sets the vehicle mileage
    vehicle1->setID(*vehicle_id2); // Sets the vehicle ID
    vehicle1->setRental(false, 1, 1); // Sets the vehicle's rental status for a certain date
    
    cout << "***Checking the rental status of a vehicle created with empty constructor, should return that it is rented for this day***" << endl << endl;
    cout << "Rental status for 1/1/2019 (1 = available, 0 = rented): " << vehicle1->checkRental(1, 1) << endl; // Checks the vehicle's rental status for a certain date
    cout << endl << endl;

    
    // Testing the copy constructor
    Car *vehicle3;
    vehicle3 = vehicle2;
    
    cout << "***Testing the copy constructor on car***" << endl << endl;
    vehicle3->print();
    cout << endl;
    
    // Creating a Truck
    Truck *truck1;
    truck1 = new Truck();
    
    truck1->setModel(*vehicle_model);
    truck1->setDate(vehicle_date); // Testing the setDate function using a date object
    truck1->setMileage(vehicle_mileage);
    truck1->setID(*vehicle_id);
    truck1->setRental(false, 1, 1);
    truck1->setWeightlimit(2000); // Sets the truck's weight limit
    
    cout << "***Testing the construction of a truck***" << endl << endl;
    truck1->print();
    cout << endl << endl;
    
    // Creating a second Truck
    Truck *truck2;
    string *vehicleModel;
    string *vehicleID;
    vehicleModel = new string("make 124");
    vehicleID = new string("1242");
    Date* vehicle_date2;
    vehicle_date2 = new Date(10, 5, 2019);
    truck2 = new Truck(*vehicleModel, *vehicle_date2, 12422, *vehicleID, vehicle_rental, 4000);
    
    //Creating a Customer
    Customer *customer1;
    customer1 = new Customer();

    string *customer_name;
    customer_name= new string("John Smith");

    string *drivers_license;
    drivers_license = new string("ABC 123");

    int day = 1, month = 2, year = 1990;
    Date date1(day, month, year);

    customer1->setName(customer_name); // Sets customer name
    customer1->setLicense(drivers_license); // Sets the customer's driver's license
    customer1->setDOB(day,month,year); // Sets the customer's date of birth
    
    cout << "***Testing the construction of a customer*** " << endl << endl;
    cout << "Customer name: " << customer1->getName() << endl;
    cout << "Customer's license: " << customer1->getLicense() << endl;
    cout << "Customer's birthday: ";
    customer1->getDOB().getDate();
    cout << endl << endl;
    
    // Creating a Second Customer
    Customer *customer2;
    string *customerName;
    customerName = new string("Jane Smith");
    
    string *driversLicense;
    driversLicense = new string("XYZ 789");
    
    Date DOB(2,12,1997);
    customer2 = new Customer(*customerName,*driversLicense, DOB);
    
    // Creating a Reservation Request
    Date date2(3, 5, 2019);
    
    Date date3(4, 5, 2019);
    
    string * vehicle_type1;
    vehicle_type1 = new string("car");
    ReservationRequest *request1;
    request1 = new ReservationRequest(*customer1,*vehicle_type1,date1,date2,date3,4); // Constructor which sets the information about a reservation request
    
    // Creating a new Reservation Request
    ReservationRequest *request2;
    Date date4(6,6,2019);
    Date date5(7,7,2019);
    string *vehicle_type2;
    vehicle_type2 = new string("truck");
    request2 = new ReservationRequest(*customer2, *vehicle_type2, date1, date4, date5,1000);
    
    cout << "***Testing the construction of a reservation request***" << endl << endl;
    request1 -> print();
    cout << endl << endl;
    
    // Creating a Payment
    CashPayment *c;
    c = new CashPayment{1042.53};
    
    CreditCardPayment *d;
    d = new CreditCardPayment{"Kevin Sidhu", "123456789", 2000.42};
    
    cout << "***Testing the construction of a cash payment***" << endl << endl;
    c->paymentDetails();
    cout << endl << endl;
    
    cout << "***Testing the construction of a credit card payment***" << endl << endl;
    d->paymentDetails();
    cout << endl << endl;

    // Creating a Vehicle Rental Contract
    VehicleRentalContract *contract;
    
    contract = new VehicleRentalContract();
    contract->setReservation(*request1);
    contract->setCar(*vehicle2);
    contract->setCashPayment(*c);
    
    cout << "***Testing the construction of a Vehicle Rental Contract***" << endl << endl;
    contract->print();
    cout << endl << endl;
    
    // Creating a Fleet Manager
    FleetManager *f;
    f = new FleetManager();
    f->addContract(contract);
    f->addRequest(request1);
    f->printContractDetails(1);
    f->addCar(vehicle2);
    f->addTruck(truck1);
    f->addCustomer(customer1);
    f->addCustomer(customer2);
    
    
    // Adding the request to Fleet Manager
    f->addTruck(truck1);
    cout << "***Printing out the details of a rental contract by the request number 1***" << endl << endl;
    f->printContractDetails(1);
    cout << endl << endl;
    cout << "***Processing request number 2***" << endl << endl;
    f->processRequestCredit(*request2, *d);
    cout << endl << endl;
    cout << "***Attempting to process request number 1, which has already been processed***" << endl << endl;
    f->processRequestCash(*request1, *c);
    cout << endl << endl;
    cout << "***Trying to return a vehicle with a mileage lower than what it was rented with***" << endl << endl;
    f->returnCar(vehicle2, 2, 100);
    cout << endl << endl;
    cout << "***Cancelling the request number 1***" << endl << endl;
    f->requestCancel(1, date2);
    cout << endl << endl;
    cout << "***Returning the request number 2***" << endl << endl;
    f->returnTruck(truck1, 2, 20000);
    cout << endl << endl;
    cout << "***Trying to return a vehicle that is not with the fleet***" << endl << endl;
    f->returnTruck(truck2, 3, 30000);
    cout << endl << endl;
   
    
}
