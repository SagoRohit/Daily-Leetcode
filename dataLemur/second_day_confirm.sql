select e.user_id
-- select *
from emails e left join texts t on 
e.email_id = t.email_id 
where extract(day from t.action_date) - extract(day from e.signup_date) =1 
and t.signup_action = 'Confirmed'
