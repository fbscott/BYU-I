/***************************************** exercise 13-1 *****************************************/
CREATE VIEW film_ctgry_actor AS
SELECT f.title
    , c.name category_name
    , a.first_name
    , a.last_name
FROM film f
    INNER JOIN film_category fc
    ON f.film_id = fc.film_id
    INNER JOIN category c
    ON fc.category_id = c.category_id
    INNER JOIN film_actor fa
    ON fa.film_id = f.film_id
    INNER JOIN actor a
    ON fa.actor_id = a.actor_id;

SELECT title, category_name, first_name, last_name
FROM film_ctgry_actor
WHERE last_name = 'FAWCETT';

/***************************************** exercise 13-2 *****************************************/
CREATE VIEW country_payments AS
SELECT c.country
    , (SELECT SUM(p.amount)
        FROM city ct
            INNER JOIN address a
            ON ct.city_id = a.city_id
            INNER JOIN customer cst
            ON a.address_id = cst.address_id
            INNER JOIN payment p
            ON cst.customer_id = p.customer_id
        WHERE ct.country_id = c.country_id
    ) tot_payments
FROM country c;
