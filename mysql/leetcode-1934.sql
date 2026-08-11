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