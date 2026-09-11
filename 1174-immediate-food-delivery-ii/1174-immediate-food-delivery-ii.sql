# Write your MySQL query statement below
select round(avg(immediate='Y')*100,2) as immediate_percentage from(
select * ,
(case
 when datediff(order_date,customer_pref_delivery_date)=0 then 'Y'
 else 'N'
 end)as immediate,
rank() over(partition by customer_id order by order_date) as r
from Delivery)x
where r=1