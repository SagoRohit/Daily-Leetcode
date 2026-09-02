with base as (
select user_id, count(tweet_id) as cnt
from tweets
where extract(year from tweet_date) = 2022
group by user_id
)
select cnt as tweet_bucket, count(*) as users_num
from base 
group by cnt