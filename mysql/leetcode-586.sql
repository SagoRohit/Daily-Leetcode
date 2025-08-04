select customer_number 
from orders
group by customer_number 
having count(order_number)>1
;