select name
from Customer c1
where c1.referee_id <> 2 or 
c1.referee_id is NULL
;