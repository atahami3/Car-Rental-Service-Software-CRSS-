/* --------------- CRSS DB Tables ---------------------
* Created by:
*   Kanwaljeet Ahluwalia, Ali Tahami
* Professor M. Peiravi
* CPSC 362-01
* The is the database created for CPSC 362 Project
*
---------------------------------------------------- */

/* ------------------------------ PARENT TABLES -------------------------------------*/
CREATE TABLE vehicles (
   vVin VARCHAR(17) NOT NULL,
   plateNumber VARCHAR(7) NOT NULL,
   vType VARCHAR(10) NOT NULL,
   vSize VARCHAR(10) NOT NULL,
   vMake VARCHAR(20) NOT NULL,
   vModel VARCHAR(20) NOT NULL,
   color VARCHAR(10) NOT NULL,
   vMPG INT NOT NULL,
   vNav VARCHAR(20) NOT NULL,
   seatingCapacity INT NOT NULL,
   engineCylinders INT NOT NULL,
   transmissionType VARCHAR(10) NOT NULL,
   PRIMARY KEY(vVin),
   UNIQUE(plateNumber)
);

/* ----------------------------------------------------------------------
* Needed to use UNIQUE b/c we cannot have multiple primary keys that
* are referenced by child tables. Throws error 1882 constraint issues.
---------------------------------------------------------------------- */
CREATE TABLE customers (
   driversLicenseNumber VARCHAR(8) NOT NULL,
   emailAddress VARCHAR(50) NOT NULL,
   password VARCHAR(25) NOT NULL,
   customerFName VARCHAR(25) NOT NULL,
   customerLName VARCHAR(25) NOT NULL,
   customerBirthday DATE NOT NULL,
   cityOfResidence VARCHAR(20) NOT NULL,
   apartmentNumber VARCHAR(10) NOT NULL,
   streetAddress VARCHAR(50) NOT NULL,
   stateOfResidence VARCHAR(25) NOT NULL,
   zipCode VARCHAR(10),
   customerAge INT NOT NULL,
   PRIMARY KEY(driversLicenseNumber),
   UNIQUE(emailAddress, password)
);
/* ----------------------------------------------------------------------
*
*
---------------------------------------------------------------------- */
CREATE TABLE transactions(
   transactionID INT AUTO_INCREMENT,
   transactionTimeStamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,
   PRIMARY KEY(transactionID)
);
/* ----------------------------------------------------------------------
* -> Vehicle rental registraion Dates & Times.
*
---------------------------------------------------------------------- */
CREATE TABLE vReservation (
  reservationID INT AUTO_INCREMENT,
  reservationPickupDate DATE NOT NULL,
  reservationDropOffDate DATE NOT NULL,
  reservationPickupTime TIME NOT NULL,
  reservationDropoffTime TIME NOT NULL,
  PRIMARY KEY(reservationID)
);
/* ------------------------ END PARENT TABLES ------------------------ */
/* ------------------------ END PARENT TABLES ------------------------ */


