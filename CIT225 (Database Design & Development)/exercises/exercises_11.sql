/***************************************** exercise 11-1 *****************************************/
DROP TABLE IF EXISTS studentdb.account;
DROP TABLE IF EXISTS studentdb.transaction;

CREATE TABLE studentdb.account (
    account_id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    avail_balance double NOT NULL,
    last_activity_date datetime NOT NULL
);

CREATE TABLE studentdb.transaction (
    txn_id INT(10) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    txn_date datetime,
    account_id INT UNSIGNED,
    txn_type_cd VARCHAR(1) NOT NULL,
    amount double
);

INSERT INTO account
    (account_id, avail_balance, last_activity_date)
VALUES
    (123, 500, now());

INSERT INTO account
    (account_id, avail_balance, last_activity_date)
VALUES
    (789, 75, now());

INSERT INTO transaction
    (txn_id, txn_date, account_id, txn_type_cd, amount)
VALUES
    (1003, now(), 123, 'D', 50);

INSERT INTO transaction
    (txn_date, account_id, txn_type_cd, amount)
VALUES
    (now(), 789, 'C', 50);

START TRANSACTION;

UPDATE account
SET avail_balance = avail_balance - 50,
    last_activity_date = now()
WHERE account_id = 123;

INSERT INTO transaction
    (txn_date, account_id, txn_type_cd, amount)
VALUES
    (now(), 123, 'D', 50);

UPDATE account
SET avail_balance = avail_balance + 50,
    last_activity_date = now()
WHERE account_id = 789;

INSERT INTO transaction
    (txn_date, account_id, txn_type_cd, amount)
VALUES
    (now(), 789, 'C', 50);

COMMIT;

/***************************************** exercise 11-2 *****************************************/
START TRANSACTION;

INSERT INTO rental
    (rental_date, inventory_id, customer_id, return_date, staff_id)
VALUES
    (now(), 100, 10, NULL, 1);
# verify: SELECT * FROM rental ORDER BY rental_id DESC limit 1;

INSERT INTO payment
    (customer_id, staff_id, rental_id, amount, payment_date)
VALUES
    (10, 1, LAST_INSERT_ID(), 15, now());
# verify: SELECT * FROM payment ORDER BY payment_id DESC limit 1;

COMMIT;

ROLLBACK; # won't affect inerts

/***************************************** exercise 11-3 *****************************************/
START TRANSACTION;

UPDATE customer SET active = 1 WHERE customer_id = 406;
# verify: SELECT * FROM customer WHERE customer_id = 406;

SAVEPOINT after_activate;

INSERT INTO rental
    (rental_date, inventory_id, customer_id, return_date, staff_id)
VALUES
    (now(), 101, 406, NULL, 1);
# verify: SELECT * FROM rental ORDER BY rental_id DESC limit 1;

INSERT INTO payment
    (customer_id, staff_id, rental_id, amount, payment_date)
VALUES
    (406, 1, LAST_INSERT_ID(), 5, now());
# verify: SELECT * FROM payment ORDER BY payment_id DESC limit 1;

ROLLBACK TO SAVEPOINT after_activate;

COMMIT;

/***************************************** exercise 11-4 *****************************************/
SELECT DISTINCT f.rating,
    CASE f.rating
        WHEN 'PG' THEN 'Parental Guidance'
        WHEN 'G' THEN 'General Audience'
        WHEN 'NC-17' THEN 'Restricted - 17'
        WHEN 'PG-13' THEN 'Parental Guidance - 13'
        WHEN 'R' THEN 'Restricted'
    END rating_description
FROM film f;

/***************************************** exercise 11-5 *****************************************/
SELECT f.title, f.replacement_cost,
    CASE
        WHEN f.replacement_cost <= 10
            THEN 'STANDARD_MOVIE'
        WHEN f.replacement_cost > 10
            THEN 'NEW_RELEASE'
    END rental_type
FROM film f
WHERE f.length > 180;
