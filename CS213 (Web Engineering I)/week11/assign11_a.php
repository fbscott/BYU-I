<!DOCTYPE html>
<html lang="en">
<head>
   <meta charset="UTF-8">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <link rel="stylesheet" href="./css/assign11_php.css">
   <title>Purchase Review</title>
</head>
<body>
   <h1>
      <?php 
          if (isset($_POST['Submit'])) {
              echo 'Purchase was submitted.';
          }
          elseif (isset($_POST['Cancel'])) {
              echo 'Purchase was canceled.';
          }
      ?>
   </h1>
</body>
</html>
