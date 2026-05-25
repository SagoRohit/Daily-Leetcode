DELETE p1 
from person p1 left join 
person p2 on p1.email = p2.email
where p1.id > p2.id 