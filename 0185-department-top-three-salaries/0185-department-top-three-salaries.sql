# Write your MySQL query statement below
select Department,Employee,Salary from(
select d.name as Department , e.name as Employee , e.Salary,
dense_rank() over(partition by d.name order by e.salary desc) as dn
from employee e
join department d
on d.id = e.departmentID
)x
where x.dn<4;