/******************************************************************************
 * create
 *****************************************************************************/
INSERT INTO quote (title, pres_id)
VALUES ('It is better to offer no excuse than a bad one.', 1)
    , ('Honesty is the first chapter of the book wisdom.', 3)
    , ('If freedom of speech is taken away, then dumb and silent we may be led, like sheep to the slaughter.', 1)
    , ('On matters of style, swim with the current, on matters of principle, stand like a rock.', 3)
    , ('The advancement and diffusion of knowledge is the only guardian of true liberty.', 4)
    , ('If tyranny and oppression come to this land it will be in the guise of fighting a foreign enemy.', 4)
    , ('A little flattery will support a man through great fatigue.', 5)
    , ('Courage and perseverance have a magical talisman, before which difficulties disappear and obstacles vanish into air.', 6)
    , ('Try and fail, but don\'t fail to try.', 6)
    , ('One man with courage makes a majority.', 7)
    , ('It\'s easier to do a job right, than to explain why you didn\'t.', 8)
    , ('There is nothing more corrupting, nothing more destructive of the noblest and finest feelings of our nature, than the exercise of unlimited power.', 9)
    , ('It is not strange… to mistake change for progress.', 13)
    , ('You don\'t know what you can miss before you try.', 14)
    , ('I am a slow walker, but I never walk backwards.', 16)
    , ('In the end, it\'s not the years in your life that count. It\'s the life in your years.', 16)
    , ('Leave nothing for tomorrow which can be done today.', 16)
    , ('Whatever you are, be a good one.', 16)
    , ('Nearly all men can stand adversity, but if you want to test a man\'s character, give him power.', 16)
    , ('If wrinkles must be written on our brow, let them not be written on our heart. The spirit should never grow old.', 20)
    , ('Great lives never go out; they go on.', 23)
    , ('It is hard to fail, but it is worse never to have tried to succeed.', 25)
    , ('Do what you can, with what you have, where you are.', 25)
    , ('Be patient and calm; no one can catch a fish with anger.', 30)
    , ('Words without actions are the assassins of idealism.', 30)
    , ('The only thing we have to fear is fear itself.', 31)
    , ('Remember, remember always, that all of us, and you and I especially, are descended from immigrants and revolutionists.', 31)
    , ('It\'s amazing what you can accomplish if you do not care who gets the credit.', 32)
    , ('What counts is not necessarily the size of the dog in the fight- it\'s the size of the fight in the dog.', 33)
    , ('Never question another man\'s motive. His wisdom, yes, but not his motives.', 33)
    , ('Never waste a minute thinking about people you don\'t like.', 33)
    , ('The Chinese use two brush strokes to write the word ‘crisis.\' One brush stroke stands for danger; the other for opportunity. In a crisis, be aware of the danger–but recognize the opportunity.', 34)
    , ('Conformity is the jailer of freedom and the enemy of growth.', 34)
    , ('The hottest places in hell are reserved for those who, in times of great moral crisis, maintain their neutrality.', 34)
    , ('One person can make a difference, and everyone should try.', 34)
    , ('Forgive your enemies, but never forget their names.', 34)
    , ('We become not a melting pot but a beautiful mosaic. Different people, different beliefs, different yearnings, different hopes, different dreams.', 38)
    , ('Live simply, love generously, care deeply, speak kindly, leave the rest to God.', 40)
    , ('I have opinions of my own – strong opinions – but I don\'t always agree with them.', 40)
    , ('A volunteer is a person who can see what others cannot see; who can feel what most do not feel. Often, such gifted persons do not think of themselves as volunteers, but as citizens – citizens in the fullest sense: partners in civilization.', 40)
    , ('We all do better when we work together. Our differences do matter, but our common humanity matters more.', 41)
    , ('When our memories outweigh our dreams, it is then that we become old.', 41)
    , ('There\'s an old saying in Tennessee — I know it\'s in Texas, probably in Tennessee — that says, fool me once, shame on — shame on you. Fool me — you can\'t get fooled again.', 42)
    , ('If you\'re walking down the right path and you\'re willing to keep walking, eventually you\'ll make progress.', 43)
    , ('You have to think anyway, so why not think big?', 44)
    , ('I don\'t know what I\'m signing.', 45);

/******************************************************************************
 * read
 *****************************************************************************/
SELECT p.last, q.title FROM quote q
LEFT JOIN pres p
ON p.pres_id = q.pres_id;

SELECT * FROM quote
WHERE pres_id = 16;

/******************************************************************************
 * update
 *****************************************************************************/
START TRANSACTION;

UPDATE quote
SET title = 'Make America great again!'
WHERE pres_id = 44;

COMMIT;

/******************************************************************************
 * delete
 *****************************************************************************/

