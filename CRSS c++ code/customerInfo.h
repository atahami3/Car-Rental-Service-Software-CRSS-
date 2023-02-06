// ============================ CustomerInfo Header ======================
#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H
#include <iostream>
#include <string>
#include <mysql.h>
#include <stdlib.h>
#include <sstream>
using namespace std; 

class Customer
{
protected:
	string emailAddress;
	string customerFName;
	string customerLName;
	string birthday;
	string driversLicenseNumber;
	string streetAddress;
	string apartmentNumber;
	string cityOfResidence;
	string stateOfResidence;
	string zipCode;
	string customerAge;
	string reservationPickupDate;
	string reservationDropOff;
	string reservationPickupTime;
	string reservationDropoffTime;
	string vSize;
	string password;
	float reservationCost;
	float couponCode;

public:
	Customer();
	~Customer();
	Customer(string emailAddress, string customerFName, string customerLName, string birthday, string customerAge, string driversLicenseNumber, string streetAddress, string apartmentNumber, string cityOfResidence, string stateOfResidence, string zipCode, string reservationPickupDate, string reservationDropOff, string reservationPickupTime, string reservationDropoffTime, string vSize, string password, float reservationCost, float couponCode);
	// -------------------- For Customer Information -----------------------------
	void displayCustomerInfo();
	void customerCount();
	void insertCustomerInfo();
	void deleteCustomerInfo();
	// -------------------------- For Customer reservations ---------------------------
	void makeReservation();
	void deleteReservation(); // Call this function in makeReservation if cutomer doesn't want to complete the transaction. 
	bool completeTransaction(string vMake, string vModel); // Call this function in makeReservation to complete customer transaction. 
	void displayPickupDropoffInfo(); // Call in makeReservation.
	// ------------ Fn's to provide access from main -----------------
	void adminAccessC(Customer c);
	void custAccessC(Customer c);
};
#endif
/* ========================== vehicleData.txt ===========================
Sedan Mid - size Toyota Camry XYZ123F White 32 5 True
Sedan Large Mercedes S500 WGV456T Black 20 5 true
SUV Small Honda CRV YRS789O Red 26 5 True
SUV Large Mercedes G55 YSL655T Blue 16 5 False
Coupe Small Porsche Caymann JHL782V Yellow 2 True
Coupe Mid - sized Chevolet Camaro JKL239J Green False
Coupe Small Honda S2000 YZF639I Silverstone  22 2 False
Coupe small chevy Corvette awm96t black 17 4 false
coupe small Ford Mustange asd92e black 18 4 true
======================================================================== */