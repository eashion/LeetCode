# Write your MySQL query statement below
Select dep.Name as Department, emp.Name as Employee, emp.Salary
from Department dep, Employee emp
where emp.DepartmentId=dep.Id
and emp.Salary=(Select max(Salary) from Employee emp2 where emp2.DepartmentId=dep.Id)
