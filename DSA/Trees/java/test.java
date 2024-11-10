import java.util.Scanner;  

public class test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = scanner.nextLine();  
        System.out.print("Enter your age: ");
        int age = scanner.nextInt();  // Read an integer input

        // Display the input received
        System.out.println("Hello, " + name + "! You are " + age + " years old.");

        // Close the scanner
        scanner.close();
    }
}
