-- Write your MySQL query statement below
SELECT c.name as Customers
from Customers c left join 
orders o ON
c.id = o.customerid
where o.id is NULL