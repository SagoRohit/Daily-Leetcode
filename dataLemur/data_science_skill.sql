with base as (
SELECT candidate_id, skill
from candidates 
where skill in ('Python', 'Tableau', 'PostgreSQL')
)
select candidate_id
from base 
group by candidate_id
having count(skill)=3

-- SELECT candidate_id, skill
-- from candidates 
-- where skill in ('Python', 'Tableau', 'PostgreSQL')