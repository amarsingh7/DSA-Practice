# Write your MySQL query statement below

SELECT IF(COUNT(*)=1, num, null) AS num
FROM MyNumbers
GROUP BY num
ORDER BY num DESC LIMIT 1