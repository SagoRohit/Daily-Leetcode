with base as (
select 
cast(measurement_time as date) as measurement_day,
measurement_value,
dense_rank() over(partition by cast(measurement_time as date)
order by measurement_time asc ) as rnk
from measurements)

select measurement_day,
sum(measurement_value) filter(where rnk%2!=0) as odd_sum,
sum(measurement_value) filter(where rnk%2=0) as even_sum
from  base 
GROUP by measurement_day

-- cast use to filter out the date : cast(measurement_time as day)
-- filter to condition sum()