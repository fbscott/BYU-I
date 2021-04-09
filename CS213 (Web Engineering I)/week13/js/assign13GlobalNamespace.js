// Piano Registration
var PR = PR || {};

// all the inputs
PR.firstName   = document.piano.first_name;
PR.lastName    = document.piano.last_name;
PR.studentID   = document.piano.student_id;
PR.performance = document.piano.performance;
PR.skill       = document.piano.skill;
PR.instrument  = document.piano.instrument;
PR.location    = document.piano.location;
PR.room        = document.piano.room;
PR.time        = document.piano.time_slot;
PR.firstName2  = document.piano.first_name_2;
PR.lastName2   = document.piano.last_name_2;
PR.studentID2  = document.piano.student_id_2;
// other performer info: name (first and last) & student ID
PR.duetArr = [
    PR.firstName2,
    PR.lastName2,
    PR.studentID2
];
// DOM element to be updated
PR.displayRecitalData = document.getElementById('js-recital-data');
// call to action
PR.button = document.getElementById('js-button');
