# Write your MySQL query statement below
select p.product_id, (
    coalesce(
        (
            select pr.new_price
            from products pr
            where p.product_id = pr.product_id
            and pr.change_date <= '2019-08-16'
            ORDER BY pr.change_date DESC LIMIT 1
        )
        ,10)
) as price
from (SELECT DISTINCT product_id
        from products) as p


-- solution - 2 (took 1 hr almost)
with base as (
    select product_id, new_price, change_date
    from products 
    where (product_id, change_date) in
    (
        select product_id, max(change_date) as change_date
        from products
        where change_date <= '2019-08-16'
        group by product_id
    )
)
select p.product_id, coalesce(b.new_price, 10) as price
from (
    select distinct product_id
    from products
) p left join base b on
p.product_id = b.product_id