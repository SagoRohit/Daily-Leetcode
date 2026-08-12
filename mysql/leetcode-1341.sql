# Write your MySQL query statement below
(select u.name as results
from users u INNER join movieRating mr
on u.user_id = mr.user_id
GROUP BY u.user_id, u.name
order by count(mr.movie_id) DESC, u.name
limit 1
)
union ALL
(
select m.title as results
from movies m inner join movierating mr
on m.movie_id = mr.movie_id
where mr.created_at between '2020-02-01' and '2020-02-29'
group by m.movie_id, m.title
order by avg(mr.rating) desc, m.title 
limit 1)