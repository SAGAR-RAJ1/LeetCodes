# Write your MySQL query statement below
select product_id , new_price as price 
from Products p
where p.change_date = (
    select max(change_date) from Products
    where change_date<="2019-08-16" and p.product_id=product_id
)
union
SELECT product_id, 10 AS price
FROM Products p
GROUP BY product_id
HAVING MIN(change_date) > '2019-08-16';