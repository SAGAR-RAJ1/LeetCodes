with temp as (
    select * , id - row_number() over(order by id) as rw
    from stadium
    where people>=100
)
select id,visit_date,people from temp
where rw IN (
    select rw from temp 
    group by rw
    having count(*)>=3
)
order by visit_date