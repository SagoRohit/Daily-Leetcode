with base as (
    select d.name as department,
    e.name as employee,
    e.salary as salary,
    dense_rank() over(PARTITION BY d.name
    ORDER BY e.salary DESC) as ranking

    from employee e inner join department d on
    e.departmentid = d.id
)

select department, employee, salary
from base
where ranking in (1,2,3)