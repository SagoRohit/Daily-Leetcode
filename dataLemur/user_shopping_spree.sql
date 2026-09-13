with base as (
select user_id, transaction_date as day1,
lead(transaction_date,1) over(partition by user_id order by transaction_date) as day2,
lead(transaction_date,2) over(partition by user_id order by transaction_date) as day3
from transactions)



select user_id
from base 
where day2 is not null and day3 is not null and 
(day2::date-day1::date)=1 and (day3::date-day2::date)=1