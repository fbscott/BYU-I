<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="./css/mortgage.css">
  <title>Mortgage Calculator</title>
  <?php
      // globals 
      $amount  = $_GET['amount'];
      $apr     = $_GET['apr'];
      $term    = $_GET['term'];

      /*****************************************************************************
       * CALCULATE LOAN PAYMENT
       ****************************************************************************/
      function calculatePayment() {
         global $amount, $apr, $term;

         $localAmount = $amount;
         $localApr    = $apr / 1200;
         $localTerm   = $term * 12;

         $payment = round($localAmount * $localApr / (1 - (pow(1 / (1 + $localApr), $localTerm))), 2);

         echo $payment;
      }
   ?>
</head>
<body>
  <h1>Mortgage Calculator</h1>
  <form action="" name="mortCalc">
    <table>
      <!----------------------------------- APR ------------------------------------>
      <tr>
        <td>APR:</td>
        <td>
          <input type="text" name="apr" id="apr" placeholder="<?php echo $apr ?>">
        </td>
        <td>
          <span id="apr-error" class="error hide">Error: APR must be between 0% and 25%.</span>
        </td>
      </tr>
      <!----------------------------------- End APR -------------------------------->
      <!----------------------------------- Term ----------------------------------->
      <tr>
        <td>Term:</td>
        <td>
          <input type="text" name="term" id="term" placeholder="<?php echo $term ?>">
        </td>
        <td>
          <span id="term-error" class="error hide">Error: Term must be between 0 and 40 years.</span>
        </td>
      </tr>
      <!----------------------------------- End Term ------------------------------->
      <!----------------------------------- Amount --------------------------------->
      <tr>
        <td>Amount:</td>
        <td>
          <input type="text" name="amount" id="amount" placeholder="<?php echo $amount ?>">
        </td>
        <td>
          <span id="amount-error" class="error hide">Error: Amount must be greater than $0.00.</span>
        </td>
      </tr>
      <!----------------------------------- End Amount ----------------------------->
      <!----------------------------------- Payment -------------------------------->
      <tr>
        <td>Payment:</td>
        <td><input type="text" name="payment" id="payment" readonly value="<?php calculatePayment(); ?>"></td>
      </tr>
      <!----------------------------------- End Payment ---------------------------->
      <!----------------------------------- Buttons -------------------------------->
      <tr>
        <td>&nbsp;</td>
        <td>
          <input type="reset" value="Reset" id="clear" />
          <input type="submit" value="Calculate" id="calculate" />
        </td>
        <td>
          <span id="calculate-error" class="error hide">Error: All input fields must contain valid data.</span>
        </td>
      </tr>
      <!----------------------------------- End Buttons ---------------------------->
    </table>
  </form>
</body>
</html>
