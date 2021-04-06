/******************************************************************************
 * create - add ticket (pres, vp, party, and slogan)
 *****************************************************************************/
INSERT INTO ticket (pres_id, vice_pres_id, party_id, slogan)
VALUES (1, 1, 1, NULL)
    , (2, 2, 2, NULL)
    , (3, 3, 3, NULL)
    , (4, 5, 3, NULL)
    , (5, 6, 3, NULL)
    , (6, 7, 3, NULL)
    , (7, 8, 4, NULL)
    , (8, 9, 4, 'Independent Treasury and Liberty')
    , (9, 10, 5, 'Tippecanoe and Tyler Too')
    , (10, NULL, 5, NULL)
    , (11, 11, 4, '54-40 or fight')
    , (12, 12, 5, 'For President of the People')
    , (13, NULL, 5, NULL)
    , (14, 13, 4, 'We Polked you in \'44, We shall Pierce you in \'52')
    , (15, 14, 4, 'We\'ll Buck \'em in \'56')
    , (16, 15, 6, 'Vote yourself a farm and horses')
    , (17, NULL, 8, NULL)
    , (18, 18, 6, 'Let Us Have Peace')
    , (19, 19, 6, 'Hayes the true and Wheeler too')
    , (20, 20, 6, NULL)
    , (21, NULL, 6, NULL)
    , (22, 21, 4, 'Burn this letter!')
    , (23, 22, 6, 'Tippecanoe and Morton too')
    , (22, 23, 4, 'Our choice: Cleve and Steve')
    , (24, 24, 6, 'Patriotism, Protection, and Prosperity')
    , (25, 26, 6, 'To Assure Continued Prosperity')
    , (26, 27, 6, 'A Square Deal For All')
    , (27, 28, 4, 'Win with Wilson')
    , (28, 29, 6, 'Return to normalcy')
    , (29, 30, 6, 'Keep Cool and Keep Coolidge')
    , (30, 31, 6, 'Who but Hoover?')
    , (31, 32, 4, 'Happy Days Are Here Again')
    , (32, 35, 4, 'The Buck Stops Here')
    , (33, 36, 6, 'I like Ike')
    , (34, 37, 4, 'A time for greatness 1960')
    , (35, 38, 4, 'All the way with LBJ')
    , (36, 39, 6, 'This time, vote like your whole world depended on it')
    , (37, 41, 6, 'He\'s making us proud again')
    , (38, 42, 4, 'Not Just Peanuts')
    , (39, 43, 6, 'Are You Better Off Than You Were Four Years Ago?')
    , (40, 44, 6, 'Kinder, Gentler Nation')
    , (41, 45, 4, 'For People, for a Change')
    , (42, 46, 6, 'Compassionate Conservatism')
    , (43, 47, 4, 'Change')
    , (44, 48, 6, 'Make America Great Again!')
    , (45, 49, 4, 'Build back better');

/******************************************************************************
 * read - select Abraham Lincoln's ticket
 *****************************************************************************/
SELECT CONCAT(p.first, ' ', IF(ISNULL(p.middle), '', CONCAT(p.middle, ' ')), p.last) president
     , CONCAT(vp.first, ' ', IF(ISNULL(vp.middle), '', CONCAT(vp.middle, ' ')), vp.last) vice_president
     , pty.name party
     , t.slogan slogan
FROM ticket t
LEFT JOIN pres p
ON p.pres_id = t.pres_id
LEFT JOIN party pty
ON pty.party_id = t.party_id
LEFT JOIN vice_pres vp
ON vp.vice_pres_id = t.vice_pres_id
WHERE p.pres_id = 16;

SELECT CONCAT(p.first, ' ', IF(ISNULL(p.middle), '', CONCAT(p.middle, ' ')), p.last) president
FROM ticket t
INNER JOIN pres p
ON p.pres_id = t.pres_id
INNER JOIN party pty
ON pty.party_id = t.party_id
WHERE pty.name = 'Republican';

/******************************************************************************
 * update
 *****************************************************************************/


/******************************************************************************
 * delete
 *****************************************************************************/

