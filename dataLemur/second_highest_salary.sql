select salary as second_highest_salary
from (
  select salary,
  rank() over(order by salary desc) as rnk
  from employee) t 
where rnk = 2