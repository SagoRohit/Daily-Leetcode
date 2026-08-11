select DISTINCT customer_id
from customer
GROUP BY customer_id
having count(DISTINCT product_key) = 
(select count(product_key)
from product)