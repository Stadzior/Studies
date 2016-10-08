INSERT INTO users(UserName,Password,Email) values("Zorro","zzz123","Zorro@z.es");
INSERT INTO users(UserName,Password,Email) values("Sebix","seba123","Seba@s.pl");
INSERT INTO users(UserName,Password,Email) values("Putin","putin123","Putin@r.ru");
INSERT INTO users(UserName,Password,Email) values("Merkel","merkel123","Merkel@d.de");

INSERT INTO cities(CityName) values("Kielce");
INSERT INTO cities(CityName) values("Warszawa");
INSERT INTO cities(CityName) values("Kraków");
INSERT INTO cities(CityName) values("Łódź");

INSERT INTO cars(Brand,Model) values("Opel","Vectra");
INSERT INTO cars(Brand,Model) values("Honda","Civic");
Insert INTO cars(Brand,Model) values("Audi","A4");
INSERT INTO cars(Brand,Model) values("Volkswagen","Golf");
INSERT INTO cars(Brand,Model) values("Seat","Leon");

INSERT INTO trips(StartDate,IdStartCity,IdDestinationCity,Price,SeatsLeft,IdOwner,IdCar) values(now(),1,4,18,2,5,1);
INSERT INTO trips(StartDate,IdStartCity,IdDestinationCity,Price,SeatsLeft,IdOwner,IdCar) values(now(),2,3,30,4,4,2);

INSERT INTO reservations(IdUser,IdTrip,AmountOfSeats)values(6,2,1);
INSERT INTO reservations(IdUser,IdTrip,AmountOfSeats)values(7,2,1);