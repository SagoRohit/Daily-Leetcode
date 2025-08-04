select Employee.name, Bonus.bonus
from Employee 
left join Bonus 
on Employee.empId= Bonus.empId
where Bonus.bonus is  NULL
or Bonus.bonus < 1000
;