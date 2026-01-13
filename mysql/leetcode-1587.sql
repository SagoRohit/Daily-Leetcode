select u.name, SUM(t.amount) as Balance
from users u left join transactions t on u.account= t.account
GROUP BY u.name
HAVING sum(t.amount) > 10000
