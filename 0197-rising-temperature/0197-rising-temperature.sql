# Write your MySQL query statement below

SELECT DISTINCT current.Id
FROM Weather current, Weather previous
WHERE current.Temperature > previous.Temperature 
      AND DATEDIFF(current.Recorddate, previous.Recorddate)=1
