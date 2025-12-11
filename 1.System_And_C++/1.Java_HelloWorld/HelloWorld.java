import java.lang.System;
import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        int a;
        System.out.println("Hello World!");

        System.out.print("Please enter an integer: ");
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();  // read an integer from keyboard and store it in a
        System.out.println("You entered: " + a);
    }
}
