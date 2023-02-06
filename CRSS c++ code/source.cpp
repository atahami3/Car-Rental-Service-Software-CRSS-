/*==================================================================
* Ali Tahami, Kanwaljeet Ahluwalia
* Professor M. Peiravi
* CPSC 362 - Software Engineering
* DATE:
* ------------------------------------------------------------------
* Description: CRSS v3.0:
* CRSS is a care rental software service.
==================================================================*/

// =================== Source ==========================
#include "vehicle.h"
#include "customerInfo.h"

/* MySQL Server Name */
#define SERVER "localhost"

/* MySQL User Name */
#define USER "root"

/* MySQL Server Password */
#define PASSWORD "password"

/* MySQL Database Name */
#define DATABASE "crss"

// -----------------------------------------------------------------------------
int qState3;
MYSQL* conn5;
MYSQL_ROW row3;
MYSQL_RES* res3;
// -----------------------------------------------------------------------------

bool isAdmin();
bool isCustomer();

int main()
{

    char choice1 = 'A';
    char choice2 = 'V';
    char choice3 = 'Y';
    bool isValid = false;

    // ------------- Class instance variables -----------------
    Customer c;
    Vehicle v;
    // --------------------------------------------------------

    cout << "Welcome to the Car Rental Service Software, CRSS: \n" << endl;

    do{

        cout << "Are your an Administrator, an existing customer or a new customer?  \n"
        << "Select (A) for Administrator, (E) for an existing customer or (N) for a New customer: ";
        cin.get(choice1);
        cin.ignore();
        cout << endl;

        switch (toupper(choice1))
        {
            // ---------------------- choice1 = A -------------------------
            case 'A':
            isValid = isAdmin();

            if(isValid == true)
            {

                cout << "\nHello, would you like to Access Customer or Vehicle data (C or V): ";
                cin.get(choice2);
                cin.ignore();
                cout << endl;

                switch (toupper(choice2))
                {
                case 'C':
                    cout << "\nYou've selected Access to Customer Data: ";
                    c.adminAccessC(c);
                    break;
                case 'V':
                    cout << "\nYou've selected Access to Vehicle Data: ";
                    v.adminAccessV(v);
                    break;
                }
                break;
            }
            else {
                break;
            }
                // ---------------------- choice1 = E -------------------------
            case 'E':
                isValid = isCustomer();

                if (isValid == true)
                {
                    cout << "\nHello Customer, let's book your vehicle! ";

                    switch (toupper(choice2))
                    {
                    case 'V':
                        c.custAccessC(c);
                        break;
                    }
                    break;
                }
                else {
                    break;
                }
                // ---------------------- choice1 = N -------------------------
            case 'N':
                    cout << "\nHello Customer, let's create your new account! ";
                
                    switch (toupper(choice2))
                    {
                        case 'V':
                        c.insertCustomerInfo();
                        break;
                    }
                    break;
        }

    cout << "\nWould you like to return to the main CRSS menu? " 
        << "( Y or N ) ";
    cin.get(choice3);
    cin.ignore();
    cout << endl;
    system("cls");

    } while (toupper(choice3 == 'y'));
            
          
    system("pause");
    return 0;
}
// -------------------------------------------------------------------------------------------------------------------------------------------------
// -> This function will validate administrator credentials and return a boolean T/F to the main switch statement, so the administrators 
// can continue.
// -> No parameters will be passed. 
// -------------------------------------------------------------------------------------------------------------------------------------------------
bool isAdmin()
{
    string adminUSN1 = "ATahami1";
    string adminUSN2 = "KAhluwalia2";
    string adminPSW1 = "@CRSSadmin1$";
    string adminPSW2 = "#CRSSadmin2&";

    string checkUSN = "";
    string checkPSW = "";

    int count = 0;
    const int ATTEMPTS = 3;

    while (count < ATTEMPTS)
    {

        cout << "\nLet's check your credentials, and remember that everything is case sensitive. \n"
            << "Please enter your username: ";
        getline(cin, checkUSN);
        cout << "\nThank you, now please enter your password: ";
        getline(cin, checkPSW);


        if ((checkUSN == adminUSN1) && (checkPSW == adminPSW1))
        {
            cout << "\nWelcome Administrator 1, Ali." << endl;
            return true;
        }
        else if ((checkUSN == adminUSN2) && (checkPSW == adminPSW2))
        {
            cout << "\nWelcome Administrator 2, Kanwaljeet." << endl;
            return true;
        }
        else {
            count++;
            cout << "\nEither your username or password are incorrect. \n"
                << "You have " << (ATTEMPTS - count) << " attempts left. \n"
                << "Please try again. \n\n";

            if (count >= 3)
            {
                cout << "You have exceeded the number of attempts allowed to login, goodbye. \n";
                return false;
            }
        }
        system("pause");
        //cout << "Press any key to continue. ";
        system("cls"); // clear previous I/O
    }
    return false;
}
bool isCustomer()
{

    string checkUSN = "";
    string checkPSW = "";
    int count = 0;
    const int ATTEMPTS = 3;

    conn5 = mysql_init(0);  // initializes a MYSQL object suitable for mysql_real_connect() fn.

    // ------------------------------ Connecting to MySQL --------------------------------------
    conn5 = mysql_real_connect(conn5, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0);
    // -----------------------------------------------------------------------------------------

    while (count < ATTEMPTS)
    {
        cout << "Let's check your credentials. \n"
            << "Please enter your username: ";
        getline(cin, checkUSN);
        cout << "\nPlease enter your password: ";
        getline(cin, checkPSW);

        // ------------------------------------------------------ This query will check the email address and PSW for customer access ----------------------------------------------------------------------
        string check_availability_query = "SELECT * FROM customers";

        const char* q5 = check_availability_query.c_str();
        qState3 = mysql_query(conn5, q5);

        if (!qState3)
        {
            res3 = mysql_store_result(conn5);


            while (row3 = mysql_fetch_row(res3))
            {
               // cout << "\n Lisence Plate Number: " << row3[1]
               //     << "\n Reservation ID: " << row3[2] << endl;

                // -----------------------------------------------------------------------------------------------------------------------------------------------
                // Now we will search through every iteration of the results to see if the user entered details,
                // vMake && vModel && reservationPickupDate && reservationDropOff all match, if these detail match then the vehile is already reserved and not
                // available for rent during those periods. 
                // -----------------------------------------------------------------------------------------------------------------------------------------------
                if ((checkUSN == row3[1]) && (checkPSW == row3[2]))
                {

                    /* ----------------------------------------------- TEST ---------------------------------------------------------------------------
                    // cout << vMake << " " << vModel << " " << this->reservationPickupDate << " " << this->reservationDropOff << endl << endl;
                    -------------------------------------------------------------------------------------------------------------------------------- */

                    cout << "\nWelcome " << row3[1] << ", you now have access to your account. \n";
                    return true;
                }

            }

        }
        // -------------------- Connection error handling -------------------------
        else
        {
            printf("\n\nMySQL Database Connection Unsuccessful.");
            exit(1);
        }
        
        count++;
        cout << "\nEither your username or password are incorrect. \n"
            << "You have " << (ATTEMPTS - count) << " attempts left. \n"
            << "Please try again. \n\n";

        if (count >= 3)
        {
            cout << "You have exceeded the number of attempts allowed to login, goodbye. \n";
            return false;
        }

        system("pause");
        //cout << "Press any key to continue. ";
        system("cls"); // clear previous I/O
       //  return false;
    }
    // ------------------------------- Close MySQL Conn 8 -----------------------------------------
    mysql_close(conn5);
    if (conn5 == 0)
    {
        perror("\n\nSomething went wrong, MySQL connection did not closed. ");
        exit(1);
    }
    /* ------------------------- Explaination -----------------------------
    * mysql_close() deallocates the connection handler pointed to by mysql
    * if the handler was allocated automatically by mysql_init().
    -------------------------------------------------------------------- */

    return false;
}
/* =============================================================== END of Main ======================================================================== */