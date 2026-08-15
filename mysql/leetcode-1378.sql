# Write your MySQL query statement below
select coalesce(u.unique_id,null) as unique_id, e.name
from employees e left join employeeuni u
on e.id = u.id
