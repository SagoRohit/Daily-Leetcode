select sender_id, count(message_id) as message_count
from messages
where extract(month from sent_date) = 8 and extract(year from sent_date)=2022
group by sender_id
order by message_count desc limit 2
-- select * from messages



select sender_id, count(message_id) as message_count
from messages
where sent_date between '08-01-22' and '08-21-22'
group by sender_id
order by message_count desc limit 2