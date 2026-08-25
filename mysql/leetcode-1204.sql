select q1.person_name
from queue q1 join queue q2 ON
q1.turn >= q2.turn
group by q1.turn
having sum(q2.weight) <= 1000
order by sum(q2.weight) desc
limit 1

# 2nd approach using window function over() and cte
with base as (
    select person_id, person_name,
    sum(weight) over(order by turn asc) as weight
    from queue
)
select person_name
from base
where weight <=1000
order by weight desc limit 1