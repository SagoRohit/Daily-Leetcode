select w1.id
from weather w1, weather w2
where DATEDIFF(w1.recorddate, w2.recorddate)=1 and 
w1.temperature > w2.temperature

-- comma seperated makes the table become join.
-- and the both table will be cross joined to each other.
-- and then datediff will delete w2 from w1. thus w1 temp
-- should be greater than w2. Means, next day temp is greater
-- than the previous day temp.