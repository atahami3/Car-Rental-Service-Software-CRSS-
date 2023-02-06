/* --------------- CRSS DB Insert Statments ---------------------
* Created By:
*             Kanwaljeet Ahluwalia, Ali Tahami
* Professor M. Peiravi
* CPSC 362-01
* These are the dummy values to be INSERTED into the
* CRSS database.
*
-------------------------------------------------------------- */
INSERT INTO vehicles
VALUES("CYG739IKAH1528F09","HWS579T","sedan", "large", "mercedes","e550", "black", 30, "yes", 6, 8, "automatic");
INSERT INTO vehicles
VALUES("CYG739IKAH1528B32","HWS584I","suv", "medium", "honda","crv", "blue", 33, "no", 5, 4, "automatic");
INSERT INTO vehicles
VALUES("AYG739IKAH1528Z91","SWS5840","coupe", "small", "chevrolet","camaro", "black", 17, "yes", 4, 8, "manual");
INSERT INTO vehicles
VALUES("KYG739IKAH1528K01","OGS584P","coupe", "small", "nissan", "370z", "white", 19, "no", 2, 6, "manual");
INSERT INTO vehicles
VALUES("KYG739IKAH1528K02","OGSYT5P","coupe", "small", "ford", "mustang", "red", 16, "yes", 4, 8, "manual");
INSERT INTO vehicles
VALUES("LYG739IK131528KP2","ZGSPS20","suv", "medium", "toyota", "rav4", "white", 28, "yes", 7, 6, "Automatic");
INSERT INTO vehicles
VALUES("B1L239IK13101MSI1","LPSPLP1","sedan", "small", "kia", "rio", "pink", 29, "yes", 4, 4, "automatic");
INSERT INTO vehicles
VALUES("L0G239IK131MLAQP9","LP245P1","minivan", "large", "honda", "odessey", "black", 30, "yes", 8, 6, "automatic");
INSERT INTO vehicles
VALUES("GFN23LPQQ31MLAQLL","NPSMAZS","minivan", "large", "chrysler", "pacifica", "blue", 30, "yes", 8, 6, "automatic");
INSERT INTO vehicles
VALUES("CYG739IZYT1528B32","HWS794I","suv", "medium", "toyota","highlander", "white", 24, "yes", 5, 6, "automatic");

INSERT INTO vehicles
VALUES("CYG739IZYT1512345","HWS754Q","sedan", "large", "bmw","750li", "blue", 22, "yes", 5, 8, "automatic");


INSERT INTO customers
VALUES("FDB7Y59","alitahami@gmail.com", "#GiantBoulder1$", "ali","tahami", '1998-01-25', "Irvine", 15, "1234 Where In The World AVE", "California", "92604", 24);
INSERT INTO customers
VALUES("FDB734Y","kanwaljeetahluwalia@gmail.com", "#DarthVaderSucks3&", "kanwaljeet","ahluwalia", '1986-10-15', "Fullerton", "N/A", "45783 Chuck Norris Cir.", "California", "92835", 36);
INSERT INTO customers
VALUES("FDB71lZ","pgriffin@hotmail.com","#MegSucks%", "peter", "griffin", '1977-06-12', "Quahog", "N/A", "31 Spooner Street", "Rhode Island", "00093", 44);
INSERT INTO customers
VALUES("FDB709M","crykim@gmail.com", "#Accounting1@", "crystal", "kim", '1999-11-05', "Garden Grove", 19, "1345 New Land", "Nevada", "95194", 23);
INSERT INTO customers
VALUES("FDB716D","himpson@gmail.com", "#password$", "homer", "simpson", '1956-05-12', "Springfield", "N/A", "742 Evergreen Terrace", "Oregon", "97205", 66);

/* These values are auto generated when making a transaction */
INSERT INTO transactions
VALUES();
INSERT INTO transactions
VALUES();
INSERT INTO transactions
VALUES();
INSERT INTO transactions
VALUES();

