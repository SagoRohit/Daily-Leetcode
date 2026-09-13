with base as (
select 
rank() over(partition by category_name
order by sales_quantity desc, rating desc) as rnk,
category_name,
product_name,
sales_quantity,
rating
from products p 
join product_sales as sales on p.product_id = sales.product_id)

select category_name, product_name
from base 
where rnk = 1
order by category_name