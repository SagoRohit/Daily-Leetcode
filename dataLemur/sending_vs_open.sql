select ab.age_bucket,

round(
  (select sum(time_spent) 
  from activities a 
  where a.user_id in  (select user_id from age_breakdown ag where ag.age_bucket = ab.age_bucket) and 
  a.activity_type = 'send')*100.0/
  (select sum(time_spent)
  from activities a 
  where a.user_id in  (select user_id from age_breakdown ag where ag.age_bucket = ab.age_bucket) and 
  a.activity_type!='chat')
,2) as send_perc,


round(
  (select sum(time_spent) 
  from activities a 
  where a.user_id in  (select user_id from age_breakdown ag where ag.age_bucket = ab.age_bucket) and 
  a.activity_type = 'open')*100.0/
  (select sum(time_spent)
  from activities a 
  where a.user_id in  (select user_id from age_breakdown ag where ag.age_bucket = ab.age_bucket) and 
  a.activity_type!='chat')
,2) as open_perc

from age_breakdown ab join activities ac on 
ab.user_id = ac.user_id
group by ab.age_bucket