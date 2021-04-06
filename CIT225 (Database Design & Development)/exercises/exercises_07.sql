# Exercise 1
SELECT COUNT(*) AS 'rows' FROM payment;

# Exercise 2
SELECT customer_id, COUNT(payment_id) AS 'Payments', SUM(amount) AS 'Total Paid'
FROM payment
GROUP BY customer_id;

# Exercise 3
SELECT customer_id, COUNT(payment_id) AS 'Payments', SUM(amount) AS 'Total Paid'
FROM payment
GROUP BY customer_id
HAVING COUNT(payment_id) >= 40;

# Exercise 4
SELECT customer_id, count(*) rental_count
FROM rental GROUP BY customer_id
HAVING count(*) > 40;

# Exercise 5
SELECT fa.actor_id,
CONCAT(a.first_name, ' ', a.last_name) actor_name,
f.rating rating,
COUNT(*) film_count,
AVG(f.length) avg_length,
AVG(f.replacement_cost) avg_replacement_cost
FROM film_actor AS fa
    INNER JOIN film AS f
    on fa.film_id = f.film_id
    INNER JOIN actor AS a
    on a.actor_id = fa.actor_id
WHERE a.last_name IN ('DEPP') AND rating != 'NC-17'
GROUP BY fa.actor_id, f.rating
ORDER BY actor_name, rating;




# Paper Query 1 (ORDER BY runs after WHERE. Need to use HAVING)
SELECT customer_id, count(rental_id) AS rental_count
FROM rental
GROUP BY customer_id
HAVING count(rental_id) > 40;

# Paper Query 2 (Add GROUP BY district)
SELECT district, COUNT(*) AS city_count
FROM address
GROUP BY district;
