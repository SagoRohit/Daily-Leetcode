-- Write your MySQL query statement below
SELECT  p.firstname  as firstName, p.lastname as lastName, a.city, a.state
from person p left join address a
on p.personid = a.personid