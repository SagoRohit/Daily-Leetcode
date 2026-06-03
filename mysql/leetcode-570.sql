select e1.name
from employee e1 join
(
select managerid, count(*) as report
from employee
group by managerid
having count(*)>=5
) e2
on e1.id = e2.managerid;