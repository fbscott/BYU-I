/******************************************************************************
 * create - add vice presidents
 *****************************************************************************/
INSERT INTO vice_pres (first, middle, last)
VALUES ('John', NULL, 'Adams')
    , ('Thomas', NULL, 'Jefferson')
    , ('Aaron', NULL, 'Burr')
    , ('George', NULL, 'Clinton')
    , ('Elbridge', NULL, 'Gerry')
    , ('Daniel', 'D.', 'Tompkins')
    , ('John', 'C.', 'Calhoun')
    , ('Martin', NULL, 'Van Buren')
    , ('Richard', 'M.', 'Johnson')
    , ('John', NULL, 'Tyler')
    , ('George', 'M.', 'Dallas')
    , ('Millard', NULL, 'Fillmore')
    , ('William', 'R.', 'King')
    , ('John', 'C.', 'Breckinridge')
    , ('Hannibal', NULL, 'Hamlin')
    , ('Andrew', NULL, 'Johnson')
    , ('Schuyler', NULL, 'Colfax')
    , ('Henry', NULL, 'Wilson')
    , ('William', 'A.', 'Wheeler')
    , ('Chester', 'A.', 'Arthur')
    , ('Thomas', 'A.', 'Hendricks')
    , ('Levi', 'P.', 'Morton')
    , ('Adlai', 'E.', 'Stevenson')
    , ('Garret', 'A.', 'Hobart')
    , ('Theodore', NULL, 'Roosevelt')
    , ('Charles', 'W.', 'Fairbanks')
    , ('James', 'S.', 'Sherman')
    , ('Thomas', 'R.', 'Marshall')
    , ('Calvin', NULL, 'Coolidge')
    , ('Charles', 'G.', 'Dawes')
    , ('Charles', NULL, 'Curtis')
    , ('John', 'N.', 'Garner')
    , ('Henry', 'A.', 'Wallace')
    , ('Harry', 'S.', 'Truman')
    , ('Alben', 'W.', 'Barkley')
    , ('Richard', 'M.', 'Nixon')
    , ('Lyndon', 'B.', 'Johnson')
    , ('Hubert', 'H.', 'Humphrey')
    , ('Spiro', 'T.', 'Agnew')
    , ('Gerald', 'R.', 'Ford')
    , ('Nelson', NULL, 'Rockefeller')
    , ('Walter', 'F.', 'Mondale')
    , ('George', 'H W', 'Bush')
    , ('Dan', NULL, 'Quayle')
    , ('Albert', NULL, 'Gore')
    , ('Richard', NULL, 'Cheney')
    , ('Joseph', 'R.', 'Biden')
    , ('Mike', NULL, 'Pence')
    , ('Kamala', NULL, 'Harris');

/******************************************************************************
 * read
 *****************************************************************************/
SELECT CONCAT(vp.first, ' ', IF(ISNULL(vp.middle), '', CONCAT(vp.middle, ' ')), vp.last) vice_president
FROM vice_pres vp;

/******************************************************************************
 * update - remove punctuation from middle initials
 *****************************************************************************/
START TRANSACTION;

UPDATE vice_pres
SET middle = REPLACE(middle, '.', NULL)
WHERE middle LIKE '%.';

COMMIT;

/******************************************************************************
 * delete
 *****************************************************************************/

