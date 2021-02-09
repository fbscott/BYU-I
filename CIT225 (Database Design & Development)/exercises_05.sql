SELECT a.first_name, a.last_name
FROM actor a
WHERE a.last_name like 'L%'
UNION
SELECT c.first_name, c.last_name
FROM customer c
WHERE c.last_name like 'L%';

SELECT a.first_name fname, a.last_name lname
FROM actor a
WHERE a.last_name like 'L%'
UNION
SELECT c.first_name, c.last_name
FROM customer c
WHERE c.last_name like 'L%'
ORDER BY lname;
