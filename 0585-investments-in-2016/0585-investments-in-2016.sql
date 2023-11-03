# Write your MySQL query statement below

SELECT round(sum(TIV_2016),2) AS TIV_2016
FROM insurance i
WHERE (SELECT count(*) 
       FROM insurance i1 
       WHERE i.TIV_2015 = i1.TIV_2015)>1 
       AND
      (SELECT count(*) 
       FROM insurance i2 
       WHERE (i.LAT, i.LON) = (i2.LAT, i2.LON))=1