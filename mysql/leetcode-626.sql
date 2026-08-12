SELECT
    case 
        when id%2=1 and id+1 in (select id from seat) then id + 1
        when id%2=0 then id-1
        else id
    end as id, student
from seat
order by id

# approach 2 : using window function

select id,
    CASE 
        WHEN id%2=0 THEN lag(student) over(ORDER BY id) 
        ELSE coalesce(lead(student) over(ORDER BY id), student)
    END as student
from seat