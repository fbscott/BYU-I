SELECT payment_id, customer_id, amount, date(payment_date)
FROM payment
WHERE payment_id
BETWEEN 101 AND 120 AND
customer_id <> 5 AND (amount > 8 OR date(payment_date) = '2005-08-23');

SELECT payment_id, customer_id, amount, date(payment_date)
FROM payment
WHERE payment_id
BETWEEN 101 AND 120 AND
customer_id = 5 AND NOT (amount > 6 OR date(payment_date) = '2005-06-19');

SELECT amount
FROM payment
WHERE amount IN (1.98, 7.98, 9.98);

SELECT first_name, last_name
FROM customer
WHERE last_name LIKE "_a%w%";