/* ----------------------------- Deleted table B/C Unnecessary -----------------------
INSERT INTO wantToRent
VALUES("FDB7Y59", "AliTahami@gmail.com","HWS579T", "CYG739IKAH1528F09");
INSERT INTO wantToRent
VALUES("FDB734Y", "KanwaljeetAhluwalia@gmail.com","HWS584I", "CYG739IKAH1528B32");
INSERT INTO wantToRent
VALUES("FDB71lZ","pGriffin@hotmail.com","SWS5840", "AYG739IKAH1528Z91");
INSERT INTO wantToRent
VALUES("FDB709M","CryKim@gmail.com","OGS584P", "KYG739IKAH1528K01");
----------------------------------------------------------------------------------- */

INSERT INTO isMakingTransaction
VALUES("FDB7Y59", 1 , "alitahami@gmail.com");
INSERT INTO isMakingTransaction
VALUES("FDB734Y", 2,"kanwaljeetahluwalia@gmail.com");
INSERT INTO isMakingTransaction
VALUES("FDB71lZ", 3,"pgriffin@hotmail.com");
INSERT INTO isMakingTransaction
VALUES("FDB709M", 4, "crykim@gmail.com");

INSERT INTO beingRented
VALUES( 1,"HWS579T", "CYG739IKAH1528F09", 1);
INSERT INTO beingRented
VALUES( 2,"HWS584I", "CYG739IKAH1528B32", 1);
INSERT INTO beingRented
VALUES( 3,"SWS5840", "AYG739IKAH1528Z91", 1);
INSERT INTO beingRented
VALUES( 4,"OGS584P", "KYG739IKAH1528K01", 1);

/*( reservationID must be zero here to use AUTO_INCREMENT, don't know why?? )*/
INSERT INTO vReservation
VALUES(0,'2023-01-10', '2023-01-25', '06:30:15', '02:15:45');
INSERT INTO vReservation
VALUES(0,'2022-01-15', '2022-01-28', '06:40:15', '04:15:45');
INSERT INTO vReservation
VALUES( 0,'2023-02-05', '2023-02-15', '02:30:15', '08:15:45');
INSERT INTO vReservation
VALUES( 0,'2023-02-08', '2023-02-27' , '01:30:15', '09:15:45');

INSERT INTO madeFor
VALUES( "HWS579T", 1, "mercedes", "e550", '2023-01-10', '2023-01-25', '06:30:15', '02:15:45');
INSERT INTO madeFor
VALUES( "HWS584I", 2, "honda", "crv", '2022-01-15', '2022-01-28', '06:40:15', '04:15:45');
INSERT INTO madeFor
VALUES( "SWS5840", 3, "chevrolet", "camaro", '2023-02-05', '2023-02-15', '02:30:15', '08:15:45');
INSERT INTO madeFor
VALUES( "OGS584P", 4, "nissan", "370z", '2023-02-08', '2023-02-27', '01:30:15', '09:15:45');

INSERT INTO wantToMake
VALUES( 1, "FDB7Y59", "alitahami@gmail.com", '2023-01-10', '2023-01-25', '06:30:15', '02:15:45');
INSERT INTO wantToMake
VALUES( 2, "FDB734Y", "kanwaljeetahluwalia@gmail.com", '2022-01-15', '2022-01-28', '06:40:15', '04:15:45');
INSERT INTO wantToMake
VALUES( 3, "FDB71lZ", "pgriffin@hotmail.com", '2023-02-05', '2023-02-15', '02:30:15', '08:15:45');
INSERT INTO wantToMake
VALUES( 4, "FDB709M", "crykim@gmail.com", '2023-02-08', '2023-02-27', '01:30:15', '09:15:45');


/* CREATE TABLE beingRented (
   transID VARCHAR(10) NOT NULL,
   plateNumb VARCHAR(7) NOT NULL,
   vVIN VARCHAR(17) NOT NULL,
   vRentCount int NOT NULL,
   PRIMARY KEY(transID, plateNumb, vVIN),
   FOREIGN KEY(transID) REFERENCES transactions(transactionID),
   FOREIGN KEY(plateNumb) REFERENCES vehicles(plateNumber),
   FOREIGN KEY(vVIN) REFERENCES vehicles(vVin)
);
*/


/*  */
