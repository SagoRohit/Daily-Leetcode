select user_id,
spend, transaction_date
from (
  select user_id, 
  spend, transaction_date, 
  dense_rank() over(PARTITION by user_id order by transaction_date asc) as rnk
  from transactions) t
where rnk = 3
order by user_id asc