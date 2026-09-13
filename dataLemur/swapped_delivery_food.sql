with base as (
select count(*) total_count
from orders)

select 
case 
when order_id %2!=0 and order_id!= total_count then order_id + 1
when order_id %2!=0 and order_id=total_count then order_id
else order_id -1 
end as corrected_order_id, item
from orders 
cross join base 
order by corrected_order_id