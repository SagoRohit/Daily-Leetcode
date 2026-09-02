
select DISTINCT
(
select count(user_id)
from viewership
where device_type = 'laptop'
) as laptop_view,

(select count(user_id)
from viewership
where device_type in ('tablet', 'phone')) as mobile_view
from viewership