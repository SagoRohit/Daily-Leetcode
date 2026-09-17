with base as (
  select extract(year from transaction_date) year1, product_id, spend as curr_year_spend,
    lag(spend) over(partition by product_id 
      order by extract(year from transaction_date) asc) as prev_year_spend
  from user_transactions)

select year1, product_id, curr_year_spend, prev_year_spend,
  round((curr_year_spend - prev_year_spend)*100.0/prev_year_spend,2) as yoy_rate
from base