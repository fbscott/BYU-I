/******************************************************************************
 * create - add presidents
 *****************************************************************************/
INSERT INTO pres (first, middle, last)
VALUES ('George', NULL, 'Washington')
    , ('John', NULL, 'Adams')
    , ('Thomas', NULL, 'Jefferson')
    , ('James', NULL, 'Madison')
    , ('James', NULL, 'Monroe')
    , ('John', 'Quincy', 'Adams')
    , ('Andrew', NULL, 'Jackson')
    , ('Martin', NULL, 'Van Buren')
    , ('William', 'Henry', 'Harrison')
    , ('John', NULL, 'Tyler')
    , ('James', 'K', 'Polk')
    , ('Zachary', NULL, 'Taylor')
    , ('Millard', NULL, 'Fillmore')
    , ('Franklin', NULL, 'Pierce')
    , ('James', NULL, 'Buchanan')
    , ('Abraham', NULL, 'Lincoln')
    , ('Andrew', NULL, 'Johnson')
    , ('Ulysses', 'S', 'Grant')
    , ('Rutherford', 'B', 'Hayes')
    , ('James', 'A', 'Garfield')
    , ('Chester', 'A', 'Arthur')
    , ('Grover', NULL, 'Cleveland')
    , ('Benjamin', NULL, 'Harrison')
    , ('William', NULL, 'McKinley')
    , ('Theodore', NULL, 'Roosevelt')
    , ('William', 'Howard', 'Taft')
    , ('Woodrow', NULL, 'Wilson')
    , ('Warren', 'G', 'Harding')
    , ('Calvin', NULL, 'Coolidge')
    , ('Herbert', NULL, 'Hoover')
    , ('Franklin', 'D', 'Roosevelt')
    , ('Harry', 'S', 'Truman')
    , ('Dwight', 'D', 'Eisenhower')
    , ('John', 'F', 'Kennedy')
    , ('Lyndon', 'B', 'Johnson')
    , ('Richard', NULL, 'Nixon')
    , ('Gerald', NULL, 'Ford')
    , ('Jimmy', NULL, 'Carter')
    , ('Ronald', NULL, 'Reagan')
    , ('George', 'H W', 'Bush')
    , ('William', NULL, 'Clinton')
    , ('George', 'W', 'Bush')
    , ('Barack', NULL, 'Obama')
    , ('Donald', NULL, 'Trump')
    , ('Joe', NULL, 'Biden');

/******************************************************************************
 * read
 *****************************************************************************/
SELECT CONCAT(p.first, ' ', IF(ISNULL(p.middle), '', CONCAT(p.middle, ' ')), p.last) president
FROM pres p;

/******************************************************************************
 * update
 *****************************************************************************/
UPDATE pres p
SET p.first = 'Homer'
    , p.middle = 'J'
    , p.last = 'Simpson'
WHERE p.first = 'Joe' AND p.last = 'Biden';

/******************************************************************************
 * delete
 *****************************************************************************/

