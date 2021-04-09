<!DOCTYPE html>
<html lang="en">
<head>
   <meta charset="UTF-8">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <link rel="stylesheet" href="./css/assign11_php.css">
   <title>Purchase Review</title>
</head>
<body>
   <h1>Purchase Review</h1>

   <table class="align-right">
      <tr>
         <th>Name:</th>
         <td><?php echo $_POST['first_name'] . ' ' . $_POST['last_name'] ?></td>
      </tr>
      <tr>
         <th>Address:</th>
         <td><?php echo $_POST['address'] ?></td>
      </tr>
      <tr>
         <th>Phone:</th>
         <td><?php echo $_POST['phone'] ?></td>
      </tr>
      <tr>
         <th>Itemized Purchase List:</th>
         <td>
            <ul>
            <?php 
               $prices = $_POST['prices'];

               foreach ($prices as $price) {
                  switch ($price) {
                     case '5000000.00':
                        echo '<li>Time Machine ($' . number_format($price, 2, '.', ',') . ')</li>';
                        break;
                     case '2000000.00':
                        echo '<li>Transporter ($' . number_format($price, 2, '.', ',') . ')</li>';
                        break;
                     case '3500000.00':
                        echo '<li>Anti-gravity Propulsion Vehicle ($' . number_format($price, 2, '.', ',') . ')</li>';
                        break;
                     case '275000.00':
                        echo '<li>Cloaking Device ($' . number_format($price, 2, '.', ',') . ')</li>';
                        break;
                     default:
                        echo '<li>No items selected.</li>';
                        break;
                  }
               }
             ?>
            </ul>
         </td>
      </tr>
      <tr>
         <th>Total Cost:</th>
         <td>
            <?php 
               $total = 0;

               foreach ($_POST['prices'] as $price) {
                  $total += $price;
               }

               echo number_format($total, 2, '.', ',');
             ?>
         </td>
      </tr>
      <tr>
         <th>Credit Type:</th>
         <td><?php echo $_POST['card_type'] ?></td>
      </tr>
      <tr>
         <th>Exp:</th>
         <td>
            <?php
               $date = date_create_from_format('m/Y', $_POST['exp_date']);
               echo date_format($date, 'F Y');
            ?>
         </td>
      </tr>
   </table>

   <form method="POST" action="assign11_a.php">
      <input type="submit" name="Submit" value="Submit">
      <input type="submit" name="Cancel" value="Cancel">
   </form>
</body>
</html>
