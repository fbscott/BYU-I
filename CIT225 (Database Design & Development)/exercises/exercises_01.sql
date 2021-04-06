DROP TABLE IF EXISTS favorite_food;
DROP TABLE IF EXISTS person;

CREATE TABLE person (
    person_id SMALLINT UNSIGNED,
    fname VARCHAR(20),
    lname VARCHAR(20),
    eye_color ENUM('BR', 'BL', 'GR', 'HZ'),
    birth_date DATE,
    street VARCHAR(20),
    city VARCHAR(20),
    state VARCHAR(20),
    country VARCHAR(20),
    postal_code VARCHAR(20),
    CONSTRAINT pk_person
        PRIMARY KEY (person_id)
);

CREATE TABLE favorite_food (
    person_id SMALLINT UNSIGNED,
    food VARCHAR(20),
    CONSTRAINT pk_favorite_food
        PRIMARY KEY (person_id, food), # two primary keys
    CONSTRAINT fk_fav_food_person_id # person_id MUST exist in person table
        FOREIGN KEY (person_id)
            REFERENCES person (person_id)
);

SET foreign_key_checks = 0; # may need to disable the fk checks
                            # before altering the person table
ALTER TABLE person MODIFY person_id SMALLINT UNSIGNED AUTO_INCREMENT;
SET foreign_key_checks = 1; # re-enable fk checks

INSERT INTO person (person_id, fname, lname, eye_color, birth_date)
    VALUES (null, 'William', 'Turner', 'BR', '1972-05-27');

INSERT INTO favorite_food (person_id, food)
    VALUES(1, 'pizza');
INSERT INTO favorite_food (person_id, food)
    VALUES(1, 'cookies');
INSERT INTO favorite_food (person_id, food)
    VALUES(1, 'nachos');

SELECT food FROM favorite_food WHERE person_id = 1 ORDER BY food;

UPDATE person SET street = '1225 Tremont St.',
    city = 'Boston',
    state = 'MA',
    country = 'USA',
    postal_code = '02138'
    WHERE person_id = 1;

INSERT INTO person (person_id, fname, lname, eye_color, birth_date, street, city, state, country, postal_code)
    VALUES(null, 'Susan', 'Smith', 'BL', '1975-11-02', '23 Maple St.', 'Arlington', 'VA', 'USA', '20220');

DELETE FROM person WHERE person_id = 2;
