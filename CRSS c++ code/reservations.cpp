#include "reservations.h"

/* MySQL Server Name */
#define SERVER "localhost"

/* MySQL User Name */
#define USER "root"

/* MySQL Server Password */
#define PASSWORD "password"

/* MySQL Database Name */
#define DATABASE "crss"

/*---------------------------------------------------
* Got build error when these weren't commented out.
* ---------------------------------------------------
*	int qState3;
*	MYSQL* conn10, * conn11, * conn12, * conn13;
*	MYSQL_ROW row;
*	MYSQL_RES* res;
-------------------------------------------------- */

Reservations::Reservations()
{
	reservationPickupDate = " ";
	reservationDuration = 0;
	reservationPickupTime = " ";
	reservationDropoffTime = " ";
	vSzieCost = 0.0;
	costPerDuration = 0.0;
	couponCode = 0.0;
}
// ------------------------------------------------------------------------------------------------------------------
Reservations::Reservations(string reservationPickupDate, int reservationDuration, string reservationPickupTime, string reservationDropoffTime, float vSzieCost, float costPerDuration, float couponCode)
{
	this->reservationPickupDate = reservationPickupDate;
	this->reservationDuration = reservationDuration;
	this->reservationPickupTime = reservationPickupTime;
	this->reservationPickupTime = reservationDropoffTime;
	this->vSzieCost = vSzieCost;
	this->costPerDuration = costPerDuration;
	this->couponCode = couponCode;
}
// ============================================================================================================================================
Reservations::~Reservations()
{
	//Destructor 
}
// ============================================================================================================================================
void Reservations::makeReservation()
{
	return;
}
// ============================================================================================================================================
void Reservations::deleteReservation()
{
	return;
}
// ============================================================================================================================================
void Reservations::estimateCost()
{
	return;
}
// ============================================================================================================================================
void Reservations::displayPickupDropoffInfo()
{
	return;
}
// ============================================================================================================================================