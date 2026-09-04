select e.employee_id, e.name
from employee e left join employee m on 
e.manager_id = m.employee_id
where e.salary > m.salary