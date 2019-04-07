<?php
   $name        = $_GET['firstName'] . " " . $_GET['lastName'];
   $studentID   = $_GET['studentID'];
   $performance = $_GET['performance'];
   $skill       = $_GET['skill'];
   $instrument  = $_GET['instrument'];
   $location    = $_GET['location'];
   $room        = $_GET['room'];
   $time        = $_GET['time'];
   $name2       = $_GET['firstName2'] . " " . $_GET['lastName2'];
   $studentID2  = $_GET['studentID2'];

   $file = "./data/assign13.txt";

   if ($performance !== 'duet') {
      $name2       = "N/A";
      $studentID2  = "N/A";
   }

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

   file_put_contents($file, $tableInner, FILE_APPEND);
   
   $string = file_get_contents($file);

   echo "$string";
?>
