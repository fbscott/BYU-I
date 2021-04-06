# searched case expression
SELECT first_name, last_name,
    CASE
        WHEN active = 1 THEN 'ACTIVE'
        ELSE 'INACTIVE' -- 'else' clause is optional
    END activity_type
FROM customer
ORDER BY 3
LIMIT 10;

SELECT c.first_name, c.last_name,
    CASE
        WHEN active = 0 THEN 0
        ELSE (SELECT count(*) FROM rental r
              WHERE r.customer_id = c.customer_id)
    END num_rentals
FROM customer c
LIMIT 10;

SELECT c.first_name, c.last_name,
    (SELECT count(*) FROM rental r
        WHERE r.customer_id = c.customer_id) num_rentals
FROM customer c
LIMIT 10;

SELECT c.first_name, c.last_name,
    sum(p.amount) tot_payment_amt,
    count(p.amount) num_payments,
    sum(p.amount) /
        # wrap denominators in conditional logic
        CASE WHEN count(p.amount) = 0 THEN 1
            ELSE count(p.amount)
        END avg_payment
FROM customer c
    LEFT OUTER JOIN payment p
    ON c.customer_id = p.customer_id
GROUP BY c.first_name, c.last_name;


/**
 * exercise 10-1
 * Rewrite the following query, which uses a simple case expression, so that
 * the same results are achieved using a searched case expression. Try to use
 * as few when clauses as possible.:
 * SELECT name,
 *   CASE name
 *     WHEN 'English' THEN 'latin1'
 *     WHEN 'Italian' THEN 'latin1'
 *     WHEN 'French' THEN 'latin1'
 *     WHEN 'German' THEN 'latin1'
 *     WHEN 'Japanese' THEN 'utf8'
 *     WHEN 'Mandarin' THEN 'utf8'
 *     ELSE 'Unknown'
 *   END character_set
 * FROM language;
 */
SELECT name,
    CASE
        WHEN name IN ('English', 'Italian', 'French', 'German')
            THEN 'latin1'
        WHEN name IN ('Japanese', 'Mandarin')
            THEN 'utf8'
        ELSE 'Unknown'
    END character_set
FROM language;

/**
 * exercise 10-2
 * Rewrite the following query so that the result set contains a single row
 * with five columns (one for each rating).:
 * SELECT rating, count(*)
 *   FROM film
 *   GROUP BY rating;
 */
SELECT
    SUM(CASE WHEN rating = 'G' THEN 1
        ELSE 0 END) G,
    SUM(CASE WHEN rating = 'PG' THEN 1
        ELSE 0 END) PG,
    SUM(CASE WHEN rating = 'PG-13' THEN 1
        ELSE 0 END) PG_13,
    SUM(CASE WHEN rating = 'R' THEN 1
        ELSE 0 END) R,
    SUM(CASE WHEN rating = 'NC-17' THEN 1
        ELSE 0 END) NC_17
FROM film;