/*  ----------------- Deleted table ----------------
---------------------- CHILD OR RELATIONAL TABLES ------------------ */
/* CREATE TABLE wantToRent(
   DLNum VARCHAR(8) NOT NULL,
   emailAdd VARCHAR(50) NOT NULL,
   plateNum VARCHAR(7) NOT NULL,
   VIN VARCHAR(17) NOT NULL,
   FOREIGN KEY(DLNum) REFERENCES customers(driversLicenseNumber) ON DELETE CASCADE,
   FOREIGN KEY(plateNum) REFERENCES vehicles(plateNumber) ON DELETE CASCADE,
   FOREIGN KEY(VIN) REFERENCES vehicles(vVin) ON DELETE CASCADE,
   FOREIGN KEY(emailAdd) REFERENCES customers(emailAddress) ON DELETE CASCADE
); */
/* ----------------------------------------------------------------------
*
*
---------------------------------------------------------------------- */
CREATE TABLE isMakingTransaction(
   DLNumT VARCHAR(8) NOT NULL,
   tID INT NOT NULL,
   eMailAdd VARCHAR(50) NOT NULL,
   FOREIGN KEY(DLNumT) REFERENCES customers(driversLicenseNumber) ON DELETE CASCADE,
   FOREIGN KEY(tID) REFERENCES transactions(transactionID) ON DELETE CASCADE,
   FOREIGN KEY(eMailAdd) REFERENCES customers(emailAddress) ON DELETE CASCADE,
   UNIQUE(tID, DLNumT, eMailAdd)
);
/* ----------------------------------------------------------------------
*
*
---------------------------------------------------------------------- */
CREATE TABLE beingRented (
   transID INT NOT NULL REFERENCES transactions(transactionID) ON DELETE CASCADE,
   plateNumb VARCHAR(7) NOT NULL,
   vVIN VARCHAR(17) NOT NULL,
   vRentCount INT NOT NULL,
   FOREIGN KEY(plateNumb) REFERENCES vehicles(plateNumber) ON DELETE CASCADE,
   FOREIGN KEY(vVIN) REFERENCES vehicles(vVin) ON DELETE CASCADE
);
/* ----------------------------------------------------------------------
* -> toMakeFor is a child table that references vReservation and vehicles
* to
//    UNIQUE(transID, plateNumb, vVIN)
---------------------------------------------------------------------- */
CREATE TABLE madeFor (
  plateNumm VARCHAR(8) NOT NULL,
  resID INT PRIMARY KEY,
  vehicleMake VARCHAR(20) NOT NULL REFERENCES vehicles(vMake) ON DELETE CASCADE,
  vehicleModel VARCHAR(20) NOT NULL REFERENCES vehicles(vModel) ON DELETE CASCADE,
  resPickupD DATE NOT NULL REFERENCES vReservation(reservationPickupDate) ON DELETE CASCADE,
  resDropoffD DATE NOT NULL REFERENCES vReservation(reservationDropOffDate) ON DELETE CASCADE,
  resPickupT TIME NOT NULL REFERENCES vReservation(reservationPickupTime) ON DELETE CASCADE,
  resDropoffT TIME NOT NULL REFERENCES vReservation(reservationDropoffTime) ON DELETE CASCADE,
  FOREIGN KEY(plateNumm) REFERENCES vehicles(plateNumber) ON DELETE CASCADE,
  FOREIGN KEY(resID) REFERENCES vReservation(reservationID) ON DELETE CASCADE
);
/* ----------------------------------------------------------------------

TID INT NOT NULL,
FOREIGN KEY(TID) REFERENCES transactions(transactionID) ON DELETE CASCADE */
/* -> Vehicle rental registraion Dates & Times.
*/
---------------------------------------------------------------------- */
CREATE TABLE wantToMake (
  rID INT PRIMARY KEY,
  driversLicenseNum VARCHAR(10) NOT NULL,
  EMAdd VARCHAR(50) NOT NULL,
  resPickupDT DATE NOT NULL REFERENCES vReservation(reservationPickupDate) ON DELETE CASCADE,
  resDropoffDT DATE NOT NULL REFERENCES vReservation(reservationDropOffDate) ON DELETE CASCADE,
  resPickupTI TIME NOT NULL REFERENCES vReservation(reservationPickupTime) ON DELETE CASCADE,
  resDropoffTI TIME NOT NULL REFERENCES vReservation(reservationDropoffTime) ON DELETE CASCADE,
  FOREIGN KEY(EMAdd) REFERENCES customers(emailAddress) ON DELETE CASCADE,
  FOREIGN KEY(rID) REFERENCES vReservation(reservationID) ON DELETE CASCADE,
  FOREIGN KEY(driversLicenseNum) REFERENCES customers(driversLicenseNumber) ON DELETE CASCADE
);
/* ------------------------------------- END CHILD TABLES  ------------------------------------ */
/* ------------------------------------- END CHILD TABLES  ------------------------------------ */



/*
----------------------------------- Common Commands ------------------------------------
use crss
SHOW TABLES;
SHOW COLUMNS FROM vehicles;

SET FOREIGN_KEY_CHECKS = 0;
drop table vReservation;
SET FOREIGN_KEY_CHECKS = 1;
-----------------------------------------------------------

DECLARE @startDate DATE = '2023-01-01';
DECLARE @endDate DATE = '2023-12-31';

WITH recursiveDateCTE AS
(SELECT @startDate AS [DATE]
UNION ALL
SELECT DATEADD(dd, 1, [DATE]
FROM recursiveDateCTE
WHERE DATEADD(dd, 1, [DATE])
SELECT [DATE] FROM recursiveDateCTE
);

;WITH recursiveDateCTE AS
(
    SELECT 1 AS Count                       /* Anchor Query
    UNION ALL                             /* Separation/UNION
    SELECT Count+1 FROM recursiveDateCTE        /* Recursive Query --> returns value of 2
    WHERE Count < 10                        /* Termination Condition --> count less than 10
);

;WITH recursiveDateCTE AS
(
    SELECT 1 AS Count
    UNION ALL
    SELECT Count+1 FROM recursiveCTE
    WHERE Count < 10
)

SELECT * FROM recursiveCTE;

*/
/* In MySQL you can use a WHERE clause to limit the rows from a date field within a certain period of time: ... WHERE `date_col` BETWEEN '2015-08-18 23:03:00' AND '2015-08-19 23:03:00') */
