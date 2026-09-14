with base as (select caller_id, 
(select country_id from phone_info p where p.caller_id = pc.caller_id) as 
caller_country,
receiver_id, 
(select country_id from phone_info p where p.caller_id = pc.receiver_id) as 
receiver_country
from phone_calls pc)

select round(count(*)*100.0/(select count(*) from phone_calls),1) as international_calls_pct
from base 
where caller_country != receiver_country