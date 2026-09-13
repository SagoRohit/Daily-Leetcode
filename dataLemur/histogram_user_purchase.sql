with base as (select distinct transaction_date, user_id,
count(product_id) over(partition by TRANSACTION_date, user_id) as cnt
from user_transactions
order by TRANSACTION_date)


select transaction_date, user_id, cnt as purchase_count
from base  b
where TRANSACTION_date = 
(
select max(TRANSACTION_date)
from base b1
where b1.user_id = b.user_id)