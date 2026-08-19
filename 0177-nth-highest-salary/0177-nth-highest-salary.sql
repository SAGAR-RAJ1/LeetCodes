CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
--    set N = N-1;
  RETURN (
      # Write your MySQL query statement below.
    --   select distinct salary from Employee
    --   order by salary desc
    --   limit 1 offset N
   
    select salary from(
    select * , dense_rank() over(order by salary desc) as dn 
    from employee
    ) x
    where x.dn = N
    limit 1
  );
END