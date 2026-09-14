select round(
count(case_id)*100.0/
(select count(*) from callers)
,1) as uncategorised_call_pct
from callers
where call_category like 'n/a' or 
call_category is NULL

