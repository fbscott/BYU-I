# exercise 9-1
SELECT c.name, sum(p.amount)
FROM customer c
    LEFT OUTER JOIN payment p
    ON c.customer_id = p.customer_id
GROUP BY c.name;

# using sakila
SELECT CONCAT(c.first_name, ' ', c.last_name) name, SUM(p.amount)
FROM customer c
    LEFT OUTER JOIN payment p
    ON c.customer_id = p.customer_id
GROUP BY c.customer_id
LIMIT 10;

# exercise 9-2
SELECT c.name, sum(p.amount)
FROM payment p
    RIGHT OUTER JOIN customer c
    ON c.customer_id = p.customer_id
GROUP BY c.name;

# using sakila
SELECT CONCAT(c.first_name, ' ', c.last_name) name, SUM(p.amount)
FROM payment p
    RIGHT OUTER JOIN customer c
    ON c.customer_id = p.customer_id
GROUP BY c.customer_id
LIMIT 10;

# exercise 9-3
SELECT ones.num + tens.num + 1
    FROM (SELECT 0 num UNION ALL
          SELECT 1 num UNION ALL
          SELECT 2 num UNION ALL
          SELECT 3 num UNION ALL
          SELECT 4 num UNION ALL
          SELECT 5 num UNION ALL
          SELECT 6 num UNION ALL
          SELECT 7 num UNION ALL
          SELECT 8 num UNION ALL
          SELECT 9 num) ones
          CROSS JOIN
          (SELECT 0 num UNION ALL
          SELECT 10 num UNION ALL
          SELECT 20 num UNION ALL
          SELECT 30 num UNION ALL
          SELECT 40 num UNION ALL
          SELECT 50 num UNION ALL
          SELECT 60 num UNION ALL
          SELECT 70 num UNION ALL
          SELECT 80 num UNION ALL
          SELECT 90 num) tens;
