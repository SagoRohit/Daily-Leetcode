select user_id, days_between
from (
select distinct user_id, 
datediff((select max(post_date) from posts p1 where p.user_id = p1.user_id and extract(year from post_date) =2021 ), 
(select min(post_date) from posts p1 where p1.user_id=p.user_id and extract(year from post_date) =2021)) as days_between
from posts p
) t
where days_between != 0