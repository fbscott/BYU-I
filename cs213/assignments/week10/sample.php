<!DOCTYPE html>
<html lang="en">
<head>
   <meta charset="UTF-8">
   <title>Week10_Quiz</title>
</head>
<body>
   <div>
      <h2>Question 1:</h2>
   </div>
   <div>
      <h2>Question 2:</h2>
   </div>
   <div>
      <h2>Question 3:</h2>
      <?php $value = 42; ?>
      <?php 
         print "<b>";
         print $value;
         print "</b>";
      ?>
      <?php 
         printf("<b>%d</b>", $value);
      ?>
      <?php 
         print "<b>$value</b>";
      ?>
      <?php 
         print ("<b>$value</b>");
      ?>
      <?php 
         print '<b>$value</b>';
      ?>
      <?php 
         echo "<b>$value</b>";
      ?>
   </div>
   <div>
      <h2>Question 4:</h2>
      <?php 
         // $stuff1 = "zero one two";$stuff2 = explode(" ", $stuff1); print $stuff2[0];
       ?> <br />
       <?php 
         // $stuff = array("zero", "one", "two");print $stuff[1];
       ?> <br />
       <?php 
         // $stuff = array("zero", "one", "two"); print implode(" ", $stuff);
       ?> <br />
       <?php 
         // $stuff = array("zero", "one", "two"); print sizeof($stuff);
       ?>
   </div>
   <div>
      <h2>Question 5:</h2>
      <?php 
         // $books = array("Matthew", "Mark", "Luke", "John");
         // while ($book = next($books))
         //    print "<b>$book</b>";
      ?>
      <?php 
         // $books = array("Matthew" => 1, "Mark" => 2, "Luke" => 3, "John" => 4);
         // while ($book = each($books))
         //    print "<b>$book[key]</b>";
      ?>
      <?php 
         // $books = array("Matthew", "Mark", "Luke", "John");
         // foreach ($books as $book)
         //    print "<b>$book</b>";
      ?>
      <?php 
         // $books = array("Matthew" => 1, "Mark" => 2, "Luke" => 3, "John" => 4);
         // foreach ($books as $book => $order)
         //    print "<b>$book</b>";
      ?>
      <?php 
         // $books = array("Matthew" => 1, "Mark" => 2, "Luke" => 3, "John" => 4);
         // while ($book = next($books))
         //  print "<b>$book</b>";
      ?>
      <?php 
         // $books = array("Matthew" => 1, "Mark" => 2, "Luke" => 3, "John" => 4);
         // foreach ($book = each($books))
         //    print "<b>$book["key"]</b>";
      ?>
      <?php 
         // $books = array("Matthew", "Mark", "Luke", "John");
         // while ($books as $book)
         //    print "<b>$book</b>";
      ?>
      <?php 
         // $books = array("Matthew" => 1, "Mark" => 2, "Luke" => 3, "John" => 4);
         // foreach ($books = $order => $book)
         //    print "<b>$book</b>";
      ?>
   </div>
</body>
</html>