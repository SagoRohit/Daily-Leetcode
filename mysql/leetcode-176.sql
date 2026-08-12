select (select distinct salary 
from employee
ORDER BY salary desc
limit 1,1) as SecondHighestSalary



#2nd approach using max() function
select max(salary) as SecondHighestSalary
from employee
where salary < (select max(salary)
                from employee)


#3rd approach (best solution for n-th rank)
select(
    select DISTINCT salary
    from (
        select salary,
        dense_rank() over(ORDER BY salary desc) as rnk
        from employee
    ) as ranksalary
    where rnk = 2
) as SecondHighestSalary