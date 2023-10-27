# Write your MySQL query statement below

SELECT P.project_id, 
       ROUND(SUM(e.experience_years)/COUNT(P.employee_id), 2) AS average_years
FROM Project P
JOIN Employee e ON P.employee_id= e.employee_id
GROUP BY P.project_id 
ORDER BY P.project_id ASC
