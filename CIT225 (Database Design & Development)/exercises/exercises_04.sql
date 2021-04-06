# three-table join
SELECT c.first_name, c.last_name, ct.city
FROM customer c
    INNER JOIN address a
    ON c.address_id = a.address_id
    INNER JOIN city ct
    ON a.city_id = ct.city_id;

# same query as above but using the USING keyword
SELECT c.first_name, c.last_name, ct.city
FROM customer c
    INNER JOIN address a
    USING (address_id)
    INNER JOIN city ct
    USING (city_id);

# exercise 5-1
SELECT c.first_name, c.last_name, a.address, ct.city
FROM customer c
    INNER JOIN address a
    ON c.address_id = a.address_id
    INNER JOIN city ct
    on a.city_id = ct.city_id
WHERE a.district = 'California';

# exercise 5-2
SELECT f.title
FROM film f
    INNER JOIN film_actor fa
    ON f.film_id = fa.film_id
    INNER JOIN actor a
    ON a.actor_id = fa.actor_id
WHERE a.first_name = 'JOHN';

# exercise 5-3
SELECT a1.address addr1, a2.address addr2, a1.city_id
FROM address a1
    INNER JOIN address a2
WHERE a1.city_id = a2.city_id
    AND a1.address_id <> a2.address_id;
