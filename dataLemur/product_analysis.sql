with base as (select e.employee_id, COALESCE(count(DISTINCT q.query_id),0) as unique_queries
from employees e left join queries q on 
e.employee_id = q.employee_id
and q.query_starttime >= '2023-07-01T00:00:00Z'
AND q.query_starttime < '2023-10-01T00:00:00Z'
group by e.employee_id)

select unique_queries,
count(employee_id) as employee_count
from base 
group by unique_queries
order by unique_queries