DELETE FROM string_tbl;

INSERT INTO string_tbl(vchar_fld)
VALUES('abc'),
      ('xyz'),
      ('QRSTUV'),
      ('qrstuv'),
      (12345);

# Exercise 1
SELECT SUBSTRING('Please find the substring in this string', 17, 9);

# Exercise 2
SELECT ABS(-25.76823) abs, SIGN(-25.76823) sign, ROUND(-25.76823, 2) round;

# Exercise 3
SELECT EXTRACT(MONTH FROM CURRENT_DATE()) month;

# Exercise 4
INSERT INTO actor(first_name, last_name)
VALUES('Maureen', 'O\'Hara');

# Exercise 5
SELECT first_name, last_name
FROM actor
WHERE first_name = 'MARK' AND last_name = 'WAHLBERG, II';

UPDATE actor 
SET first_name = 'MARK', last_name = CONCAT(last_name, ', II')
WHERE first_name = 'NICK' and last_name = 'WAHLBERG';

# Exercise 6
SELECT DAYNAME(LAST_DAY('2030-07-04')) day_of_the_week;
