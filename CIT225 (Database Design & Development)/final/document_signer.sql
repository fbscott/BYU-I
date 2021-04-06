/******************************************************************************
 * create
 *****************************************************************************/
INSERT INTO document_signer (document_id, pres_id)
VALUES (1, 2)
    , (1, 3)
    , (2, 1)
    , (2, 4)
    , (3, 4)
    , (4, 16);

/******************************************************************************
 * read
 *****************************************************************************/
SELECT d.title
    , CONCAT(p.first, ' ', IF(ISNULL(p.middle), '', CONCAT(p.middle, ' ')), p.last) president
FROM document_signer ds
LEFT JOIN document d
ON d.document_id = ds.document_id
LEFT JOIN pres p
ON p.pres_id = ds.pres_id;

SELECT CONCAT(p.first, ' ', IF(ISNULL(p.middle), '', CONCAT(p.middle, ' ')), p.last) president
FROM document_signer ds
LEFT JOIN document d
ON d.document_id = ds.document_id
LEFT JOIN pres p
ON p.pres_id = ds.pres_id
WHERE d.document_id = 1;

/******************************************************************************
 * update
 *****************************************************************************/


/******************************************************************************
 * delete
 *****************************************************************************/

