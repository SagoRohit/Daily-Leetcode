# Write your MySQL query statement below
select 'Low Salary' as category, count(*) as accounts_count
from accounts
where income < 20000
union ALL

select 'Average Salary' as category, count(*)
from accounts
where income BETWEEN 20000 and 50000
UNION ALL

select 'High Salary' as category, count(*)
from accounts
where income > 50000