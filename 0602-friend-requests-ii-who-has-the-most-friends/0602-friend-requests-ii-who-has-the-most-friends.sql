# Write your MySQL query statement below

WITH cte AS (SELECT requester_id id FROM RequestAccepted
UNION ALL
SELECT accepter_id id FROM RequestAccepted)

SELECT id, COUNT(*) num  
FROM cte 
GROUP BY 1 
ORDER BY 2 DESC 
LIMIT 1