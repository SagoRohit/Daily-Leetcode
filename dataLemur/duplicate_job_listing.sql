select count(distinct j1.company_id) as duplicate_companies
from job_listings j1 cross join job_listings j2
where j1.job_id != j2.job_id and j1.company_id = j2.company_id
and j1.title = j2.title and j1.description = j2.description 