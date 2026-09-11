# Write your MySQL query statement below
select person_name from
(select * , 
sum(weight) over(order by turn) as sw
from Queue
)x
where sw<=1000
order by sw desc
limit 1