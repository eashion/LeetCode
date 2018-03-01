# Write your MySQL query statement below
select Id
from Weather w
where Temperature > (select Temperature from Weather where DATEDIFF(Date,w.Date)=-1)
