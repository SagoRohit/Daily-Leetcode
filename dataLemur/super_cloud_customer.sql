select c.customer_id
from customer_contracts c inner join products p on 
c.product_id = p.product_id
group by c.customer_id
having count(DISTINCT p.product_category) = (
select count(DISTINCT product_category)
from products)