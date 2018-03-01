#下次写不出来sql不许看答案
# Write your MySQL query statement below
select Score, (select count(distinct Score) from Scores s where s.Score>=t.Score) Rank
from Scores t
order by Score desc
