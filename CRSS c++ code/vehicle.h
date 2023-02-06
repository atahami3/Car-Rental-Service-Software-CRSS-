// ================================ Vehicle Header ==============================
//#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
#include <mysql.h>
#include <stdlib.h>
using namespace std;



class Vehicle
{

protected: // b/c we want to be able to access and view these details outside the class. [inheritance]
	string vVin;
	string plateNumber;
	string vType;
	string vSize;
	string vMake;
	string vModel;
	string color;
	string vMPG;
	string vNav;
	string seatingCapacity;
	string engineCylinders;
	string transmissionType;
	


public:
	Vehicle();// constructor 
	Vehicle(string vVin, string vType, string vSize, string vMake, string vModel, string plateNumber, string color, string vMPG, string seatingCapacity, string vNav, string engineCylinders, string transmissionType); // overloaded constructor
	~Vehicle(); // destructor
	void vCount();
	void displayVehicle();
	void addInventory();
	void deleteVehicle();
	// ------------ Fn's to provide access from main -----------------
	void adminAccessV(Vehicle v);
	
	/* --------------------------------------
	void custAccessV(Vehicle v);
	void Vehicle::custAccessV(Vehicle v)
	{
		v.displayVehicle();
	}
	---------------------------------------*/
};
#endif 

//==================================================================================================