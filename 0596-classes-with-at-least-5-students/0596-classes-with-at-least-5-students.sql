# Write your MySQL query statement below
select class 
from (select class , count(student) as hy
from Courses
group by class)x
where hy>=5;