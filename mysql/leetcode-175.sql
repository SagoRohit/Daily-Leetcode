select firstname, lastname, city, state
from Person left join Address
on Person.PersonID = Address.PersonID
;