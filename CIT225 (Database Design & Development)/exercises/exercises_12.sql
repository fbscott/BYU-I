/***************************************** exercise 12-1 *****************************************/
/**
 * Generate an alter table statement for the rental table so that an error will
 * be raised if a row having a value found in the rental.customer_id column is
 * deleted from the customer table.
 */

ALTER TABLE rental
ADD CONSTRAINT fk_rental_customer_id FOREIGN KEY (customer_id)
REFERENCES customer (customer_id) ON DELETE RESTRICT;

/***************************************** exercise 12-2 *****************************************/
/**
 * Generate a multicolumn index on the payment table that could be used by both
 * of the following queries:
 */

CREATE INDEX idx_payment
ON payment (payment_date, amount);

/***************************************** exercise 12-3 *****************************************/
-- part 1
CREATE TABLE movie_review (
    movie_review_id SMALLINT UNSIGNED NOT NULL AUTO_INCREMENT,
    film_id SMALLINT UNSIGNED NOT NULL,
    review_text TEXT NOT NULL,
    create_date DATETIME NOT NULL,
    last_update TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        ON UPDATE CURRENT_TIMESTAMP,
    PRIMARY KEY (movie_review_id),
    KEY idx_fk_film_id (film_id),
    CONSTRAINT fk_movie_review_film FOREIGN KEY (film_id)
        REFERENCES film (film_id) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4;

-- part 2 (with challenge)
INSERT INTO movie_review (film_id, review_text, create_date)
VALUES ((SELECT film_id
        FROM film
        WHERE  title = 'brotherhood blanket')
        , 'This is a great movie!', now());

-- part 3
SELECT movie_review_id, film_id, review_text
FROM movie_review
WHERE film_id = 101;

SHOW INDEX FROM movie_review;

SELECT COLUMN_NAME, CONSTRAINT_NAME, REFERENCED_COLUMN_NAME, REFERENCED_TABLE_NAME
FROM information_schema.KEY_COLUMN_USAGE
WHERE TABLE_NAME = 'movie_review';


/***************************************** exercise 12-4 *****************************************/
-- part 1 (with challenge)
ALTER TABLE movie_review
ADD customer_id SMALLINT UNSIGNED NULL AFTER film_id,
ADD INDEX (customer_id),
ADD CONSTRAINT fk_movie_review_customer FOREIGN KEY (customer_id)
    REFERENCES customer (customer_id) ON DELETE restrict ON UPDATE CASCADE;

-- part 2 (with challenge)
INSERT INTO movie_review (film_id, customer_id, review_text, create_date)
VALUES ((SELECT film_id
    FROM film
    WHERE title = 'Bull Shawshank')
, (SELECT customer_id
    FROM customer
    WHERE first_name = 'nathan' AND last_name = 'runyon')
, 'This is not a great movie!'
, NOW());

-- part 3
SELECT movie_review_id, film_id, customer_id, review_text
FROM movie_review WHERE film_id = 105;

SHOW INDEX FROM movie_review;

SELECT COLUMN_NAME, CONSTRAINT_NAME, REFERENCED_COLUMN_NAME, REFERENCED_TABLE_NAME
FROM information_schema.KEY_COLUMN_USAGE
WHERE TABLE_NAME = 'movie_review';

DELETE FROM customer WHERE customer_id = 406;

/***************************************** exercise 12-5 *****************************************/
-- part 1
CREATE TABLE movie_rating(
    movie_rating_id SMALLINT UNSIGNED NOT NULL AUTO_INCREMENT,
    rating_description VARCHAR(20) NOT NULL,
    create_date DATETIME NOT NULL,
    last_update TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        ON UPDATE CURRENT_TIMESTAMP,
    PRIMARY KEY (movie_rating_id)
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4;

-- part 2
INSERT INTO movie_rating (rating_description, create_date)
VALUES ('Rotten', NOW())
    , ('Fresh', NOW())
    , ('Excellent', NOW());

-- part 3 (with challenge)
ALTER TABLE movie_review
ADD movie_rating_id SMALLINT UNSIGNED AFTER customer_id,
ADD INDEX (movie_rating_id),
ADD CONSTRAINT fk_movie_review_movie_rating FOREIGN KEY (movie_rating_id)
    REFERENCES movie_rating (movie_rating_id) ON DELETE SET NULL ON UPDATE CASCADE;

-- part 4
UPDATE movie_review
SET movie_rating_id = 2
WHERE movie_review_id = 1;

UPDATE movie_review
SET movie_rating_id = 1
WHERE movie_review_id = 2;

-- part 5
INSERT INTO movie_review (film_id
    , customer_id
    , movie_rating_id
    , review_text
    , create_date)
VALUES (200, 500, 3, 'This is an Excellent Movie', now());

-- part 6
DELETE FROM movie_rating
WHERE movie_rating_id = 3;

-- part 7
SELECT movie_review_id, film_id, customer_id, movie_rating_id, review_text
FROM movie_review;

SELECT movie_rating_id, rating_description
FROM movie_rating;

SHOW INDEX FROM movie_rating;

SHOW INDEX FROM movie_review;

SELECT COLUMN_NAME, CONSTRAINT_NAME, REFERENCED_COLUMN_NAME, REFERENCED_TABLE_NAME
FROM information_schema.KEY_COLUMN_USAGE
WHERE TABLE_NAME = 'movie_review';
