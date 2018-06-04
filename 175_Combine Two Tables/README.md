left join according to left table, all of left table's contents will show, right join according to right table. inner join according to the 
condition. Only show contents satisfy the condition. https://www.cnblogs.com/pcjim/articles/799302.html
```
# Write your MySQL query statement below
select firstName, LastName, City, State
from Person as a left join Address as b
on a.PersonId = b.PersonId
```
