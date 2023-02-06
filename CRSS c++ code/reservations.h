
// ================================ Reservations Header ==============================
#ifndef RESERVATIONS_H
#define RESERVATIONS_H
#include <iostream>
#include <string>
#include <mysql.h>
#include <stdlib.h>
using namespace std;



class Reservations
{

protected: // b/c we want to be able to access and view these details outside the class. [inheritance]
	string reservationPickupDate;
	int reservationDuration;
	string reservationPickupTime;
	string reservationDropoffTime;
	float vSzieCost;
	float costPerDuration;
	float couponCode; 
	

public:
	Reservations();// constructor 
	Reservations(string reservationPickupDate, int reservationDuration, string reservationPickupTime, string reservationDropoffTime, float vSzieCost, float costPerDuration, float couponCode); // overloaded constructor
	~Reservations(); // destructor
	void makeReservation();
	void deleteReservation();
	void estimateCost(); // call this function in makeReservation to estimate the cost for customer before they make the reservation.
	void displayPickupDropoffInfo(); // call in makeReservation.
	void adminAccessV(Reservations r);
	void custAccessV(Reservations r);

};
#endif 

//==================================================================================================