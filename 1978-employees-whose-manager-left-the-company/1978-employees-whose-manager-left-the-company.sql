SELECT e.employee_id
FROM Employees e
left join Employees m 
on m.employee_id = e.manager_id
where e.salary <30000
 AND e.manager_id IS NOT NULL
 AND m.employee_id is NULL
 order by e.employee_id
