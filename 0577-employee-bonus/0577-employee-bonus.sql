# Write your MySQL query statement below

SELECT name, b.bonus
FROM Employee
LEFT OUTER JOIN Bonus as b ON Employee.EmpID= b.EmpID 
WHERE ifnull(b.bonus, 0)<1000