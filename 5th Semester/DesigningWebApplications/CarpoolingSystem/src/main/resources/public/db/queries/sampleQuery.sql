use carpoolingsystem;

SELECT r.IdReservation,u.UserName as Passenger,o.UserName as TripOwner,t.Price,cf.CityName as CityFrom,ct.CityName as CityTo FROM
reservations as r
left join users as u on r.IdUser = u.IdUser
left join trips as t on t.IdTrip = r.IdTrip
left join (select IdUser,UserName from users) as o on  o.IdUser = t.IdOwner
left join (select IdCity,CityName from cities) as cf on  cf.IdCity = t.IdStartCity
left join (select IdCity,CityName from cities) as ct on  ct.IdCity = t.IdDestinationCity
