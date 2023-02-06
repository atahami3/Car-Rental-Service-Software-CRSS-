// ====================== Vehicle.cpp =================================
#include "vehicle.h"


/* MySQL Server Name */
#define SERVER "localhost"

/* MySQL User Name */
#define USER "root"

/* MySQL Server Password */
#define PASSWORD "password"

/* MySQL Database Name */
#define DATABASE "crss"

// -----------------------------------------------------------------------------
int qState1;
MYSQL* conn1, *conn2, *conn3, *conn4;
MYSQL_ROW row;
MYSQL_RES* res;
// -----------------------------------------------------------------------------

Vehicle::Vehicle()
{
	vVin = "";
	plateNumber = "";
	vType = "";
	vSize = "";
	vMake = "";
	vModel = "";
	color = "";
	vMPG = "";
	vNav = "";
	seatingCapacity = "";
	engineCylinders = "";
	transmissionType = "";

}// constructor 
Vehicle::Vehicle(string vVin, string vType, string vSize, string vMake, string vModel, string plateNumber, string color, string vMPG, string seatingCapacity, string vNav, string engineCylinders, string transmissionType) // overloaded constructor
{
	this->vVin = vVin;
	this->plateNumber = plateNumber;
	this->vType = vType;
	this->vSize = vSize;
	this->vMake = vMake;
	this->vModel = vModel;
	this->color = color;
	this->vMPG = vMPG;
	this->vNav = vNav;
	this->seatingCapacity = seatingCapacity;
	this->engineCylinders = engineCylinders;
	this->transmissionType = transmissionType;

}
Vehicle::~Vehicle()
{
	// destructor
}
void Vehicle::vCount()
{
	//-----------------------------------------------------------------------------------------
	conn1 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn1 = mysql_real_connect(conn1, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------
	 

	// -------------------> If the connection to our MySQL DB was successful, then ....-------------
	if (conn1)
	{
		cout << "Connection to the MySQL Database CRSS was Successful. " << endl;

		// ---------------------------- MySQL Query -----------------------------------------------
		string count_query = "SELECT COUNT(*) FROM vehicles";
		const char* q1 = count_query.c_str();
		qState1 = mysql_query(conn1, q1);
		//-----------------------------------------------------------------------------------------
		
		// ---------------------------- Show Query Results --------------------------------------------
		if (!qState1)
		{
			res = mysql_store_result(conn1);

			while (row = mysql_fetch_row(res))
			{
				cout << "\nThis is the number of Customers in the CRSS database: " << row[0] << endl;
			}
		}
		//--------------------------------------------------------------------------------------------
	}
	// -------- Throw error w/ message if connection is unsuccessful ----------
	else
	{
		printf("MySQL Database Connection Unsuccessful.");
		exit(1);
	}
	// ------------------------------------------------------------------------

	mysql_close(conn1);
	if (conn1 == 0)
	{
		perror("Something went wrong, MySQL connection did not closed. ");
		exit(1);
	}
	/* ------------------------- Explaination -----------------------------
	* mysql_close() deallocates the connection handler pointed to by mysql
	* if the handler was allocated automatically by mysql_init().
	-------------------------------------------------------------------- */
	
	return;
}
void Vehicle::displayVehicle()
{

	conn2 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.
	// ------------------------------ Connecting to MySQL --------------------------------------
	conn2 = mysql_real_connect(conn2, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------
	
	// ---------------------------------------------------------------------------
	// -> If the connection to our MySQL DB was successful, then ....
	if (conn2)
	{
		cout << "\nConnection 2 to the MySQL Database CRSS was Successful. \n" << endl;

		// ----------------------------------------------------------------------------------------
		cout << "These are all the vehicles in the Database: \n\n";
		// ---------------------------- MySQL Query -----------------------------------------------
		string insert_query = "SELECT * FROM vehicles";

		const char* q2 = insert_query.c_str();

		qState1 = mysql_query(conn2, q2);

		if (!qState1)
		{
			res = mysql_store_result(conn2);

			while (row = mysql_fetch_row(res))
			{
				cout << " vVin: " << row[0]
					<< " plateNumber: " << row[1]
					<< " vType: " << row[2]
					<< " vSize: " << row[3]
					<< " vMake: " << row[4]
					<< " vModel: " << row[5]
					<< " color: " << row[6]
					<< " vMPG: " << row[7]
					<< " vNav: " << row[8]
					<< " seatingCapacity: " << row[9]
					<< " engineCylinders: " << row[10]
					<< " transmissionType: " << row[11] << endl << endl;

			}
		}
		// -----------------------------------------------------------------------------------------
		else
		{
			printf("MySQL Database Connection Unsuccessful.");
			exit(1);
		}
		// ------------------------------------------------------------------------

		mysql_close(conn2);
		if (conn2 == 0)
		{
			perror("Something went wrong, MySQL connection did not closed. ");
			exit(1);
		}

		/* ------------------------- Explaination -----------------------------
		* mysql_close() deallocates the connection handler pointed to by mysql
		* if the handler was allocated automatically by mysql_init()
		-------------------------------------------------------------------- */
		return;
	}
}
/* ---------------------------------------- Add Inventory Fn. ------------------------------------------------------
* -> Variables being used in sql Query: vVin, plateNumber, vType, vSize, vMake, vModel, color, vMPG,
* vNav, seatingCapacity, engineCylinders, transmissionType;
*
* -> Parameters being passed: vVin, plateNumber, vType, vSize, vMake, vModel, color, vMPG, vNav, s
* eatingCapacity, engineCylinders, transmissionType;
*
* -> Output:
-------------------------------------------------------------------------------------------------------------------------------- */
void Vehicle::addInventory()
{
	char choice = 'y';
	char choice2 = 'n';

	// ------------------------------------ MySQL Connection 3-----------------------------------------------------
	conn3 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn3 = mysql_real_connect(conn3, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------


	cout << "\n\nWould you like to add a new vehicle? (Y/N): ";
	cin.get(choice);
	cin.ignore();
	cout << endl;

	// -------------------------> If the connection to our MySQL DB was successful, then .... ------------------------------
	if (conn3)
	{
		cout << "\nConnection 3 to the MySQL Database CRSS was Successful. \n" << endl;

		while (toupper(choice == 'y'))
		{
			// -------------------- Using getline we'll take user input and insert the values into the class variables ---------
			cout << "\nPlease enter Vehicle Identification Number: ";
			getline(cin, this->vVin);

			cout << "\nPlease enter Vehicle License Plate Number: ";
			getline(cin, this->plateNumber);

			cout << "Please enter Vehicle Type: ";
			getline(cin, this->vType);

			cout << "\nPlease enter Vehicle Size: ";
			getline(cin, this->vSize);

			cout << "\nPlease enter Vehicle Make: ";
			getline(cin, this->vMake);

			cout << "\nPlease enter Vehicle Model: ";
			getline(cin, this->vModel);

			cout << "\nPlease enter Vehicle Color: ";
			getline(cin, this->color);

			cout << "\nPlease enter Vehicle MPGs: ";
			getline(cin, this->vMPG);

			cout << "\nPlease enter Vehicle Navigation system status (yes or no): ";
			getline(cin, this->vNav);

			cout << "\nPlease enter Vehicle Seating Capacity: ";
			getline(cin, this->seatingCapacity);

			cout << "\nPlease enter the number of Cylinders this vehicle's engine has: ";
			getline(cin, this->engineCylinders);

			cout << "\nPlease enter the Transmission Type this vehicle has: ";
			getline(cin, this->transmissionType);

			// ---------------------------------------------------------------------------
				
			// ----------------------------------------------------------------------------------------
			cout << "These are all the vehicles in the Database: \n\n";
			// ---------------------------- MySQL Query -----------------------------------------------
			string insert_query = "INSERT INTO vehicles VALUES('" + vVin + "', '" + plateNumber + "', '" + vType + "', '" + vSize + "', '" + vMake + "', '" + vModel + "', '" + color + "', '" + vMPG + "', '" + vNav + "','" + seatingCapacity + "','" + engineCylinders + "','" + transmissionType + "')";

			const char* q3 = insert_query.c_str();

			qState1 = mysql_query(conn3, q3);
			
			// --------------- Now display entered vehicles by calling function -------------------
			cout << "Here is the the result of your insert query. \n\n";
			displayVehicle();
			// ------------------------------------------------------------------------------------


			
			// -------------------------------- User Choice to contiune loop ----------------------------------
			cout << "\n\nWould you like to add more vehicles? (Y/N): ";
			cin >> choice2;
			cin.ignore();
			
			if (toupper(choice2 == 'n'))
			{
				cout << "Okay, now redirecting. " << endl << endl;
				break;
			}
			// -----------------------------------------------------------------------------------------

			// -------------------- Connection error handling -------------------------
			else
			{
				printf("MySQL Database Connection Unsuccessful.");
				exit(1);
			}
			// ------------------------------------------------------------------------
		}
	}
	// -------------------------- Closing MySQL conn 3 ----------------------
	mysql_close(conn3);
	if (conn3 == 0)
	{
		perror("Something went wrong, MySQL connection did not closed. ");
		exit(1);
	}
	/* ------------------------- Explaination -----------------------------
	* mysql_close() deallocates the connection handler pointed to by mysql
	* if the handler was allocated automatically by mysql_init().
	-------------------------------------------------------------------- */

	return;
}
// ------------------------------------------------------------------------------------------------------------------
void Vehicle::deleteVehicle()
{
	{
		conn4 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

		// ------------------------------ Connecting to MySQL --------------------------------------
		conn4 = mysql_real_connect(conn4, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
		// -----------------------------------------------------------------------------------------

		char choice = 'y';
		char choice2 = 'y';

		cout << "\n\nWould you like to delete a vehicle? (Y/N): ";
		cin.get(choice);
		cin.ignore();
		cout << endl;

		while (toupper(choice == 'y'))
		{
			// -> If the connection to our MySQL DB was successful, then ....
			if (conn4)
			{

				printf("\n\nConnection 4 to the MySQL Database CRSS was Successful. \n");

				// -------------------- Using getline we'll take user input and insert the values into the class variables ---------
				cout << "\nEnter Vehicle Identification Number: ";
				getline(cin, this->vVin);

				/*cout << "\nEnter Lisence Plate Number: ";
				getline(cin, this->plateNumber);*/

				cout << endl;
				// ---------------------------------------------------------------------------

				// ---------------------------- MySQL Query -----------------------------------------------
				string delete_query = "DELETE FROM vehicles WHERE vVin = '" + vVin + "' "; // AND plateNumber = ('"+ plateNumber +") ???
				const char* q4 = delete_query.c_str();
				qState1 = mysql_query(conn4, q4);

				// --------------- Now display entered customer by calling function -------------------
				cout << "\nHere is the the result of your delete query. \n\n";
				displayVehicle();
				// ------------------------------------------------------------------------------------

				// -------------------------------- User Choice to contiune loop ----------------------------------
				cout << "\n\nWould you like to continue deleting vehicles? (Y/N): ";
				cin.get(choice2);
				cin.ignore();
				cout << endl;

				if (toupper(choice2 != 'y'))
				{
					printf("\n\nNow exiting SQL delete Query. ");
					break;
				}
				// ---------------------------------------------------------------------------------------------------

				/*
				CYG739IBAH1128B32 HZS577T --> 760Li
				KYG739IKAH1528K01 OGS584P --> 370z
				*/
			}
			// -------------------- Connection error handling -------------------------
			else
			{
				printf("\n\nMySQL Database Connection Unsuccessful.");
				exit(1);
			}
			// ------------------------------------------------------------------------
			//system("cls"); // Clear screen at end of loop
		}
		// ------------------------------- Close MySQL Conn 8 -----------------------------------------
		mysql_close(conn4);
		if (conn4 == 0)
		{
			perror("\n\nSomething went wrong, MySQL connection did not closed. ");
			exit(1);
		}
		/* ------------------------- Explaination -----------------------------
		* mysql_close() deallocates the connection handler pointed to by mysql
		* if the handler was allocated automatically by mysql_init().
		-------------------------------------------------------------------- */
		return;
	}
}
void Vehicle::adminAccessV(Vehicle v)
{
	char choice1 = 'd';
	char choice2 = 'y';
	/* ========================================= Calling Customer Class Functions ==================================================================
	* -> Each instance of the Customer class and its functions will prompt the user to add the required information and return them to main where
	* each value is stored into variable and inserted into the MySQL DB.
	*
	* -> Variables: driversLicenseNumber, customerFName, customerLName, customerAge, cityOfResidence; apartmentNumber,
	*  streetAddress, stateOfResidence, & zipCode.
	// ------------------------------------------------- Executing Vehicle Class-Instance Functions ------------------------------------------------- */
	do {

		cout << "\nFor Display Vehicle Information (select [D]) \n"
			<< "For Vehicle Count (select [C]) \n"
			<< "To Insert New Vehicle Inventory (select [N]) \n"
			<< "To Delete Vehicle from Inventory (select [B]):: ";

		cin.get(choice1);
		cin.ignore();
		cout << endl;

		switch (toupper(choice1))
		{
			// ---------------------- choice1 = A -------------------------
		case 'D':
			cout << "\nYou've selected to Display Vehicle Information: ";
			v.displayVehicle();
			break;
		case 'C':
			cout << "\nYou've selected to Display Vehicle Count: ";
			v.vCount();
			break;
		case 'N':
			cout << "\nYou've selected to Insert New Vehicle Inventory: ";
			v.addInventory();
			break;
		case 'B':
			cout << "\nYou've selected to Delete Vehicle from Inventory: ";
			v.deleteVehicle();
			break;
		}

		cout << "\nWould you like to return to the Vehicle Data menu? "
			<< "( Y or N ) ";
		cin.get(choice2);
		cin.ignore();
		cout << endl;
		system("cls");

	} while (toupper(choice2 == 'y'));

	return;

	/* -------------------------------------------------------------- END Execution -------------------------------------------------------------- */
}
/* ------------------------------------ deleteVehicle() OUTPUT ---------------------------------------------------
Connection 2 to the MySQL Database CRSS was Successful.

These are all the vehicles in the Database:

 vVin: AYG739IKAH1528Z91 plateNumber: SWS5840 vType: coupe vSize: Small vMake: Chevrolet vModel: Camaro color: Black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: Manual

 vVin: CYG739IBAH1128B32 plateNumber: HZS577T vType: Sedan vSize: Large vMake: BMW vModel: 760Li color: Blue vMPG: 19 vNav: True seatingCapacity: 5 engineCylinders: 8 transmissionType: Automatic

 vVin: CYG739IKAH1528B32 plateNumber: HWS584I vType: SUV vSize: Small vMake: Honda vModel: CRV color: Blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: Automatic

 vVin: CYG739IKAH1528F09 plateNumber: HWS579T vType: Sedan vSize: Large vMake: Mercedes vModel: e550 color: Black vMPG: 30 vNav: yes seatingCapacity: 5 engineCylinders: 8 transmissionType: Automatic

 vVin: KYG739IKAH1528K01 plateNumber: OGS584P vType: coupe vSize: Small vMake: Nissan vModel: 370z color: White vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: Manual

 --------------------------------------------- Deleting... ----------------------------------------------------------
Would you like to delete a vehicle? (Y/N): y



Connection 4 to the MySQL Database CRSS was Successful.

Enter Vehicle Identification Number: CYG739IBAH1128B32


Here is the the result of your delete query.


Connection 2 to the MySQL Database CRSS was Successful.

These are all the vehicles in the Database:

 vVin: AYG739IKAH1528Z91 plateNumber: SWS5840 vType: coupe vSize: Small vMake: Chevrolet vModel: Camaro color: Black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: Manual

 vVin: CYG739IKAH1528B32 plateNumber: HWS584I vType: SUV vSize: Small vMake: Honda vModel: CRV color: Blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: Automatic

 vVin: CYG739IKAH1528F09 plateNumber: HWS579T vType: Sedan vSize: Large vMake: Mercedes vModel: e550 color: Black vMPG: 30 vNav: yes seatingCapacity: 5 engineCylinders: 8 transmissionType: Automatic

 vVin: KYG739IKAH1528K01 plateNumber: OGS584P vType: coupe vSize: Small vMake: Nissan vModel: 370z color: White vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: Manual



Would you like to continue deleting vehicles? (Y/N): n



Now exiting SQL delete Query. Press any key to continue . . .
*/