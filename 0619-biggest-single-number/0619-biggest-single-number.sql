# Write your MySQL query statement below
select max(num) as num from (
select num , count(num) as c
from MyNumbers
group by num
order by num desc
) x
where c=1

