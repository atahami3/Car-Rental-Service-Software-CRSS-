// ======================================== CustomerInfo.cpp ======================================
#include "customerInfo.h"
//using namespace std;

/* MySQL Server Name */
#define SERVER "localhost"

/* MySQL User Name */
#define USER "root"

/* MySQL Server Password */
#define PASSWORD "password"

/* MySQL Database Name */
#define DATABASE "crss"

// -----------------------------------------------------------------------------
int qState2;
MYSQL* conn6, *conn7, *conn8, *conn9, * conn10, * conn11, * conn12, * conn13;
MYSQL_ROW row2;
MYSQL_RES* res2;
// -----------------------------------------------------------------------------

//==================================================================
Customer::Customer()
{
	password = "";
	emailAddress = "";
	customerFName = "";
	customerLName = "";
	birthday = "";
	customerAge = "";
	driversLicenseNumber = "";
	streetAddress = "";
	apartmentNumber = "";
	cityOfResidence = "";
	stateOfResidence = "";
	zipCode = "";
	// --------------- For Customer Reservations ---------------
	reservationPickupDate = " ";
	reservationDropOff = " ";
	reservationPickupTime = " ";
	reservationDropoffTime = " ";
	vSize = " ";
	reservationCost = 0.0;
	couponCode = 0.0;
}
//==================================================================
Customer::~Customer() {}
//==================================================================
Customer::Customer(string emailAddress, string customerFName, string customerLName, string birthday, string customerAge, string driversLicenseNumber, string streetAddress, string apartmentNumber, string cityOfResidence, string stateOfResidence, string zipCode, string reservationPickupDate, string reservationDropOff, string reservationPickupTime, string reservationDropoffTime, string vSize, string password, float reservationCost, float couponCode)
{
	// -------------- For Customer Information -----------------
	this->password = password;
	this->emailAddress = emailAddress;
	this->customerFName = customerFName;
	this->customerLName = customerLName;
	this->birthday = birthday;
	this->customerAge = customerAge;
	this->driversLicenseNumber = driversLicenseNumber;
	this->streetAddress = streetAddress;
	this->apartmentNumber = apartmentNumber;
	this->cityOfResidence = cityOfResidence;
	this->stateOfResidence = stateOfResidence;
	this->zipCode = zipCode;
	// --------------- For Customer Reservations ---------------
	this->reservationPickupDate = reservationPickupDate;
	this->reservationDropOff = reservationDropOff;
	this->reservationPickupTime = reservationPickupTime;
	this->reservationPickupTime = reservationDropoffTime;
	this->vSize = vSize;
	this->reservationCost = reservationCost;
	this->couponCode = couponCode;
}
// ============================================================================================================================================
void Customer::displayCustomerInfo()
{
	conn6 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn6 = mysql_real_connect(conn6, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------
		// -> If the connection to our MySQL DB was successful, then ....
	if (conn6)
	{
		cout << "Connection 6 to the MySQL Database CRSS was Successful. \n" << endl;

		// ---------------------------- MySQL Query -----------------------------------------------
		string display_query = "SELECT * FROM customers";

		const char* q1 = display_query.c_str();
		qState2 = mysql_query(conn6, q1);

		if (!qState2)
		{
			res2 = mysql_store_result(conn6);

			while (row2 = mysql_fetch_row(res2))
			{
			
				cout << "Drivers License Number: " << row2[0]
					<< " Email Address: " << row2[1]
					<< " Password: " << row2[2]
					<< " Customer First Name: " << row2[3]
					<< " Customer Last Name:" << row2[4]
					<< " Customer Birthday: " << row2[5]
					<< " City Of Residence: " << row2[6]
					<< " Apartment Number: " << row2[7]
					<< " Street Address: " << row2[8]
					<< " State Of Residence: " << row2[9]
					<< " Zip Code: " << row2[10]
					<< " Customer Age: " << row2[11] << endl << endl;
			}
			// -----------------------------------------------------------------------------------------

		}
	}
	// -------- Throw error w/ message if connection is unsuccessful ----------
	else
	{
		printf("MySQL Database Connection Unsuccessful.");
		exit(1);
	}
	// ------------------------------------------------------------------------

	mysql_close(conn6);
	if (conn6 == 0)
	{
		perror("Something went wrong, MySQL connection did not closed. ");
		exit(1);
	}
	/* ------------------------- Explaination -----------------------------
	* mysql_close() deallocates the connection handler pointed to by mysql
	* if the handler was allocated automatically by mysql_init().
	-------------------------------------------------------------------- */
}
// ============================================================================================================================================
void Customer::customerCount()
{
	conn7 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn7 = mysql_real_connect(conn7, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------
		// -> If the connection to our MySQL DB was successful, then ....
		if (conn7)
		{
			cout << "\n\nConnection 7 to the MySQL Database CRSS was Successful. \n" << endl;

			// ---------------------------- MySQL Query -----------------------------------------------
			string count_query = "SELECT COUNT(*) FROM customers";
			const char* q2 = count_query.c_str();
			qState2 = mysql_query(conn7, q2);

			if (!qState2)
			{
				res2 = mysql_store_result(conn7);

				while (row2 = mysql_fetch_row(res2))
				{
					cout << "\nThis is the number of customers in the CRSS database: " << row2[0] << endl << endl;
				}
				// -----------------------------------------------------------------------------------------

				// ---------- Test -----------
				//int count = row[0];
				//cout << "Count is: " << row[0] << endl << endl;
				// --------------------------------------------------
			}
		}
		// -------- Throw error w/ message if connection is unsuccessful ----------
		else
		{
			printf("MySQL Database Connection Unsuccessful.");
			exit(1);
		}
		// ------------------------------------------------------------------------

		mysql_close(conn7);
		if (conn7 == 0)
		{
			perror("Something went wrong, MySQL connection did not closed. ");
			exit(1);
		}
		/* ------------------------- Explaination -----------------------------
		* mysql_close() deallocates the connection handler pointed to by mysql
		* if the handler was allocated automatically by mysql_init().
		-------------------------------------------------------------------- */

		return;
}// ============================================================================================================================================
/* ------------------------------------------ - INSERT VALUES INTO CUSTOMER QUERY----------------------------------------------
	* Now we'll be inserting the user obtained data using the variables they were stored into through the SQL INSERT function.
	*
	* -> Variables: driversLicenseNumber, customerFName, customerLName, customerAge, cityOfResidence; apartmentNumber,
	* streetAddress, stateOfResidence, & zipCode.
	*
	* -> We created a string insert_query2 variable
	*
	*
----------------------------------------------------------------------------------------------------------------------------- */
void Customer::insertCustomerInfo()
{
	conn8 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn8 = mysql_real_connect(conn8, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------

	char choice = 'y';
	char choice2 = 'y';

	cout << "\n\nWould you like to add a new customer? (Y/N): ";
	cin.get(choice);
	cin.ignore();
	cout << endl;

	while (toupper(choice == 'y'))
	{
	
		// -> If the connection to our MySQL DB was successful, then ....
		if (conn8)
		{
			printf("\n\nConnection 9 to the MySQL Database CRSS was Successful. \n");
			// -------------------- Using getline we'll take user input and insert the values into the class variables ---------
			cout << "\nEnter Driver's License Number: ";
			getline(cin, this->driversLicenseNumber);

			cout << "\n Enter Email Address: ";
			getline(cin, this->emailAddress);

			cout << "\n Enter a Password for your account: ";
			getline(cin, this->password);

			cout << "\nPlease enter your first name: ";
			getline(cin, this->customerFName);

			cout << "\nEnter Last Name: ";
			getline(cin, this->customerLName);

			cout << "\nEnter Birthday: ";
			getline(cin, this->birthday);

			cout << "\nEnter City of Residence: ";
			getline(cin, this->cityOfResidence);

			cout << "\nPlease enter the Apartment Number, however if none exists then add N/A: ";
			getline(cin, this->apartmentNumber);

			cout << "\nEnter your Street Address: ";
			getline(cin, this->streetAddress);

			cout << "\nEnter State of Residence: ";
			getline(cin, this->stateOfResidence);

			cout << "\nEnter Zip Code: ";
			getline(cin, this->zipCode);

			cout << "\nPlease enter your current age: ";
			getline(cin, this->customerAge);

			cout << endl;
			// ---------------------------------------------------------------------------

			// ---------------------------- MySQL Query -----------------------------------------------
			string insert_query = "INSERT INTO customers VALUES('" + this->driversLicenseNumber + "', '"+ this->emailAddress +"', '"+ this->password +"', '" + this->customerFName + "', '" + this->customerLName + "', '" + this->birthday + "', '" + this->cityOfResidence + "', '" + this->apartmentNumber + "', '" + this->streetAddress + "', '" + this->stateOfResidence + "', '" + this->zipCode + "', '" + this->customerAge + "' )";

			const char* q3 = insert_query.c_str();
			qState2 = mysql_query(conn8, q3);

			// --------------- Now display entered customer by calling function -------------------
			cout << "Your account has been created. \n\n";
			// only meant to display for testing purpose. 
			displayCustomerInfo();
			// ------------------------------------------------------------------------------------
			
			// -------------------------------- User Choice to contiune loop ----------------------------------
			cout << "\n\nWould you like to continue addding new customers? (Y/N): ";
			cin.get(choice2);
			cin.ignore();
			cout << endl;

			if (toupper(choice2 != 'y'))
			{
				printf("\n\nNow exiting SQL insert Query. ");
				//exit(1);
			}
			// ---------------------------------------------------------------------------------------------------
		}
		// -------------------- Connection error handling -------------------------
		else
		{
			printf("\n\nMySQL Database Connection Unsuccessful.");
			exit(1);
		}
		// ------------------------------------------------------------------------
	}
	// ------------------------------- Close MySQL Conn 8 -----------------------------------------
	mysql_close(conn8);
	if (conn8 == 0)
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
// ============================================================================================================================================
void Customer::deleteCustomerInfo()
{
	conn9 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn9 = mysql_real_connect(conn9, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------
	
	char choice = 'y';
	char choice2 = 'y';

	cout << "\n\nWould you like to delete a customer? (Y/N): ";
	cin.get(choice);
	cin.ignore();
	cout << endl;

	while (toupper(choice == 'y'))
	{
		// -> If the connection to our MySQL DB was successful, then ....
		if (conn9)
		{
			
			printf("\n\nConnection 9 to the MySQL Database CRSS was Successful. \n");

			// -------------------- Using getline we'll take user input and insert the values into the class variables ---------
			cout << "\nEnter Driver's License Number: ";
			getline(cin, this->driversLicenseNumber);
			
			/* ---------------------- NEED to add email address --------------------------
			cout << "\nEnter email address: ";
			getline(cin, this->emailAddress);
			--------------------------------------------------------------------------- */

			cout << endl;
			// ---------------------------------------------------------------------------

			// ---------------------------- MySQL Query -----------------------------------------------
			string delete_query = "DELETE FROM customers WHERE driversLicenseNumber = '" + this->driversLicenseNumber + "' ";
			const char* q4 = delete_query.c_str();
			qState2 = mysql_query(conn9, q4);

			// --------------- Now display entered customer by calling function -------------------
			cout << "\nHere is the result of the delete query. \n\n";
			// Only meant for testing purposes. 
			displayCustomerInfo();
			// ------------------------------------------------------------------------------------

			// -------------------------------- User Choice to contiune loop ----------------------------------
			cout << "\n\nWould you like to continue deleting customers? (Y/N): ";
			cin.get(choice2);
			cin.ignore();
			cout << endl;

			if (toupper(choice2 != 'y'))
			{
				printf("\n\nNow exiting SQL delete Query. ");
				break;
			}
			// ---------------------------------------------------------------------------------------------------
		}
		// -------------------- Connection error handling -------------------------
		else
		{
			printf("\n\nMySQL Database Connection Unsuccessful.");
			exit(1);
		}
		// ------------------------------------------------------------------------

	}
	// ------------------------------- Close MySQL Conn 8 -----------------------------------------
	mysql_close(conn9);
	if (conn9 == 0)
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
// ============================================================================================================================================
void Customer::makeReservation()
{
	conn10 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn10 = mysql_real_connect(conn10, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------

	int year = 0;
	int	month = 0; 
	int day = 0;
	int hour = 0;
	int minute = 0;
	string word =" ";
	stringstream ss1(this->reservationPickupDate);
	stringstream ss2(this->reservationDropOff);
	stringstream ss3(this->reservationPickupTime);
	stringstream ss4(this->reservationDropoffTime);
	char dash = '-';
	char colon = ':';

	string vMake = " ";
	string vModel = " ";
	string plateNum = " ";
	//char choice1 = 'n';
	char choice2 = 'y';
	char choice3 = 'c';

	bool isTransactionComplete = false;

	cout << "\n\nLet's make a reservation! \n\n";
	
		// do {

			// -> If the connection to our MySQL DB was successful, then ....
			if (conn10)
			{
				printf("Connection 10 to the MySQL Database CRSS was Successful. \n");

				// -------------------- Using getline we'll take user input and insert the values into the class variables ---------
				cout << "\nWhat date would you like to being your reservation on? "
					<< "\nPlease enter year: ";
				cin >> year;
				cout << "Enter month: ";
				cin >> month;
				cout << "Enter the day: ";
				cin >> day;
				cin.ignore();
				ss1 << year << dash << month << dash << day;
				ss1 >> this->reservationPickupDate;

				// ------------------------ TEST ----------------------------------------------------------
				 cout << "  \n" << this->reservationPickupDate; // << "   " << year << " " << month << " " << day;
				// -----------------------------------------------------------------------------------------
				cout << "\nEnter reservation dropoff date? "
					<< "\nPlease enter year: ";
				cin >> year;
				cout << "Enter month: ";
				cin >> month;
				cout << "Enter the day: ";
				cin >> day;
				cin.ignore();
				ss2 << year << dash << month << dash << day;
				ss2 >> this->reservationDropOff;

				// ------------------------ TEST ----------------------------------------------------------
				cout << "  \n" << this->reservationDropOff; // << "   " << year << " " << month << " " << day;
				// -----------------------------------------------------------------------------------------

				cout << "\nWhat time will you be picking up the vehicle? "
					<< "\nDefault date format is (HH:MM): ";
				getline(cin, this->reservationPickupTime);

				cout << "\nWhat time will you be dropping off the vehicle? "
					<< "\nDefault date format is (HH:MM): ";
				getline(cin, this->reservationDropoffTime);


				//---------------------- test --------------------------
				/*cout << "\nreservationPickupDate: " << this->reservationPickupDate << endl
					<< "\reservationDuration: " << this->reservationDropOff << endl
					<< "\reservationPickupTime: " << this->reservationPickupTime << endl
					<< "\reservationDropoffTime: " << this->reservationDropoffTime << endl; 
				//--------------------------------------------------------------------------- */

			
				// ---------------------------------------------------------------------------

				// -------------------------------- MySQL Query selecting everything from our DB -----------------------------------------------
				string display_query = "SELECT * FROM vehicles";

				const char* q6 = display_query.c_str();

				qState2 = mysql_query(conn10, q6);

				if (!qState2)
				{
					res2 = mysql_store_result(conn10);

					while (row2 = mysql_fetch_row(res2))
					{
						cout << "\n plateNumber: " << row2[1]
							<< " vType: " << row2[2]
							<< " vSize: " << row2[3]
							<< " vMake: " << row2[4]
							<< " vModel: " << row2[5]
							<< " color: " << row2[6]
							<< " vMPG: " << row2[7]
							<< " vNav: " << row2[8]
							<< " seatingCapacity: " << row2[9]
							<< " engineCylinders: " << row2[10]
							<< " transmissionType: " << row2[11] << endl << endl;

					}
				}
				// -------------------------------------------- User selects vehicle make & model -----------------------------------
				cout << "Please enter the vehicle make you would like to rent? ";
				getline(cin, vMake);
				cout << endl;

				cout << "Please enter the vehicle model you would like to rent? ";
				getline(cin, vModel);
				cout << endl;
				// ------------------------------------------------------ This query will select everything from the madeFor table ----------------------------------------------------------------------
				string check_availability_query = " SELECT * FROM madefor WHERE(vehicleMake = '"+ vMake +"' && vehicleModel = '"+ vModel +"') && (resPickupD >= '"+ this->reservationPickupDate +"' && resDropoffD <= '"+ this->reservationDropOff +"') ";
				const char* q5 = check_availability_query.c_str();
				qState2 = mysql_query(conn10, q5);

				if (!qState2)
				{
					res2 = mysql_store_result(conn10);


					while (row2 = mysql_fetch_row(res2))
					{
						cout << "\n Lisence Plate Number: " << row2[0]
							<< " Reservation ID: " << row2[1]
							<< " Vehicle Make: " << row2[2]
							<< " Vehicle Model: " << row2[3]
							<< " Reservation Pickup Date: " << row2[4]
							<< " Reservation Dropoff Date: " << row2[5]
							<< " Reservation Pickup Time: " << row2[6]
							<< " Reservation Dropoff Time: " << row2[7] << endl;

						// -----------------------------------------------------------------------------------------------------------------------------------------------
						// Now we will search through every iteration of the results to see if the user entered details,
						// vMake && vModel && reservationPickupDate && reservationDropOff all match, if these detail match then the vehile is already reserved and not
						// available for rent during those periods. 
						// -----------------------------------------------------------------------------------------------------------------------------------------------
						// if ((vMake == row2[2]) && (vModel == row2[3]) && (this->reservationPickupDate >= row2[4]) && (this->reservationDropOff <= row2[5]))
						
						// ------------------------------------------- NOTE -------------------------------------------------------
						// If there is a result in the row2 variable, then the vehicle and associated dates are taken.
						// --------------------------------------------------------------------------------------------------------
						if (row2 != NULL)
						{
							/* ----------------------------------------------- TEST ---------------------------------------------------------------------------
							// cout << vMake << " " << vModel << " " << this->reservationPickupDate << " " << this->reservationDropOff << endl << endl;
							-------------------------------------------------------------------------------------------------------------------------------- */

							cout << "\n\nSorry, but this vehicle is already reserved during these times. " << endl
								<< "\nTo choose another vehicle for you'll be redirected to the main menu. \n";
							
							/* ---------------- Note about do-while loop -------------------------
							* For some reason, the do-while loop wasn't utilizing the choice2 
							* variable to loop back around, so we're using return to get back to 
							* the main menu to find another vehicle. 
							* ----------------------------------------------
							* 
								cin >> choice2;
								cout << endl;
								cin.ignore();

								// exit; 
							-------------------------------------------------------------------- */
							return; 
						}
					}
				}
			}	
			// -------------------- Connection error handling -------------------------
			else
			{
			printf("\n\nMySQL Database Connection Unsuccessful.");
			exit(1);
			}

			// cout << "\n\n" << choice2 << endl;

		// }while(toupper(choice2) == 'y');
		
		// Set choice1 to n for no so that we can break the loop?


		cout << "\n\nTo keep the vehicle reservation please complete your transaction.  \n"
			<< "Would you like to complete your transaction or select another vehicle? \n "
			<< "Input the letter C to complete your transaction: ";
		
		cin.get(choice3);
		cin.ignore();
		cout << endl;
		

		while (toupper(choice3) == 'c');
		{
			cout << "\nYou've selected to complete transaction: \n";
			isTransactionComplete = completeTransaction(vMake, vModel); 

			if (isTransactionComplete == true)
			{
				if (conn10)
				{
					// --------------------------------- Q3 get plate number matching the user selected vehicle make and model ----------------------------------
					string get_query = "SELECT plateNumber FROM vehicles WHERE vehicles.vMake = '" + vMake + "' && vehicles.vModel = '" + vModel + "' ";

					const char* q6 = get_query.c_str();

					qState2 = mysql_query(conn10, q6);

					if (!qState2)
					{
						res2 = mysql_store_result(conn10);

						while (row2 = mysql_fetch_row(res2))
						{
							plateNum = row2[0];
						}
					}
					
					cout << " " << this->reservationPickupDate << endl
						<< " " << this->reservationDropOff << endl
						<< " " << this->reservationPickupTime << endl
						<< " " << this->reservationDropoffTime << endl
						<< " " << plateNum << endl
						<< " " << this->driversLicenseNumber << endl
						<< " " << this->emailAddress << endl << endl;
				
				// ----------------------------------------------------------------------------------------------------------------------------------
				// ------------------------ : Q4 vReservation table: --------------------
					string insert_query = "INSERT INTO vReservation VALUES( 0, '" + this->reservationPickupDate + "', '" + this->reservationDropOff + "', '" + this->reservationPickupTime + "' , '" + this->reservationDropoffTime + "'  )";

					const char* q7 = insert_query.c_str();

					qState2 = mysql_query(conn10, q7);
					// ------------------------ : Q5 madeFor table: --------------------
					string insert_query2 = "INSERT INTO madeFor VALUES( '"+ plateNum +"', last_insert_id(), '"+ vMake +"', '" + vModel + "','" + this->reservationPickupDate + "', '" + this->reservationDropOff + "', '" + this->reservationPickupTime + "', '" + this->reservationDropoffTime + "'  )";

					const char* q8 = insert_query2.c_str();

					qState2 = mysql_query(conn10, q8);
					// ------------------------ : Q6 wantToMake table: --------------------
					string insert_query3 = "INSERT INTO wantToMake VALUES(last_insert_id(), '"+ this->driversLicenseNumber +"','" + this->emailAddress + "', '" + this->reservationPickupDate + "', '" + this->reservationDropOff + "', '" + this->reservationPickupTime + "', '" + this->reservationDropoffTime + "'  )";

					const char* q9 = insert_query3.c_str();

					qState2 = mysql_query(conn10, q9);
				// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				
				}

				cout << "\n\nCongratulations, your reservation is set and transaction processed! \n"
					<< "Here are your reservation details: \n" << endl;

				string display_query = "SELECT * FROM wanttomake ORDER BY rID DESC LIMIT 1;";

				// ----------------------------------- TEST ---------------------------------
				// SELECT * FROM wanttomake WHERE rID =(SELECT last_insert_id());
				// OR
				// SELECT * FROM getLastRecord ORDER BY rID DESC LIMIT 1; <-- this works!
				// --------------------------------------------------------------------------

				const char* q11 = display_query.c_str();
				qState2 = mysql_query(conn10, q11);

				if (!qState2)
				{
					res2 = mysql_store_result(conn10);

					while (row2 = mysql_fetch_row(res2))
					{

						cout << "Reservation ID:" << row2[0] << endl
							<< " Driver's Lisence Number: " << row2[1] << endl
							<< " Email Address:" << row2[2] << endl
							<< " Pickup Date: " << row2[3] << endl
							<< " Dropoff Date: " << row2[4] << endl
							<< " Pick-up Time: " << row2[5] << endl
							<< " Dropoff Time: " << row2[6] << endl << endl;

					}
					// -----------------------------------------------------------------------------------------

				}
			}
			// -------------------- Connection error handling -------------------------
			else
			{
				printf("\n\nMySQL Database Connection Unsuccessful.");
				exit(1);
			}
		}
					
		
			// ------------------------------- Close MySQL Conn 8 -----------------------------------------
			mysql_close(conn10);
			if (conn10 == 0)
			{
				perror("\n\nSomething went wrong, MySQL connection did not closed. ");
				exit(1);
			}
			/* ------------------------- Explaination -----------------------------
			* mysql_close() deallocates the connection handler pointed to by mysql
			* if the handler was allocated automatically by mysql_init().
			-------------------------------------------------------------------- */
}
// ============================================================================================================================================
void Customer::deleteReservation()
{
	int rID = 0;
	stringstream ss;
	string rID1 = "";
	char choice = 'y';
	
	conn13 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn13 = mysql_real_connect(conn13, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------

	cout << "\nTo cancel a reservation we'll need your Reservation ID and Email Address. \n"
		<< "Please enter your Reservation ID: ";
	cin >> rID;
	cin.ignore();
	ss << rID;
	ss >> rID1;

	cout << "\nPlease enter your Email Address: ";
	getline(cin, this->emailAddress);

// ---------------------------------------------------------------------------
		// -> If the connection to our MySQL DB was successful, then ....
	if (conn13)
	{
		cout << "Connection 13 to the MySQL Database CRSS was Successful. \n" << endl;
		

			// ---------------------------- MySQL Query -----------------------------------------------
			string display_query = "SELECT * FROM wanttomake WHERE (rID = '" + rID1 + "' && EMAdd = '" + this->emailAddress + "')";

			const char* q4 = display_query.c_str();

			qState2 = mysql_query(conn13, q4);

			if (!qState2)
			{
				res2 = mysql_store_result(conn13);

				while (row2 = mysql_fetch_row(res2))
				{

					cout << "\nReservation ID: " << row2[0] << endl
						<< " Driver's Lisence Number: " << row2[1] << endl
						<< " Email Address: " << row2[2] << endl
						<< " Pickup Date: " << row2[3] << endl
						<< " Dropoff Date: " << row2[4] << endl
						<< " Pick-up Time: " << row2[5] << endl
						<< " Dropoff Time: " << row2[6] << endl << endl;

				}
				// -----------------------------------------------------------------------------------------

			}

			cout << "Would you like to cancel your reservation? (Y or N): ";
			cin.get(choice);
			cin.ignore();
			cout << endl << endl << rID1;
			
			while (toupper(choice) == 'y');
			{
			// ------------------------------- Cancel Reservation Query ------------------------------
				string delete_query = "DELETE FROM vReservation WHERE reservationID = '" + rID1 + "' ";

				const char* q2 = delete_query.c_str();

				qState2 = mysql_query(conn13, q2);
			// ---------------------------------------------------------------------------------------

				string display_query2 = "SELECT * FROM wanttomake";

				const char* q3 = display_query2.c_str();
				qState2 = mysql_query(conn13, q3);

				if (!qState2)
				{
					res2 = mysql_store_result(conn13);

					while (row2 = mysql_fetch_row(res2))
					{

						cout << "\nReservation ID: " << row2[0] << endl
							<< " Driver's Lisence Number: " << row2[1] << endl
							<< " Email Address: " << row2[2] << endl
							<< " Pickup Date: " << row2[3] << endl
							<< " Dropoff Date: " << row2[4] << endl
							<< " Pick-up Time: " << row2[5] << endl
							<< " Dropoff Time: " << row2[6] << endl << endl;

					}
					// -----------------------------------------------------------------------------------------

				}
				choice = 'n';
			}
			cout << "\nYour reservation has been canceled. \n";
			// -----------------------------------------------------------------------------------------
	}
	// -------- Throw error w/ message if connection is unsuccessful ----------
	else
	{
		printf("MySQL Database Connection Unsuccessful.");
		exit(1);
	}
	// ------------------------------------------------------------------------

	mysql_close(conn13);
	if (conn13 == 0)
	{
		perror("Something went wrong, MySQL connection did not closed. ");
		exit(1);
	}
	/* ------------------------- Explaination -----------------------------
	* mysql_close() deallocates the connection handler pointed to by mysql
	* if the handler was allocated automatically by mysql_init().
	-------------------------------------------------------------------- */
}
// ============================================================================================================================================
bool Customer::completeTransaction(string vMake, string vModel)
{
	char choice = 'y';
	int numDays = 0;
	string plateNum = "";
	string vVIN = "";


	conn11 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn11 = mysql_real_connect(conn11, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------
		// -> If the connection to our MySQL DB was successful, then ....
	if (conn11)
	{
		
		cout << "Connection 11 to the MySQL Database CRSS was Successful. \n" << endl;

		// ------------ Directly into mySQL --------------- --> works
		// SELECT vSize FROM vehicles Where vehicles.vMake = 'toyota' && vehicles.vModel = 'rav4';
		 
		// ---------------------------- MySQL Query -----------------------------------------------
		string vSize_query = "SELECT vSize FROM vehicles Where vehicles.vMake = '"+ vMake +"' && vehicles.vModel = '"+ vModel +"' ";

		const char* q1 = vSize_query.c_str();
		qState2 = mysql_query(conn11, q1);

		if (!qState2)
		{
			res2 = mysql_store_result(conn11);

			while (row2 = mysql_fetch_row(res2))
			{

				// cout << " vMake is " << row2[0] << endl;

				// set vehicle size based on vehicle make and model choices obtained in previous function:

				this->vSize = row2[0];

				// ------------- test output ------------
				// cout << endl << row2[0];
				// --------------------------------------
			}	
			// -----------------------------------------------------------------------------------------
		}

		cout << "\nPlease enter your user information for validation. "
			<< "\nCase matters, so don't add any unnecessary capital letters."
			<< "\nNow enter your Email Address: ";

		getline(cin, this->emailAddress);
		cout << endl;

		cout << "Now enter your Driver's Lisence Number: ";
		getline(cin, this->driversLicenseNumber);
		cout << endl;

		string userInfo_query1 = "SELECT emailAddress, driversLicenseNumber FROM customers Where customers.emailAddress = '" + this->emailAddress + "' && customers.driversLicenseNumber = '" + this->driversLicenseNumber + "' ";

		// ------------------------------------------- mySQL query ----------------------------
		// SELECT emailAddress, driversLicenseNumber FROM customers Where customers.emailAddress = 'kanwaljeetahluwalia@gmail.com' && customers.driversLicenseNumber = 'FDB734Y';
		
		const char* q2 = userInfo_query1.c_str();
		qState2 = mysql_query(conn11, q2);

		if (!qState2)
		{
			res2 = mysql_store_result(conn11);

			while (row2 = mysql_fetch_row(res2))
			{

				cout << " \nEmail Address: " << row2[0] <<  endl << endl
					<< "\n DLN: " << row2[1] << endl;

				// set customer emailAddress and driversLNum based on database validation:
				if (( this->emailAddress == row2[0] ) && ( this->driversLicenseNumber == row2[1] ))
				{
					cout << "\nValidated. \n";
					exit;
				}

				// ------------- test output ------------
				// cout << endl << row2[0] << endl << endl << row2[1];
				// --------------------------------------

			}
			// -----------------------------------------------------------------------------------------
		}
	

	cout << "\nWould you like to complete your transaction? (Y or N) ";
	cin.get(choice);
	cin.ignore();

	cout << "\nHow many days is the reservation? ";
	cin >> numDays;
	cin.ignore();
	cout << endl;

			if (toupper(choice == 'y'))
			{
				// -----------------------------------------------------------------------------------------
				// Q1 for transactions table:
				string insert_query = "INSERT INTO transactions VALUES()";

				const char* q7 = insert_query.c_str();

				qState2 = mysql_query(conn11, q7);
				// ---------------------------------------------- Q2 for isMakingTransaction -------------------------------------
				string insert_query2 = "INSERT INTO isMakingTransaction VALUES( '" + this->driversLicenseNumber + "', last_insert_id(), '" + this->emailAddress + "' )";

				const char* q8 = insert_query2.c_str();

				qState2 = mysql_query(conn11, q8);
			// ------------------------------------------- Q3 to obtain the plate number and VIN based on the user's input -----------------------------------------------------------------------
				string select_query2 = "SELECT plateNumber, vVin FROM vehicles WHERE vehicles.vMake = '" + vMake + "' && vehicles.vModel = '" + vModel + "' ";

				// SELECT plateNumber, vVin FROM vehicles WHERE vehicles.vMake = vMake  && vehicles.vModel = rav4;

				const char* q9 = select_query2.c_str();

				qState2 = mysql_query(conn11, q9);

				if (!qState2)
				{
					res2 = mysql_store_result(conn11);

					while (row2 = mysql_fetch_row(res2))
					{

						cout << " plate Num: " << row2[0] << endl
							<< "VIN: " << row2[1] << endl;

						// set customer emailAddress and driversLNum based on database validation:
						plateNum = row2[0];
						vVIN = row2[1];


						// ------------- test output ------------
						// cout << endl << row2[0] << endl << endl << row2[1];
						// --------------------------------------

					}
					// -----------------------------------------------------------------------------------------
				}
				// cout << plateNum << "         " << vVIN;
				// 
				// --------------------------------------------------------------------------------------------------------------------
				string insert_query9 = "INSERT INTO beingrented VALUES( last_insert_id(), '" + plateNum + "' , '" + vVIN + "', 1) ";

				// INSERT INTO beingrented VALUES( last_insert_id(), "ZGSPS20" , "LYG739IK131528KP2" ,1 );

				const char* q11 = insert_query9.c_str();

				qState2 = mysql_query(conn11, q11); 
				// ---------------------------------------------------------------------------------------------------------------------



				if (this->vSize == "small")
				{
			
					cout << "The total is: $" << ((20.00 * numDays) + ((20.00 * numDays) * .08));
					return true;
				}
				else if (this->vSize == "medium")
				{
					cout << "The total is: $" << ((30.00 * numDays) + ((30.00 * numDays) * .08));
					return true;
				}
				else if (this->vSize == "large")
				{
					cout << "The total is: $" << ((40.00 * numDays) + ((40.00 * numDays) * .08));
					return true;
				}
			}
			else
			{
				cout << "Transaction refused. ";
				return false;
			}
	
	}
	// -------- Throw error w/ message if connection is unsuccessful ----------
	else
	{
	printf("MySQL Database Connection Unsuccessful.");
	exit(1);
	}
	// ------------------------------------------------------------------------

	mysql_close(conn11);
	if (conn11 == 0)
	{
		perror("Something went wrong, MySQL connection did not closed. ");
		exit(1);
	}
	/* ------------------------- Explaination -----------------------------
	* mysql_close() deallocates the connection handler pointed to by mysql
	* if the handler was allocated automatically by mysql_init().
	-------------------------------------------------------------------- */

	return false;
}
// ============================================================================================================================================
void Customer::displayPickupDropoffInfo()
{
	int rID = 0;
	stringstream ss;
	conn12 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

	// ------------------------------ Connecting to MySQL --------------------------------------
	conn12 = mysql_real_connect(conn12, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
	// -----------------------------------------------------------------------------------------

	cout << "\n\nPlease enter your reservation ID number: ";
	cin >> rID;
	cin.ignore();
	ss << rID;
	string rID1;
	ss >> rID1;

	/* ----------------Test--------------
	cout << rID << endl << endl 
		<< rID1 << endl;
	----------------------------------- */

	cout << "\nPlease enter your email address : ";
	getline(cin, this->emailAddress);
	cout << endl;

// ---------------------------------------------------------------------------
		// -> If the connection to our MySQL DB was successful, then ....
	if (conn12)
	{
		cout << "\n\nConnection 12 to the MySQL Database CRSS was Successful. \n" << endl;

		// ---------------------------- MySQL Query -----------------------------------------------
		string display_query = "SELECT * FROM wanttomake WHERE (rID = '"+ rID1 +"' && EMAdd = '"+ this->emailAddress +"')";
		
		const char* q1 = display_query.c_str();
		qState2 = mysql_query(conn12, q1);

		if (!qState2)
		{
			res2 = mysql_store_result(conn12);

			while (row2 = mysql_fetch_row(res2))
			{

				cout << "\nReservation ID: " << row2[0] << endl
					<< " Driver's Lisence Number: " << row2[1] << endl
					<< " Email Address: " << row2[2] << endl
					<< " Pickup Date: " << row2[3] << endl
					<< " Dropoff Date: " << row2[4] << endl
					<< " Pick-up Time: " << row2[5] << endl
					<< " Dropoff Time: " << row2[6] << endl << endl;

			}
			// -----------------------------------------------------------------------------------------

		}
	}
	// -------- Throw error w/ message if connection is unsuccessful ----------
	else
	{
		printf("MySQL Database Connection Unsuccessful.");
		exit(1);
	}
	// ------------------------------------------------------------------------

	mysql_close(conn12);
	if (conn12 == 0)
	{
		perror("Something went wrong, MySQL connection did not closed. ");
		exit(1);
	}
	/* ------------------------- Explaination -----------------------------
	* mysql_close() deallocates the connection handler pointed to by mysql
	* if the handler was allocated automatically by mysql_init().
	-------------------------------------------------------------------- */
	
}
void Customer::custAccessC(Customer c)
{
	char choice1 = 'd';
	char choice2 = 'y';

	// try using a clock to delay login attempts..

	do {

		cout << "\nTo Delete Customer Account Information (select [D]) \n"
			<< "To Make a Reservation (select [M]) \n"
			<< "To Delete a Reservation (select [R]) \n"
			<< "To Display Pickup/Dropoff Information (select [P]):: ";

		cin.get(choice1);
		cin.ignore();
		cout << endl;

		switch (toupper(choice1))
		{
			// ---------------------- choice1 = A -------------------------
		case 'D':
			cout << "\nYou've selected to Delete Customer Account Information: ";
			c.deleteCustomerInfo();
			break;
		case 'M':
			cout << "\nYou've selected to Make a Reservation: ";
			c.makeReservation();
			break;
		case 'R':
			cout << "\nYou've selected to Delete a Reservation: ";
			c.deleteReservation();
			break;
		case 'P':
			cout << "\nYou've selected to Display Pickup/Dropoff Information: ";
			c.displayPickupDropoffInfo();
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
}
void Customer::adminAccessC(Customer c)
{
	char choice1 = 'd';
	char choice2 = 'y';
	/* ========================================= Calling Customer Class Functions ==================================================================
	* -> Each instance of the Customer class and its functions will prompt the user to add the required information and return them to main where
	* each value is stored into variable and inserted into the MySQL DB.
	*
	* -> Variables: driversLicenseNumber, customerFName, customerLName, customerAge, cityOfResidence; apartmentNumber,
	*  streetAddress, stateOfResidence, & zipCode.
	* ----------------------------------------------------------------------------------------------------------------------------------------- */
	do {

		cout << "\nFor Display Customer Information (select [D]) \n"
			<< "For Customer Count (select [C]) \n"
			<< "To Insert New Customer Information (select [I]) \n"
			<< "To Delete Customer Information (select [B]) \n"
			<< "To Make Reservation (select [M]) \n"
			<< "To Delete Reservation (select [R]) \n"
			<< "To Display Pickup/Dropoff Information (select[P]):: ";

		cin.get(choice1);
		cin.ignore();
		cout << endl;

		switch (toupper(choice1))
		{
			// ---------------------- choice1 = A -------------------------
		case 'D':
			cout << "\nYou've selected to Display Customer Information: ";
			c.displayCustomerInfo();
			break;
		case 'C':
			cout << "\nYou've selected to Display Customer Count: ";
			c.customerCount();
			break;
		case 'I':
			cout << "\nYou've selected to Insert New Customer Information: ";
			c.insertCustomerInfo();
			break;
		case 'B':
			cout << "\nYou've selected to Delete Customer Information: ";
			c.deleteCustomerInfo();
			break;
		case 'M':
			cout << "\nYou've selected to Make a Reservation: ";
			c.makeReservation();
			break;
		case 'R':
			cout << "\nYou've selected to Cancel Reservation: ";
			c.deleteReservation();
			break;
		case 'P':
			cout << "\nYou've selected to Display Pickup/Dropoff Information: ";
			displayPickupDropoffInfo();
			break;
		}

		cout << "\nWould you like to return to the Customer Data menu? "
			<< "( Y or N ) ";
		cin.get(choice2);
		cin.ignore();
		cout << endl;
		system("cls");

	} while (toupper(choice2 == 'y'));

	return;
}
//============================================================================== END  CustomerInfo.cpp ======================================================================================
/* ------------------------------------------------------------------ OUTPUT addCustomer  --------------------------------------------------------------------
Welcome to the Car Rental Service Software, CRSS:

Are your an Administrator, an existing customer or a new customer?
Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: a

Hello, would you like to Access Customer or Vehicle data (C or V): c

You've selected Access to Customer Data:

Would you like to make a reservation? (Y/N): y



Connection 10 to the MySQL Database CRSS was Successful.

What date would you like to being your reservation on?
Default date format is YYYY-MM-DD: 2023-01-10

How many days will you be reserving the vehicle for?
Default date format is YYYY-MM-DD: 2023-01-25

What time will you be picking up the vehicle?
Default date format is HH:MM:SS: 5:00

What time will you be dropping off the vehicle?
Default date format is HH:MM:SS: 4:00

reservationPickupDate: 2023-01-10
eservationDuration: 2023-01-25
eservationPickupTime: 5:00
eservationDropoffTime: 4:00

 plateNumber: SWS5840 vType: coupe vSize: Small vMake: Chevrolet vModel: Camaro color: Black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: Manual

 plateNumber: LPSPLP1 vType: Sedan vSize: Small vMake: KIA vModel: RIO color: Pink vMPG: 29 vNav: yes seatingCapacity: 4 engineCylinders: 4 transmissionType: Automatic

 plateNumber: HWS584I vType: SUV vSize: Medium vMake: Honda vModel: CRV color: Blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: Automatic

 plateNumber: HWS579T vType: Sedan vSize: Large vMake: Mercedes vModel: e550 color: Black vMPG: 30 vNav: yes seatingCapacity: 6 engineCylinders: 8 transmissionType: Automatic

 plateNumber: HWS794I vType: SUV vSize: Medium vMake: Toyota vModel: Highlander color: White vMPG: 24 vNav: yes seatingCapacity: 5 engineCylinders: 6 transmissionType: Automatic

 plateNumber: NPSMAZS vType: MINIVAN vSize: Large vMake: CRYSLER vModel: PACIFICA color: Blue vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: Automatic

 plateNumber: OGS584P vType: coupe vSize: Small vMake: Nissan vModel: 370z color: White vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: Manual

 plateNumber: OGSYT5P vType: coupe vSize: Small vMake: Ford vModel: Mustang color: Red vMPG: 16 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: Manual

 plateNumber: LP245P1 vType: MINIVAN vSize: Large vMake: HONDA vModel: ODYSSEY color: Black vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: Automatic

 plateNumber: ZGSPS20 vType: SUV vSize: Medium vMake: Toyota vModel: RAV4 color: White vMPG: 28 vNav: yes seatingCapacity: 7 engineCylinders: 6 transmissionType: Automatic

Please enter the vehicle make you would like to rent? Mercedes

Please enter the vehicle model you would like to rent? e550

 Lisence Plate Number: HWS584I Reservation ID: 2 Vehicle Make: Honda Vehicle Model: CRV Reservation Pickup Date: 2022-01-15 Reservation Dropoff Date: 2022-01-28 Reservation Pickup Time: 06:40:15 Reservation Dropoff Time: 04:15:45

Congratulation, your vehicle is reserved.
 Lisence Plate Number: SWS5840 Reservation ID: 3 Vehicle Make: Chevrolet Vehicle Model: Camaro Reservation Pickup Date: 2023-02-05 Reservation Dropoff Date: 2023-02-15 Reservation Pickup Time: 02:30:15 Reservation Dropoff Time: 08:15:45

Congratulation, your vehicle is reserved.
 Lisence Plate Number: OGS584P Reservation ID: 4 Vehicle Make: Nissan Vehicle Model: 370z Reservation Pickup Date: 2023-02-08 Reservation Dropoff Date: 2023-02-27 Reservation Pickup Time: 01:30:15 Reservation Dropoff Time: 09:15:45

Congratulation, your vehicle is reserved.
 Lisence Plate Number: HWS579T Reservation ID: 1 Vehicle Make: Mercedes Vehicle Model: e550 Reservation Pickup Date: 2023-01-10 Reservation Dropoff Date: 2023-01-25 Reservation Pickup Time: 06:30:15 Reservation Dropoff Time: 02:15:45

Sorry, but this vehicle is already reserved during these times.
To keep the vehicle reservation please complete your transaction.
Would you like to complete your transaction or select another vehicle?
 Select C to complete your transaction or A to select another vehicle:

 ------------------------------------------------------------ :TEST: -----------------------------------------------------------------------------

 Welcome to the Car Rental Service Software, CRSS:

Are your an Administrator, an existing customer or a new customer?
Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: a

Hello, would you like to Access Customer or Vehicle data (C or V): c

You've selected Access to Customer Data:

Let's make a reservation!

Connection 10 to the MySQL Database CRSS was Successful.

What date would you like to being your reservation on?
Default date format is YYYY-MM-DD: 2023-04-10

How many days will you be reserving the vehicle for?
Default date format is YYYY-MM-DD: 2023-04-25

What time will you be picking up the vehicle?
Default date format is HH:MM:SS: 1:00

What time will you be dropping off the vehicle?
Default date format is HH:MM:SS: 6:00
 plateNumber: SWS5840 vType: coupe vSize: small vMake: chevrolet vModel: camaro color: black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LPSPLP1 vType: sedan vSize: small vMake: kia vModel: rio color: pink vMPG: 29 vNav: yes seatingCapacity: 4 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS584I vType: suv vSize: medium vMake: honda vModel: crv color: blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS579T vType: sedan vSize: large vMake: mercedes vModel: e550 color: black vMPG: 30 vNav: yes seatingCapacity: 6 engineCylinders: 8 transmissionType: automatic

 plateNumber: HWS794I vType: suv vSize: medium vMake: toyota vModel: highlander color: white vMPG: 24 vNav: yes seatingCapacity: 5 engineCylinders: 6 transmissionType: automatic

 plateNumber: NPSMAZS vType: minivan vSize: large vMake: chrysler vModel: pacifica color: blue vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: OGS584P vType: coupe vSize: small vMake: nissan vModel: 370z color: white vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: manual

 plateNumber: OGSYT5P vType: coupe vSize: small vMake: ford vModel: mustang color: red vMPG: 16 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LP245P1 vType: minivan vSize: large vMake: honda vModel: odessey color: black vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: ZGSPS20 vType: suv vSize: medium vMake: toyota vModel: rav4 color: white vMPG: 28 vNav: yes seatingCapacity: 7 engineCylinders: 6 transmissionType: Automatic

Please enter the vehicle make you would like to rent? toyota

Please enter the vehicle model you would like to rent? rav4

 Lisence Plate Number: HWS579T Reservation ID: 1 Vehicle Make: mercedes Vehicle Model: e550 Reservation Pickup Date: 2023-01-10 Reservation Dropoff Date: 2023-01-25 Reservation Pickup Time: 06:30:15 Reservation Dropoff Time: 02:15:45

 Lisence Plate Number: HWS584I Reservation ID: 2 Vehicle Make: honda Vehicle Model: crv Reservation Pickup Date: 2022-01-15 Reservation Dropoff Date: 2022-01-28 Reservation Pickup Time: 06:40:15 Reservation Dropoff Time: 04:15:45

 Lisence Plate Number: SWS5840 Reservation ID: 3 Vehicle Make: chevrolet Vehicle Model: camaro Reservation Pickup Date: 2023-02-05 Reservation Dropoff Date: 2023-02-15 Reservation Pickup Time: 02:30:15 Reservation Dropoff Time: 08:15:45

 Lisence Plate Number: OGS584P Reservation ID: 4 Vehicle Make: nissan Vehicle Model: 370z Reservation Pickup Date: 2023-02-08 Reservation Dropoff Date: 2023-02-27 Reservation Pickup Time: 01:30:15 Reservation Dropoff Time: 09:15:45



To keep the vehicle reservation please complete your transaction.
Would you like to complete your transaction or select another vehicle?
 Input the letter C to complete your transaction: c


You've selected to complete transaction:
Connection 11 to the MySQL Database CRSS was Successful.

 vMake is medium

Would you like to complete your transaction? (Y or N) y

 How many days is the reservation? 15

The total is: $486Congratulations, your reservation is set and transaction processed.

Hi.
Would you like to return to the main CRSS menu? ( Y or N )

-------------------------------------------------------------- TEST -------------------------------------------------------------------------------
Welcome to the Car Rental Service Software, CRSS:

Are your an Administrator, an existing customer or a new customer?
Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: a

Hello, would you like to Access Customer or Vehicle data (C or V): c

You've selected Access to Customer Data:

Let's make a reservation!

Connection 10 to the MySQL Database CRSS was Successful.

What date would you like to being your reservation on?
Default date format is YYYY-MM-DD: 2023-04-10

How many days will you be reserving the vehicle for?
Default date format is YYYY-MM-DD: 2023-04-25

What time will you be picking up the vehicle?
Default date format is HH:MM:SS: 1:00

What time will you be dropping off the vehicle?
Default date format is HH:MM:SS: 6:00
 plateNumber: SWS5840 vType: coupe vSize: small vMake: chevrolet vModel: camaro color: black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LPSPLP1 vType: sedan vSize: small vMake: kia vModel: rio color: pink vMPG: 29 vNav: yes seatingCapacity: 4 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS584I vType: suv vSize: medium vMake: honda vModel: crv color: blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS579T vType: sedan vSize: large vMake: mercedes vModel: e550 color: black vMPG: 30 vNav: yes seatingCapacity: 6 engineCylinders: 8 transmissionType: automatic

 plateNumber: HWS794I vType: suv vSize: medium vMake: toyota vModel: highlander color: white vMPG: 24 vNav: yes seatingCapacity: 5 engineCylinders: 6 transmissionType: automatic

 plateNumber: NPSMAZS vType: minivan vSize: large vMake: chrysler vModel: pacifica color: blue vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: OGS584P vType: coupe vSize: small vMake: nissan vModel: 370z color: white vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: manual

 plateNumber: OGSYT5P vType: coupe vSize: small vMake: ford vModel: mustang color: red vMPG: 16 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LP245P1 vType: minivan vSize: large vMake: honda vModel: odessey color: black vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: ZGSPS20 vType: suv vSize: medium vMake: toyota vModel: rav4 color: white vMPG: 28 vNav: yes seatingCapacity: 7 engineCylinders: 6 transmissionType: Automatic

Please enter the vehicle make you would like to rent? toyota

Please enter the vehicle model you would like to rent? rav4

 Lisence Plate Number: HWS579T Reservation ID: 1 Vehicle Make: mercedes Vehicle Model: e550 Reservation Pickup Date: 2023-01-10 Reservation Dropoff Date: 2023-01-25 Reservation Pickup Time: 06:30:15 Reservation Dropoff Time: 02:15:45

 Lisence Plate Number: HWS584I Reservation ID: 2 Vehicle Make: honda Vehicle Model: crv Reservation Pickup Date: 2022-01-15 Reservation Dropoff Date: 2022-01-28 Reservation Pickup Time: 06:40:15 Reservation Dropoff Time: 04:15:45

 Lisence Plate Number: SWS5840 Reservation ID: 3 Vehicle Make: chevrolet Vehicle Model: camaro Reservation Pickup Date: 2023-02-05 Reservation Dropoff Date: 2023-02-15 Reservation Pickup Time: 02:30:15 Reservation Dropoff Time: 08:15:45

 Lisence Plate Number: OGS584P Reservation ID: 4 Vehicle Make: nissan Vehicle Model: 370z Reservation Pickup Date: 2023-02-08 Reservation Dropoff Date: 2023-02-27 Reservation Pickup Time: 01:30:15 Reservation Dropoff Time: 09:15:45



To keep the vehicle reservation please complete your transaction.
Would you like to complete your transaction or select another vehicle?
 Input the letter C to complete your transaction: c


You've selected to complete transaction:
Connection 11 to the MySQL Database CRSS was Successful.

Please enter your user information for validation. Case matters, so don't add any unnecessary capital letters.Now enter your Email Address: kanwaljeetahluwalia@gmail.com

Now enter your Driver's Lisence Number: FDB734Y

 Email Address: kanwaljeetahluwalia@gmail.com 
 DLN: FDB734Y

kanwaljeetahluwalia@gmail.com
FDB734Y
Would you like to complete your transaction? (Y or N) y

 How many days is the reservation? 15

The total is: $486

Congratulations, your reservation is set and transaction processed.
Would you like to return to the main CRSS menu? ( Y or N )

-------------------------------------------------------------------------------------------- :TEST: ----------------------------------------------------------------------------------------------------
Welcome to the Car Rental Service Software, CRSS:

Are your an Administrator, an existing customer or a new customer?
Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: a

Hello, would you like to Access Customer or Vehicle data (C or V): c

You've selected Access to Customer Data:

Let's make a reservation!

Connection 10 to the MySQL Database CRSS was Successful.

What date would you like to being your reservation on?
Default date format is YYYY-MM-DD: 2023-04-10

How many days will you be reserving the vehicle for?
Default date format is YYYY-MM-DD: 2023-04-25

What time will you be picking up the vehicle?
Default date format is HH:MM:SS: 1:00

What time will you be dropping off the vehicle?
Default date format is HH:MM:SS: 8:00
 plateNumber: SWS5840 vType: coupe vSize: small vMake: chevrolet vModel: camaro color: black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LPSPLP1 vType: sedan vSize: small vMake: kia vModel: rio color: pink vMPG: 29 vNav: yes seatingCapacity: 4 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS584I vType: suv vSize: medium vMake: honda vModel: crv color: blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS579T vType: sedan vSize: large vMake: mercedes vModel: e550 color: black vMPG: 30 vNav: yes seatingCapacity: 6 engineCylinders: 8 transmissionType: automatic

 plateNumber: HWS794I vType: suv vSize: medium vMake: toyota vModel: highlander color: white vMPG: 24 vNav: yes seatingCapacity: 5 engineCylinders: 6 transmissionType: automatic

 plateNumber: NPSMAZS vType: minivan vSize: large vMake: chrysler vModel: pacifica color: blue vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: OGS584P vType: coupe vSize: small vMake: nissan vModel: 370z color: white vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: manual

 plateNumber: OGSYT5P vType: coupe vSize: small vMake: ford vModel: mustang color: red vMPG: 16 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LP245P1 vType: minivan vSize: large vMake: honda vModel: odessey color: black vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: ZGSPS20 vType: suv vSize: medium vMake: toyota vModel: rav4 color: white vMPG: 28 vNav: yes seatingCapacity: 7 engineCylinders: 6 transmissionType: Automatic

Please enter the vehicle make you would like to rent? toyota

Please enter the vehicle model you would like to rent? rav4

 Lisence Plate Number: HWS579T Reservation ID: 1 Vehicle Make: mercedes Vehicle Model: e550 Reservation Pickup Date: 2023-01-10 Reservation Dropoff Date: 2023-01-25 Reservation Pickup Time: 06:30:15 Reservation Dropoff Time: 02:15:45

 Lisence Plate Number: HWS584I Reservation ID: 2 Vehicle Make: honda Vehicle Model: crv Reservation Pickup Date: 2022-01-15 Reservation Dropoff Date: 2022-01-28 Reservation Pickup Time: 06:40:15 Reservation Dropoff Time: 04:15:45

 Lisence Plate Number: SWS5840 Reservation ID: 3 Vehicle Make: chevrolet Vehicle Model: camaro Reservation Pickup Date: 2023-02-05 Reservation Dropoff Date: 2023-02-15 Reservation Pickup Time: 02:30:15 Reservation Dropoff Time: 08:15:45

 Lisence Plate Number: OGS584P Reservation ID: 4 Vehicle Make: nissan Vehicle Model: 370z Reservation Pickup Date: 2023-02-08 Reservation Dropoff Date: 2023-02-27 Reservation Pickup Time: 01:30:15 Reservation Dropoff Time: 09:15:45



To keep the vehicle reservation please complete your transaction.
Would you like to complete your transaction or select another vehicle?
 Input the letter C to complete your transaction: c


You've selected to complete transaction:
Connection 11 to the MySQL Database CRSS was Successful.


Please enter your user information for validation.
Case matters, so don't add any unnecessary capital letters.
Now enter your Email Address: kanwaljeetahluwalia@gmail.com

Now enter your Driver's Lisence Number: FDB734Y

 Email Address: kanwaljeetahluwalia@gmail.com

 DLN: FDB734Y

Validated.

Would you like to complete your transaction? (Y or N) y

 How many days is the reservation? 15

The total is: $486

Congratulations, your reservation is set and transaction processed.
Would you like to return to the main CRSS menu? ( Y or N )
--------------------------------------------------------------------- :TEST: -----------------------------------------------------------------------------
Welcome to the Car Rental Service Software, CRSS:

Are your an Administrator, an existing customer or a new customer?
Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: a

Hello, would you like to Access Customer or Vehicle data (C or V): c

You've selected Access to Customer Data:

Let's make a reservation!

Connection 10 to the MySQL Database CRSS was Successful.

What date would you like to being your reservation on?
Default date format is YYYY-MM-DD: 2023-04-10

How many days will you be reserving the vehicle for?
Default date format is YYYY-MM-DD: 2023-04-25

What time will you be picking up the vehicle?
Default date format is HH:MM:SS: 1:00

What time will you be dropping off the vehicle?
Default date format is HH:MM:SS: 8:00
 plateNumber: SWS5840 vType: coupe vSize: small vMake: chevrolet vModel: camaro color: black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LPSPLP1 vType: sedan vSize: small vMake: kia vModel: rio color: pink vMPG: 29 vNav: yes seatingCapacity: 4 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS584I vType: suv vSize: medium vMake: honda vModel: crv color: blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS579T vType: sedan vSize: large vMake: mercedes vModel: e550 color: black vMPG: 30 vNav: yes seatingCapacity: 6 engineCylinders: 8 transmissionType: automatic

 plateNumber: HWS794I vType: suv vSize: medium vMake: toyota vModel: highlander color: white vMPG: 24 vNav: yes seatingCapacity: 5 engineCylinders: 6 transmissionType: automatic

 plateNumber: NPSMAZS vType: minivan vSize: large vMake: chrysler vModel: pacifica color: blue vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: OGS584P vType: coupe vSize: small vMake: nissan vModel: 370z color: white vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: manual

 plateNumber: OGSYT5P vType: coupe vSize: small vMake: ford vModel: mustang color: red vMPG: 16 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LP245P1 vType: minivan vSize: large vMake: honda vModel: odessey color: black vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: ZGSPS20 vType: suv vSize: medium vMake: toyota vModel: rav4 color: white vMPG: 28 vNav: yes seatingCapacity: 7 engineCylinders: 6 transmissionType: Automatic

Please enter the vehicle make you would like to rent? toyota

Please enter the vehicle model you would like to rent? rav4

 Lisence Plate Number: HWS579T Reservation ID: 1 Vehicle Make: mercedes Vehicle Model: e550 Reservation Pickup Date: 2023-01-10 Reservation Dropoff Date: 2023-01-25 Reservation Pickup Time: 06:30:15 Reservation Dropoff Time: 02:15:45

 Lisence Plate Number: HWS584I Reservation ID: 2 Vehicle Make: honda Vehicle Model: crv Reservation Pickup Date: 2022-01-15 Reservation Dropoff Date: 2022-01-28 Reservation Pickup Time: 06:40:15 Reservation Dropoff Time: 04:15:45

 Lisence Plate Number: SWS5840 Reservation ID: 3 Vehicle Make: chevrolet Vehicle Model: camaro Reservation Pickup Date: 2023-02-05 Reservation Dropoff Date: 2023-02-15 Reservation Pickup Time: 02:30:15 Reservation Dropoff Time: 08:15:45

 Lisence Plate Number: OGS584P Reservation ID: 4 Vehicle Make: nissan Vehicle Model: 370z Reservation Pickup Date: 2023-02-08 Reservation Dropoff Date: 2023-02-27 Reservation Pickup Time: 01:30:15 Reservation Dropoff Time: 09:15:45



To keep the vehicle reservation please complete your transaction.
Would you like to complete your transaction or select another vehicle?
 Input the letter C to complete your transaction: c


You've selected to complete transaction:
Connection 11 to the MySQL Database CRSS was Successful.


Please enter your user information for validation.
Case matters, so don't add any unnecessary capital letters.
Now enter your Email Address: kanwaljeetahluwalia@gmail.com

Now enter your Driver's Lisence Number: FDB734Y


Email Address: kanwaljeetahluwalia@gmail.com


 DLN: FDB734Y

Validated.

Would you like to complete your transaction? (Y or N) y

 How many days is the reservation? 15

 plate Num: ZGSPS20
VIN: LYG739IK131528KP2
The total is: $486

Congratulations, your reservation is set and transaction processed.
Would you like to return to the main CRSS menu? ( Y or N )
------------------------------------------------------------------- in MySQL -----------------------------------------
mysql> select * from transactions;
+---------------+----------------------+
| transactionID | transactionTimeStamp |
+---------------+----------------------+
|             1 | 2022-11-24 20:34:14  |
|             2 | 2022-11-24 20:34:14  |
|             3 | 2022-11-24 20:34:14  |
|             4 | 2022-11-24 20:34:16  |
|             8 | 2022-12-04 20:32:58  |
+---------------+----------------------+
5 rows in set (0.00 sec)

mysql> select * from ismakingtransaction;
+---------+-----+-------------------------------+
| DLNumT  | tID | eMailAdd                      |
+---------+-----+-------------------------------+
| FDB734Y |   8 | kanwaljeetahluwalia@gmail.com |
+---------+-----+-------------------------------+
1 row in set (0.00 sec)

mysql> select * from  beingrented;
+---------+-----------+-------------------+------------+
| transID | plateNumb | vVIN              | vRentCount |
+---------+-----------+-------------------+------------+
|       8 | ZGSPS20   | LYG739IK131528KP2 |          1 |
+---------+-----------+-------------------+------------+
1 row in set (0.00 sec)
-------------------------------------------------------------------------------------------- :TEST: ----------------------------------------------------------------------------------------------------
Welcome to the Car Rental Service Software, CRSS:

Are your an Administrator, an existing customer or a new customer?
Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: a

Hello, would you like to Access Customer or Vehicle data (C or V): c

You've selected Access to Customer Data:

Let's make a reservation!

Connection 10 to the MySQL Database CRSS was Successful.

What date would you like to being your reservation on?
Default date format is YYYY-MM-DD: 2023-04-10

How many days will you be reserving the vehicle for?
Default date format is YYYY-MM-DD: 2023-04-25

What time will you be picking up the vehicle?
Default date format is HH:MM:SS: 1:00

What time will you be dropping off the vehicle?
Default date format is HH:MM:SS: 6:00
 plateNumber: SWS5840 vType: coupe vSize: small vMake: chevrolet vModel: camaro color: black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LPSPLP1 vType: sedan vSize: small vMake: kia vModel: rio color: pink vMPG: 29 vNav: yes seatingCapacity: 4 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS584I vType: suv vSize: medium vMake: honda vModel: crv color: blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS579T vType: sedan vSize: large vMake: mercedes vModel: e550 color: black vMPG: 30 vNav: yes seatingCapacity: 6 engineCylinders: 8 transmissionType: automatic

 plateNumber: HWS794I vType: suv vSize: medium vMake: toyota vModel: highlander color: white vMPG: 24 vNav: yes seatingCapacity: 5 engineCylinders: 6 transmissionType: automatic

 plateNumber: NPSMAZS vType: minivan vSize: large vMake: chrysler vModel: pacifica color: blue vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: OGS584P vType: coupe vSize: small vMake: nissan vModel: 370z color: white vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: manual

 plateNumber: OGSYT5P vType: coupe vSize: small vMake: ford vModel: mustang color: red vMPG: 16 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LP245P1 vType: minivan vSize: large vMake: honda vModel: odessey color: black vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: ZGSPS20 vType: suv vSize: medium vMake: toyota vModel: rav4 color: white vMPG: 28 vNav: yes seatingCapacity: 7 engineCylinders: 6 transmissionType: Automatic

Please enter the vehicle make you would like to rent? toyota

Please enter the vehicle model you would like to rent? rav4

 Lisence Plate Number: HWS579T Reservation ID: 1 Vehicle Make: mercedes Vehicle Model: e550 Reservation Pickup Date: 2023-01-10 Reservation Dropoff Date: 2023-01-25 Reservation Pickup Time: 06:30:15 Reservation Dropoff Time: 02:15:45

 Lisence Plate Number: HWS584I Reservation ID: 2 Vehicle Make: honda Vehicle Model: crv Reservation Pickup Date: 2022-01-15 Reservation Dropoff Date: 2022-01-28 Reservation Pickup Time: 06:40:15 Reservation Dropoff Time: 04:15:45

 Lisence Plate Number: SWS5840 Reservation ID: 3 Vehicle Make: chevrolet Vehicle Model: camaro Reservation Pickup Date: 2023-02-05 Reservation Dropoff Date: 2023-02-15 Reservation Pickup Time: 02:30:15 Reservation Dropoff Time: 08:15:45

 Lisence Plate Number: OGS584P Reservation ID: 4 Vehicle Make: nissan Vehicle Model: 370z Reservation Pickup Date: 2023-02-08 Reservation Dropoff Date: 2023-02-27 Reservation Pickup Time: 01:30:15 Reservation Dropoff Time: 09:15:45



To keep the vehicle reservation please complete your transaction.
Would you like to complete your transaction or select another vehicle?
 Input the letter C to complete your transaction: c


You've selected to complete transaction:
Connection 11 to the MySQL Database CRSS was Successful.


Please enter your user information for validation.
Case matters, so don't add any unnecessary capital letters.
Now enter your Email Address: kanwaljeetahluwalia@gmail.com

Now enter your Driver's Lisence Number: FDB734Y


Email Address: kanwaljeetahluwalia@gmail.com


 DLN: FDB734Y

Validated.

Would you like to complete your transaction? (Y or N) y

 How many days is the reservation? 15

 plate Num: ZGSPS20
VIN: LYG739IK131528KP2
The total is: $486

Congratulations, your reservation is set and transaction processed.
 2023-04-10
 2023-04-25
 1:00
 6:00
 ZGSPS20
 FDB734Y
 kanwaljeetahluwalia@gmail.com
Would you like to return to the main CRSS menu? ( Y or N )
------------------------------------------------------------------------------------- :TEST: ----------------------------------------------------------------------------------------
Welcome to the Car Rental Service Software, CRSS:

Are your an Administrator, an existing customer or a new customer?
Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: a

Hello, would you like to Access Customer or Vehicle data (C or V): c

You've selected Access to Customer Data:

Let's make a reservation!

Connection 10 to the MySQL Database CRSS was Successful.

What date would you like to being your reservation on?
Default date format is YYYY-MM-DD: 2023-04-10

How many days will you be reserving the vehicle for?
Default date format is YYYY-MM-DD: 2023-04-25

What time will you be picking up the vehicle?
Default date format is HH:MM:SS: 1:00:00

What time will you be dropping off the vehicle?
Default date format is HH:MM:SS: 8:00:00
 plateNumber: SWS5840 vType: coupe vSize: small vMake: chevrolet vModel: camaro color: black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LPSPLP1 vType: sedan vSize: small vMake: kia vModel: rio color: pink vMPG: 29 vNav: yes seatingCapacity: 4 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS584I vType: suv vSize: medium vMake: honda vModel: crv color: blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: automatic

 plateNumber: HWS579T vType: sedan vSize: large vMake: mercedes vModel: e550 color: black vMPG: 30 vNav: yes seatingCapacity: 6 engineCylinders: 8 transmissionType: automatic

 plateNumber: HWS794I vType: suv vSize: medium vMake: toyota vModel: highlander color: white vMPG: 24 vNav: yes seatingCapacity: 5 engineCylinders: 6 transmissionType: automatic

 plateNumber: NPSMAZS vType: minivan vSize: large vMake: chrysler vModel: pacifica color: blue vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: OGS584P vType: coupe vSize: small vMake: nissan vModel: 370z color: white vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: manual

 plateNumber: OGSYT5P vType: coupe vSize: small vMake: ford vModel: mustang color: red vMPG: 16 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual

 plateNumber: LP245P1 vType: minivan vSize: large vMake: honda vModel: odessey color: black vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic

 plateNumber: ZGSPS20 vType: suv vSize: medium vMake: toyota vModel: rav4 color: white vMPG: 28 vNav: yes seatingCapacity: 7 engineCylinders: 6 transmissionType: Automatic

Please enter the vehicle make you would like to rent? toyota

Please enter the vehicle model you would like to rent? rav4

 Lisence Plate Number: HWS579T Reservation ID: 1 Vehicle Make: mercedes Vehicle Model: e550 Reservation Pickup Date: 2023-01-10 Reservation Dropoff Date: 2023-01-25 Reservation Pickup Time: 06:30:15 Reservation Dropoff Time: 02:15:45

 Lisence Plate Number: HWS584I Reservation ID: 2 Vehicle Make: honda Vehicle Model: crv Reservation Pickup Date: 2022-01-15 Reservation Dropoff Date: 2022-01-28 Reservation Pickup Time: 06:40:15 Reservation Dropoff Time: 04:15:45

 Lisence Plate Number: SWS5840 Reservation ID: 3 Vehicle Make: chevrolet Vehicle Model: camaro Reservation Pickup Date: 2023-02-05 Reservation Dropoff Date: 2023-02-15 Reservation Pickup Time: 02:30:15 Reservation Dropoff Time: 08:15:45

 Lisence Plate Number: OGS584P Reservation ID: 4 Vehicle Make: nissan Vehicle Model: 370z Reservation Pickup Date: 2023-02-08 Reservation Dropoff Date: 2023-02-27 Reservation Pickup Time: 01:30:15 Reservation Dropoff Time: 09:15:45



To keep the vehicle reservation please complete your transaction.
Would you like to complete your transaction or select another vehicle?
 Input the letter C to complete your transaction: c


You've selected to complete transaction:
Connection 11 to the MySQL Database CRSS was Successful.


Please enter your user information for validation.
Case matters, so don't add any unnecessary capital letters.
Now enter your Email Address: kanwaljeetahluwalia@gmail.com

Now enter your Driver's Lisence Number: FDB734Y


Email Address: kanwaljeetahluwalia@gmail.com


 DLN: FDB734Y

Validated.

Would you like to complete your transaction? (Y or N) y

 How many days is the reservation? 15

 plate Num: ZGSPS20
VIN: LYG739IK131528KP2
The total is: $486 2023-04-10
 2023-04-25
 1:00:00
 8:00:00
 ZGSPS20
 FDB734Y
 kanwaljeetahluwalia@gmail.com



Congratulations, your reservation is set and transaction processed.
Would you like to return to the main CRSS menu? ( Y or N )
-------------------------------------- MySQL DB check --------------------------
mysql> select * from isMakingTransaction;
+---------+-----+-------------------------------+
| DLNumT  | tID | eMailAdd                      |
+---------+-----+-------------------------------+
| FDB734Y |   9 | kanwaljeetahluwalia@gmail.com |
+---------+-----+-------------------------------+
1 row in set (0.00 sec)

mysql> select * from transactions;
+---------------+----------------------+
| transactionID | transactionTimeStamp |
+---------------+----------------------+
|             1 | 2022-11-24 20:34:14  |
|             2 | 2022-11-24 20:34:14  |
|             3 | 2022-11-24 20:34:14  |
|             4 | 2022-11-24 20:34:16  |
|             9 | 2022-12-05 19:41:40  |
+---------------+----------------------+
5 rows in set (0.00 sec)

mysql> select * from beingrented;
+---------+-----------+-------------------+------------+
| transID | plateNumb | vVIN              | vRentCount |
+---------+-----------+-------------------+------------+
|       9 | ZGSPS20   | LYG739IK131528KP2 |          1 |
+---------+-----------+-------------------+------------+
1 row in set (0.00 sec)

mysql> select * from madefor;
+-----------+-------+-------------+--------------+------------+-------------+------------+-------------+
| plateNumm | resID | vehicleMake | vehicleModel | resPickupD | resDropoffD | resPickupT | resDropoffT |
+-----------+-------+-------------+--------------+------------+-------------+------------+-------------+
| HWS579T   |     1 | mercedes    | e550         | 2023-01-10 | 2023-01-25  | 06:30:15   | 02:15:45    |
| HWS584I   |     2 | honda       | crv          | 2022-01-15 | 2022-01-28  | 06:40:15   | 04:15:45    |
| SWS5840   |     3 | chevrolet   | camaro       | 2023-02-05 | 2023-02-15  | 02:30:15   | 08:15:45    |
| OGS584P   |     4 | nissan      | 370z         | 2023-02-08 | 2023-02-27  | 01:30:15   | 09:15:45    |
| ZGSPS20   |     5 | toyota      | rav4         | 2023-04-10 | 2023-04-25  | 01:00:00   | 08:00:00    |
+-----------+-------+-------------+--------------+------------+-------------+------------+-------------+
5 rows in set (0.00 sec)

mysql> select * from wanttomake;
+-----+-------------------+-------------------------------+-------------+--------------+-------------+--------------+
| rID | driversLicenseNum | EMAdd                         | resPickupDT | resDropoffDT | resPickupTI | resDropoffTI |
+-----+-------------------+-------------------------------+-------------+--------------+-------------+--------------+
|   1 | FDB7Y59           | alitahami@gmail.com           | 2023-01-10  | 2023-01-25   | 06:30:15    | 02:15:45     |
|   2 | FDB734Y           | kanwaljeetahluwalia@gmail.com | 2022-01-15  | 2022-01-28   | 06:40:15    | 04:15:45     |
|   3 | FDB71lZ           | pgriffin@hotmail.com          | 2023-02-05  | 2023-02-15   | 02:30:15    | 08:15:45     |
|   4 | FDB709M           | crykim@gmail.com              | 2023-02-08  | 2023-02-27   | 01:30:15    | 09:15:45     |
|   5 | FDB734Y           | kanwaljeetahluwalia@gmail.com | 2023-04-10  | 2023-04-25   | 01:00:00    | 08:00:00     |
+-----+-------------------+-------------------------------+-------------+--------------+-------------+--------------+
5 rows in set (0.00 sec)

mysql> select * from vreservation;
+---------------+-----------------------+------------------------+-----------------------+------------------------+
| reservationID | reservationPickupDate | reservationDropOffDate | reservationPickupTime | reservationDropoffTime |
+---------------+-----------------------+------------------------+-----------------------+------------------------+
|             1 | 2023-01-10            | 2023-01-25             | 06:30:15              | 02:15:45               |
|             2 | 2022-01-15            | 2022-01-28             | 06:40:15              | 04:15:45               |
|             3 | 2023-02-05            | 2023-02-15             | 02:30:15              | 08:15:45               |
|             4 | 2023-02-08            | 2023-02-27             | 01:30:15              | 09:15:45               |
|             5 | 2023-04-10            | 2023-04-25             | 01:00:00              | 08:00:00               |
+---------------+-----------------------+------------------------+-----------------------+------------------------+
5 rows in set (0.00 sec)

--------------------------------------------------------------- :TEST: ---------------------------------------------------------------
Welcome to the Car Rental Service Software, CRSS:

Are your an Administrator, an existing customer or a new customer?
Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: a

Hello, would you like to Access Customer or Vehicle data (C or V): c

You've selected Access to Customer Data:

Please enter your reservation ID number: 5

Please enter your email address : kanwaljeetahluwalia@gmail.com



Connection 12 to the MySQL Database CRSS was Successful.


Reservation ID: 5
 Driver's Lisence Number: FDB734Y
 Email Address: kanwaljeetahluwalia@gmail.com
 Pickup Date: 2023-04-10
 Dropoff Date: 2023-04-25
 Pick-up Time: 01:00:00
 Dropoff Time: 08:00:00

Would you like to return to the main CRSS menu? ( Y or N )
------------------------------------------------------------------------------- TEST -----------------------------------------------------------------------------------------
Welcome to the Car Rental Service Software, CRSS:

Are your an Administrator, an existing customer or a new customer?
Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: a


Let's check your credentials, and remember that everything is case sensitive.
Please enter your username: KAhluwalia2

Thank you, now please enter your password: #CRSSadmin2&

Welcome Administrator 2, Kanwaljeet.

Hello, would you like to Access Customer or Vehicle data (C or V): c


You've selected Access to Customer Data:
For Display Customer Information (select [D])
For Customer Count (select [C])
To Insert New Customer Information (select [I])
To Delete Customer Information (select [B])
To Make Reservation (select [M])
To Delete Reservation (select [R])
To Display Pickup/Dropoff Information (select[P]):: m


You've selected to Make a Reservation:

Let's make a reservation!

Connection 10 to the MySQL Database CRSS was Successful.

What date would you like to being your reservation on?
Please enter year: 2023
Enter month: 1
Enter the day: 10

2023-1-10
Enter reservation dropoff date?
Please enter year: 2023
Enter month: 1
Enter the day: 20

2023-1-20
What time will you be picking up the vehicle?
Default date format is (HH:MM): 1:00

What time will you be dropping off the vehicle?
Default date format is (HH:MM): 9:00

 plateNumber: SWS5840 vType: coupe vSize: small vMake: chevrolet vModel: camaro color: black vMPG: 17 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual


 plateNumber: LPSPLP1 vType: sedan vSize: small vMake: kia vModel: rio color: pink vMPG: 29 vNav: yes seatingCapacity: 4 engineCylinders: 4 transmissionType: automatic


 plateNumber: HWS584I vType: suv vSize: medium vMake: honda vModel: crv color: blue vMPG: 33 vNav: no seatingCapacity: 5 engineCylinders: 4 transmissionType: automatic


 plateNumber: HWS579T vType: sedan vSize: large vMake: mercedes vModel: e550 color: black vMPG: 30 vNav: yes seatingCapacity: 6 engineCylinders: 8 transmissionType: automatic


 plateNumber: HWS794I vType: suv vSize: medium vMake: toyota vModel: highlander color: white vMPG: 24 vNav: yes seatingCapacity: 5 engineCylinders: 6 transmissionType: automatic


 plateNumber: NPSMAZS vType: minivan vSize: large vMake: chrysler vModel: pacifica color: blue vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic


 plateNumber: OGS584P vType: coupe vSize: small vMake: nissan vModel: 370z color: white vMPG: 19 vNav: no seatingCapacity: 2 engineCylinders: 6 transmissionType: manual


 plateNumber: OGSYT5P vType: coupe vSize: small vMake: ford vModel: mustang color: red vMPG: 16 vNav: yes seatingCapacity: 4 engineCylinders: 8 transmissionType: manual


 plateNumber: LP245P1 vType: minivan vSize: large vMake: honda vModel: odessey color: black vMPG: 30 vNav: yes seatingCapacity: 8 engineCylinders: 6 transmissionType: automatic


 plateNumber: ZGSPS20 vType: suv vSize: medium vMake: toyota vModel: rav4 color: white vMPG: 28 vNav: yes seatingCapacity: 7 engineCylinders: 6 transmissionType: Automatic

Please enter the vehicle make you would like to rent? toyota

Please enter the vehicle model you would like to rent? rav4



To keep the vehicle reservation please complete your transaction.
Would you like to complete your transaction or select another vehicle?
 Input the letter C to complete your transaction: c


You've selected to complete transaction:
Connection 11 to the MySQL Database CRSS was Successful.


Please enter your user information for validation.
Case matters, so don't add any unnecessary capital letters.
Now enter your Email Address: kanwaljeetahluwalia@gmail.com

Now enter your Driver's Lisence Number: FDB734Y


Email Address: kanwaljeetahluwalia@gmail.com


 DLN: FDB734Y

Validated.

Would you like to complete your transaction? (Y or N) y

How many days is the reservation? 10

 plate Num: ZGSPS20
VIN: LYG739IK131528KP2
The total is: $324 2023-1-10
 2023-1-20
 1:00
 9:00
 ZGSPS20
 FDB734Y
 kanwaljeetahluwalia@gmail.com



Congratulations, your reservation is set and transaction processed!
Here are your reservation details:

Reservation ID:8
 Driver's Lisence Number: FDB734Y
 Email Address:kanwaljeetahluwalia@gmail.com
 Pickup Date: 2023-01-10
 Dropoff Date: 2023-01-20
 Pick-up Time: 01:00:00
 Dropoff Time: 09:00:00


Would you like to return to the Customer Data menu? ( Y or N )
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */