select DISTINCT l1.num as ConsecutiveNums 
from logs l1, logs l2, logs l3
where l1.num = l2.num and l2.num = l3.num
and l1.id = l2.id-1 and l2.id = l3.id-1

#another solution using window function
with temp as (
    select num,
    lead(num) over(ORDER BY id) as next_num,
    lead(num, 2) over(order by id) as next_next_num
    from logs
)
select DISTINCT num as ConsecutiveNums
from temp
where num = next_num and num = next_next_num