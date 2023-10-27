# Write your MySQL query statement below

SELECT em.name
FROM Employee e
INNER JOIN Employee as em ON e.managerid= em.id
GROUP BY e.managerid
HAVING COUNT(e.id)>=5
