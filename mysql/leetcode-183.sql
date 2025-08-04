select name as Customers 
from Customers 
left join  Orders on
Customers.id = Orders.CustomerId
where orders.CustomerId is Null
;