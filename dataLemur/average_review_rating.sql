select extract(month from submit_date) as mth, 
product_id, round(avg(stars),2) as avg_stars
from reviews
GROUP by product_id, extract(month from submit_date)
order by mth asc