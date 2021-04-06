SELECT customer_id, COUNT(rental_id), SUM(amount)
FROM payment
GROUP BY customer_id;

#1
SELECT title
FROM film
WHERE film_id IN
    (SELECT fc.film_id
    FROM film_category fc INNER JOIN category c
    ON fc.category_id = c.category_id
    WHERE c.name = 'Action');

#2
SELECT f.title
FROM film AS f
WHERE f.film_id IN
    (SELECT f.film_id
    FROM film_category fc INNER JOIN category c
    ON fc.category_id = c.category_id
    WHERE c.name = 'Action'
    AND fc.film_id = f.film_id);

#3
SELECT actr.actor_id, grps.level 
FROM
    (SELECT actor_id, count(*) AS num_movies
        FROM film_actor
        GROUP BY actor_id
    ) AS actr
    INNER JOIN
    (SELECT 'Hollywood Star' level, 30 min_roles, 99999 max_roles
        UNION ALL
        SELECT 'Prolific Actor' level, 20 min_roles, 29 max_roles
        UNION ALL
        SELECT 'Newcomer' level, 1 min_roles, 19 max_roles
    ) AS grps
    ON actr.num_movies BETWEEN grps.min_roles AND grps.max_roles;

#4
SELECT title
FROM film
WHERE film_id IN
    (SELECT film_actor.film_id
        FROM film_actor
        INNER JOIN actor
        ON film_actor.actor_id = actor.actor_id
        WHERE actor.first_name = 'SISSY');

#5
SELECT f1.film_id, title, rating, length
FROM film f1
WHERE length IN 
    (SELECT ROUND(AVG(length), 0)
    FROM film f2
    WHERE f1.rating = f2.rating);

#6
SELECT c.customer_id, CONCAT(first_name, ' ', last_name) cust_name, total_rentals, total_amt
FROM customer AS c
INNER JOIN
(SELECT customer_id, COUNT(rental_id) total_rentals, SUM(amount) AS total_amt
    FROM payment
    GROUP BY customer_id) AS count_totals
ON count_totals.customer_id = c.customer_id
WHERE total_amt >= 150 AND total_rentals > 40;





# for the paper
# non-correlated
SELECT f.title, f.rating, ft.description
FROM film f
    INNER JOIN film_actor fa
    ON f.film_id = fa.film_id
    INNER JOIN film_text ft
    ON f.film_id = ft.film_id
WHERE fa.actor_id =
    (SELECT actor_id FROM actor a
        WHERE a.first_name = 'JOHNNY'
        AND a.last_name = 'CAGE');

# correlated
SELECT f.title, f.rating, ft.description
FROM film f
    INNER JOIN film_actor fa
    ON f.film_id = fa.film_id
    INNER JOIN film_text ft
    ON f.film_id = ft.film_id
WHERE fa.actor_id =
    (SELECT fa.actor_id FROM actor a
        WHERE a.first_name = 'JOHNNY'
        AND a.last_name = 'CAGE'
        AND fa.actor_id = a.actor_id);
