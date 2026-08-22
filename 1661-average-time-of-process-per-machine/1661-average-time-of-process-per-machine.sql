# Write your MySQL query statement below
select machine_id , round(avg(b),3) as processing_time
from(SELECT a.machine_id ,(b.timestamp - a.timestamp)as b
FROM Activity a
JOIN Activity b
ON a.machine_id = b.machine_id
AND a.process_id = b.process_id
AND a.activity_type = 'start'
AND b.activity_type = 'end')x
group by machine_id