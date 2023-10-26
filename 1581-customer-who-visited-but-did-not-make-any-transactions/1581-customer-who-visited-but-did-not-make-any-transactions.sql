# Write your MySQL query statement below

SELECT customer_id, COUNT(visits.visit_id) as count_no_trans 
FROM Visits
LEFT JOIN Transactions ON visits.visit_id = transactions.visit_id
WHERE transaction_id IS NULL
GROUP BY customer_id