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
