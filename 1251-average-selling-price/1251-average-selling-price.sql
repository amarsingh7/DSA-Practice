# Write your MySQL query statement below

SELECT P.product_id, 
       IFNULL(ROUND(SUM(P.price * us.units)/SUM(us.units), 2), 0) AS average_price

FROM prices P
LEFT JOIN UnitsSold us 
       ON p.product_id= us.product_id 
       AND us.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY product_id