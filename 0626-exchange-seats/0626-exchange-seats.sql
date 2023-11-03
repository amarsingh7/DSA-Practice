# Write your MySQL query statement below

SELECT
    CASE WHEN id = (SELECT max(id) FROM seat) AND id% 2 != 0 then id
    WHEN id%2 != 0 then id+1
    WHEN id%2 = 0 then id-1 end as id,
    student
FROM seat
ORDER BY id ASC