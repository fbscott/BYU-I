/******************************************************************************
 * create
 *****************************************************************************/
INSERT INTO pres_details (pres_id
    , vice_pres_id
    , party_id
    , state_id
    , terms_served
    , reason_left_office_id
    , military_branch_id
    , first_lady_id
    , living)
VALUES (1, 1, 1, 46, 2, 1, 1, 1, false)
    , (2, 2, 2, 21, 1, 1, NULL, 2, false)
    , (3, 3, 3, 46, 2, 1, 9, 3, false)
    , (4, 5, 3, 46, 2, 1, 9, 4, false)
    , (5, 6, 3, 46, 2, 1, 5, 5, false)
    , (6, 7, 3, 21, 1, 1, NULL, 6, false)
    , (7, 8, 4, 40, 2, 1, 2, 7, false)
    , (8, 9, 4, 32, 1, 1, NULL, 8, false)
    , (9, 10, 5, 46, 1, 2, 2, 9, false)
    , (10, NULL, 5, 46, 1, 1, 9, 10, false)
    , (11, 11, 4, 33, 1, 1, 9, 11, false)
    , (12, 12, 5, 46, 1, 2, 2, 12, false)
    , (13, NULL, 5, 32, 1, 1, 9, 13, false)
    , (14, 13, 4, 29, 1, 1, 2, 14, false)
    , (15, 14, 4, 38, 1, 1, 9, 15, false)
    , (16, 15, 6, 17, 2, 3, 9, 16, false)
    , (17, NULL, 8, 33, 2, 1, 2, 17, false)
    , (18, 18, 6, 35, 2, 1, 2, 18, false)
    , (19, 19, 6, 35, 1, 1, 2, 19, false)
    , (20, 20, 6, 35, 1, 3, 2, 20, false)
    , (21, NULL, 6, 45, 1, 1, 9, 21, false)
    , (22, 21, 4, 30, 1, 1, NULL, 22, false)
    , (23, 22, 6, 35, 1, 1, 2, 23, false)
    , (22, 23, 4, 30, 1, 1, NULL, 22, false)
    , (24, 24, 6, 35, 2, 3, 2, 24, false)
    , (25, 26, 6, 32, 2, 1, 2, 25, false)
    , (26, 27, 6, 35, 1, 1, 4, 26, false)
    , (27, 28, 4, 46, 2, 1, NULL, 27, false)
    , (28, 29, 6, 35, 1, 2, NULL, 28, false)
    , (29, 30, 6, 45, 2, 1, NULL, 29, false)
    , (30, 31, 6, 15, 1, 1, NULL, 30, false)
    , (31, 32, 4, 32, 4, 2, NULL, 31, false)
    , (32, 35, 4, 25, 2, 1, 3, 32, false)
    , (33, 36, 6, 43, 2, 1, 2, 33, false)
    , (34, 37, 4, 21, 1, 3, 6, 34, false)
    , (35, 38, 4, 43, 2, 1, 6, 35, false)
    , (36, 39, 6, 5, 2, 4, 6, 36, false)
    , (37, 41, 6, 27, 1, 1, 6, 37, false)
    , (38, 42, 4, 10, 1, 1, 7, 38, true)
    , (39, 43, 6, 13, 2, 1, 1, 39, false)
    , (40, 44, 6, 21, 1, 1, 6, 40, false)
    , (41, 45, 4, 4, 2, 1, NULL, 41, true)
    , (42, 46, 6, 7, 2, 1, 10, 42, true)
    , (43, 47, 4, 11, 2, 1, NULL, 43, true)
    , (44, 48, 6, 32, 1, 1, NULL, 44, true)
    , (45, 49, 4, 38, 1, 1, NULL, 45, true);

/******************************************************************************
 * read
 *****************************************************************************/
SELECT CONCAT(p.first, ' ', IF(ISNULL(p.middle), '', CONCAT(p.middle, ' ')), p.last) president
    , CONCAT(vp.first, ' ', IF(ISNULL(vp.middle), '', CONCAT(vp.middle, ' ')), vp.last) vice_president
    , pty.name party
    , st.name birth_state
    , pd.terms_served
    , r.reason reason_left_office
    , m.branch military_branch
    , CONCAT(f.first, ' ', IF(ISNULL(f.middle), '', CONCAT(f.middle, ' ')), f.last) first_lady
    , IF(living, 'Yes', 'No') living
FROM pres_details pd
LEFT JOIN pres p
ON p.pres_id = pd.pres_id
LEFT JOIN vice_pres vp
ON vp.vice_pres_id = pd.vice_pres_id
LEFT JOIN party pty
ON pty.party_id = pd.party_id
LEFT JOIN state st
ON st.state_id = pd.state_id
LEFT JOIN reason_left_office r
ON r.reason_left_office_id = pd.reason_left_office_id
LEFT JOIN military_branch m
ON m.military_branch_id = pd.military_branch_id
LEFT JOIN first_lady f
ON f.first_lady_id = pd.first_lady_id
WHERE p.pres_id = 16;

SELECT CONCAT(p.first, ' ', IF(ISNULL(p.middle), '', CONCAT(p.middle, ' ')), p.last) president
FROM pres_details pd
LEFT JOIN pres p
ON p.pres_id = pd.pres_id
LEFT JOIN military_branch m
ON m.military_branch_id = pd.military_branch_id
WHERE m.branch = 'Army';

SELECT CONCAT(p.first, ' ', IF(ISNULL(p.middle), '', CONCAT(p.middle, ' ')), p.last) president
FROM pres_details pd
LEFT JOIN pres p
ON p.pres_id = pd.pres_id
LEFT JOIN reason_left_office r
ON r.reason_left_office_id = pd.reason_left_office_id
WHERE r.reason_left_office_id = 2;

/******************************************************************************
 * update
 *****************************************************************************/


/******************************************************************************
 * delete
 *****************************************************************************/

