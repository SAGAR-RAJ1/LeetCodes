# Write your MySQL query statement below
Select id , movie, description , rating
from Cinema
where 
description <> "boring"
and
id%2!=0
order by rating desc