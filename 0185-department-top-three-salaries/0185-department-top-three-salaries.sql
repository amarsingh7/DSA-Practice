# Write your MySQL query statement below

SELECT d.name as department, e1.name as employee, e1.salary as Salary
FROM Employee e1 
JOIN Department d on e1.DepartmentId = d.Id
WHERE 3 > (SELECT COUNT(DISTINCT (e2.Salary))
           FROM Employee e2
           WHERE e2.Salary > e1.Salary
                 AND e1.DepartmentId = e2.DepartmentId)