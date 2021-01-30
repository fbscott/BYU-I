# Write the SQL statement that retrieves the actor ID, first name, and last name for all actors. Sort results by last name and then by first name.
SELECT actor_id, first_name, last_name FROM actor ORDER BY last_name, first_name;

# Write the SQL statement that retrieves the actor ID, first name, and last name for all actors whose last name equals 'WILLIAMS' or 'DAVIS'.
SELECT actor_id, first_name, last_name FROM actor WHERE (last_name = 'WILLIAMS') OR (last_name = 'DAVIS');
SELECT actor_id, first_name, last_name FROM actor WHERE last_name IN ('WILLIAMS', 'DAVIS');

# Write a query against the rental table that returns the IDs of the customers who rented a film on July 5, 2005 (use the rental.rental_date column, and you can use the date() function to ignore the time component). Include a single row for each distinct customer ID.
SELECT rental.rental_id FROM rental rental WHERE date(rental.rental_date) = '2005-07-05';

/**
Fill in the blanks (denoted by <#>) for this multi table query:

mysql> SELECT   c.email, r.return_date
    -> FROM     customer c INNER JOIN rental <1>
    -> ON       c.customer_id = <2>
    -> WHERE    date(r.rental_date) = '2005-06-14'
    -> ORDER BY <3> <4>;
    
To achieve the following results:

+---------------------------------------+---------------------+
| email                                 | return_date         |
+---------------------------------------+---------------------+
| AMBER.DIXON@sakilacustomer.org        | 2005-06-16 04:02:56 |
| CATHERINE.CAMPBELL@sakilacustomer.org | 2005-06-15 20:43:03 |
| CHARLES.KOWALSKI@sakilacustomer.org   | 2005-06-16 02:26:34 |
| DANIEL.CABRAL@sakilacustomer.org      | 2005-06-23 22:00:38 |
| ELMER.NOE@sakilacustomer.org          | 2005-06-17 02:11:13 |
| GWENDOLYN.MAY@sakilacustomer.org      | 2005-06-20 02:40:27 |
| HERMAN.DEVORE@sakilacustomer.org      | 2005-06-19 03:20:09 |
| JEANETTE.GREENE@sakilacustomer.org    | 2005-06-19 23:26:46 |
| JEFFERY.PINSON@sakilacustomer.org     | 2005-06-18 21:37:33 |
| JOYCE.EDWARDS@sakilacustomer.org      | 2005-06-16 21:00:26 |
| MATTHEW.MAHAN@sakilacustomer.org      | 2005-06-18 05:18:58 |
| MINNIE.ROMERO@sakilacustomer.org      | 2005-06-18 01:58:34 |
| MIRIAM.MCKINNEY@sakilacustomer.org    | 2005-06-21 17:12:08 |
| SONIA.GREGORY@sakilacustomer.org      | 2005-06-17 21:44:11 |
| TERRANCE.ROUSH@sakilacustomer.org     | 2005-06-23 21:53:46 |
| TERRENCE.GUNDERSON@sakilacustomer.org | 2005-06-17 05:28:35 |
+---------------------------------------+---------------------+
16 rows in set (0.21 sec)
 */
SELECT c.email, r.return_date
FROM customer c INNER JOIN rental r
ON c.customer_id = r.customer_id
WHERE date(r.rental_date) = '2005-06-14'
ORDER BY c.email, r.return_date;
