package currell;

import java.util.Scanner;

public class Test {

    public static void main(String[] args) { // standard "main signature"

        System.out.println("Enter Password: ");
        // "alt + enter" to import class (see top of file)
        Scanner userInput = new Scanner(System.in); // Scanner === input. Like cin in C++
                                                    // Usually used with "nextLine()"
                                                    // About scanners: http://pages.cs.wisc.edu/~hasti/cs368/JavaTutorial/NOTES/JavaIO_Scanner.html

        String password = userInput.nextLine(); // Read user input.
                                                // "nextLine" returns a string.
                                                // I wonder if nextLine works like cin.ignore();
                                                // in C++ to ignore new lines?

        User user = new User(password); // new instance of User class

        // Print User class (before hash)
        System.out.println(user);

        // Need try statement due to "Unhandled exception: java.lang.Exception" error.
        // This is due to imported functions in NSALoginController.java that throw errors.
        try {

            // click red bulb to add try/catch when hovering over hashUserPassword
            NSALoginController.hashUserPassword(user);

        } catch (WeakPasswordException e) {

            System.out.println("Weak Password Error: " + e.getMessage());

        } catch (Exception e) {

            System.out.println("Some ting wong . . .");
            // e.printStackTrace();

        }

        // Print User class (after hash)
        System.out.println(user);

        // Ask the user to re-enter the password for verification.
        System.out.println("Re-enter Password: ");
        userInput = new Scanner(System.in);

        // Update the password variable.
        password = userInput.nextLine();

        // NSALoginController.verifyPassword doesn't set the password value. Need to do it here.
        user.setPassword(password);

        // Print User class (before verification)
        System.out.println(user);

        // verifyPassword throws errors just like "hashUserPassword()"
        try {

            // This conditional was the only part I struggled with. It didn't occur to me that "verifyPassword()"
            // returned a boolean value (That was not apparent from the function description. I would have known to
            // use a conditional if I had known the function returned truthy/falsy). In hindsight, I was able to
            // determine that from the return statements.
            // Per the Plagiarism Policy in the Syllabus, I am citing the following help for this conditional ONLY.
            // The rest of the code on this page is my own (except for what was provided in class video instructions).
            // Former BYU-I student: David Baldwin
            // URL: https://github.com/dbaldwin77/NSALoginController/blob/master/src/baldwin/Test.java
            if (NSALoginController.verifyPassword(user)) {

                System.out.println("Passwords match.");

            } else {

                System.out.println("Passwords do NOT match.");

            }

        } catch (Exception e) {

            System.out.println("Error: Passwords do NOT match.");
            // e.printStackTrace();

        }

        // Clear password.
        user.setPassword("");

        // Print User class (after verification)
        System.out.println(user);

    } // end main

} // end class
