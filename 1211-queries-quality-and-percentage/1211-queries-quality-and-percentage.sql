# Write your MySQL query statement below
select q.query_name , round(avg(rating/position),2) as quality ,
round(((select count(*) from Queries where rating <3 and query_name = q.query_name )*100)/count(*),2) as poor_query_percentage
from Queries q
group by query_name