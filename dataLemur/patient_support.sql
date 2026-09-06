with base as (
select policy_holder_id
from callers
group by policy_holder_id
having count(case_id)>2)

select count(policy_holder_id) as policy_holder_count
from base