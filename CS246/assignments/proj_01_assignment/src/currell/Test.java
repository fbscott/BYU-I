package currell;

import java.util.Scanner;

public class Test {

    public static void main(String[] args) {

        System.out.println("Enter Password: ");
        // "alt + enter" to import class (see top of file)
        Scanner userInput = new Scanner(System.in); // Scanner === input. Like cin in C++
                                                    // Usually used w/nextLine()

        String password = userInput.nextLine(); // read user input
                                                // nextLine returns a string

        User user = new User(password); // new instance of User class

        // print User class
        System.out.println(user);

        // Need try statement due to "Unhandled exception: java.lang.Exception" error.
        // This is due to imported functions in NSALoginController.java that throw errors.
        try {

            // click red bulb to add try/catch when hovering over hashUserPassword
            NSALoginController.hashUserPassword(user);

        } catch (Exception e) {

            System.out.println("Some ting wong . . .");
            // e.printStackTrace();

        }

        // print User class
        System.out.println(user);
    }

}
