select round(sum(tiv_2016),2) as tiv_2016
from insurance
where (lat,lon) in 
    (
        select lat, lon
        from insurance
        GROUP BY lat, lon
        having count(*)=1
    )
AND
tiv_2015 in 
    (
        select tiv_2015
        from insurance
        GROUP BY tiv_2015
        having count(*)>1
    )


 # Write your MySQL query statement below
select round(sum(i.tiv_2016),2) as tiv_2016
from insurance i
where exists (select i2.pid 
                from insurance i2 
                where i.tiv_2015 = i2.tiv_2015 and
                i.pid != i2.pid)
and (i.lat, i.lon) not in
( select i2.lat, i2.lon
from insurance i2
where i.pid != i2.pid
)