<?php
   // user input
   $firstName   = $_GET['firstName'];
   $lastName    = $_GET['lastName'];
   $studentID   = $_GET['studentID'];
   $performance = $_GET['performance'];
   $skill       = $_GET['skill'];
   $instrument  = $_GET['instrument'];
   $location    = $_GET['location'];
   $room        = $_GET['room'];
   $time        = $_GET['time'];
   $firstName2  = $_GET['firstName2'];
   $lastName2   = $_GET['lastName2'];
   $studentID2  = $_GET['studentID2'];
   $name        = $firstName . " " . $lastName;
   $name2       = $firstName2 . " " . $lastName2;
   // are all inputs filled in
   $isFormValid = true;

   // all of these elems should be filled in
   $elems = array($firstName, $lastName, $studentID, $performance, $skill, $instrument, $location, $room, $time);

   // data file
   $file = "./data/assign13.txt";

   // if not duet, set addit'l fields to "N/A"
   if ($performance !== 'duet') {
      $name2      = "N/A";
      $studentID2 = "N/A";
   }

   // build table
   $tableInner = "<tr>" .
                    "<td>" . $name . "</td>" .
                    "<td>" . $studentID . "</td>" .
                    "<td>" . $performance . "</td>" .
                    "<td>" . $skill . "</td>" .
                    "<td>" . $instrument . "</td>" .
                    "<td>" . $location . "</td>" .
                    "<td>" . $room . "</td>" .
                    "<td>" . $time . "</td>" .
                    "<td>" . $name2 . "</td>" .
                    "<td>" . $studentID2 . "</td>" .
                 "</tr>";

   // iterate through inputs, make sure they're all filled in
   for ($i = 0; $i < sizeof($elems); $i++) { 
      if (empty($elems[$i])) {
         // set validation bool to false if any input is empty
         $isFormValid = false;
      }
   }

   // only read/write to file or return data if all fields are filled in
   if ($isFormValid) {
      file_put_contents($file, $tableInner, FILE_APPEND);

      $string = file_get_contents($file);
   // tell the user to complete the form
   } else {
      $string = '<div id="js-form-error" class="error show"><p>Error: Please complete all fields in order to register.</p></div>';
   }

   echo "$string";
?>
