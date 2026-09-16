select 
  extract(month from curr_month.event_date) as mth,
  count(distinct curr_month.user_id) as monthly_active_users
from user_actions as curr_month
where exists (
  select last_month.user_id
  from user_actions as last_month
  where last_month.user_id = curr_month.user_id
  and extract(month from last_month.event_date) = 
  extract(month from curr_month.event_date - interval '1 month')
)
  and extract(month from curr_month.event_date)= 7 and 
  extract(year from curr_month.event_date) = 2022
group by extract(month from curr_month.event_date)