# Write your MySQL query statement below

SELECT sg.user_id, round(avg(if(c.action="confirmed",1,0)),2) AS confirmation_rate
FROM signups sg
LEFT JOIN confirmations c ON sg.user_id= c.user_id
GROUP BY user_id