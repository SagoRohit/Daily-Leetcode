select round(count(DISTINCT player_id)/(select count(DISTINCT player_id)
from activity),2) as fraction
from activity
where (player_id,date_sub(event_date, interval 1 day)) IN
(select player_id, min(event_date) as first_log_in
from activity
group by player_id)