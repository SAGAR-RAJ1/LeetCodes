# Write your MySQL query statement below
select name from(
select e1.name,count(*) as c
from Employee e1
join Employee e2
on e1.id=e2.managerId
group by e1.id,e1.name)x
where c>=5