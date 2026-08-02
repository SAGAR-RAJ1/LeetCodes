# Write your MySQL query statement below
select Department ,  Employee , salary
from(
    select Department.name as Department , Employee.name as Employee , salary ,
    rank() over(partition by departmentId order by salary desc) as rnk
    from Employee
    join Department
    on Employee.departmentId=Department.id
)tableNameAlias
 where rnk=1;