# Write your MySQL query statement below

SELECT empb.employee_id, empb.name, COUNT(empa.employee_id) as reports_count,          ROUND(AVG(empa.age)) AS average_age
FROM employees empa 
JOIN employees empb
     ON empa.reports_to = empb.employee_id
GROUP BY employee_id
ORDER BY employee_id