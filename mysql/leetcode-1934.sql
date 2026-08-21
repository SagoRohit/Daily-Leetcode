# Write your MySQL query statement below
select s.user_id,
round(AVG(
    CASE 
        WHEN c.action = 'confirmed' THEN 1.00 
        ELSE 0.00 
    END
),2) as confirmation_rate
from signups s left JOIN
confirmations c on
s.user_id = c.user_id
GROUP BY s.user_id 


select distinct s.user_id, 
coalesce(round((select count(*)
from confirmations c1
where s.user_id = c1.user_id and action = 'confirmed')/
(
    select count(*)
    from confirmations c2
    where s.user_id = c2.user_id
),2),0) as confirmation_rate
from signups s left join confirmations c on
s.user_id = c.user_id