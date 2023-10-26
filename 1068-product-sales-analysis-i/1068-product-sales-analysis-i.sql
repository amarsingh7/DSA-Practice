# Write your MySQL query statement below

SELECT product_name, Sales.year, Sales.price
FROM Product
RIGHT JOIN Sales ON Sales.product_id= Product.product_id