# Write your MySQL query statement below
select max(num) as num from 
(select num , count(num) as cnt
from MyNumbers
group by num
order by num desc)x
where cnt = 1 limit 1