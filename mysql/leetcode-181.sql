-- Write your MySQL query statement below
select e.name as Employee
from employee e 
where e.salary > ( select m.salary 
                    from employee m
                    where e.managerid = m.id);

SELECT e.name as Employee
from employee e left join employee m
on e.managerid = m.id
where e.salary > m.salary;