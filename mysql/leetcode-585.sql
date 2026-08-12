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