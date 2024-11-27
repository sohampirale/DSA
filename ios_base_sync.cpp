#include <iostream>
#include <fstream>
#include <limits> // For std::numeric_limits

// Lambda function for input/output handling
auto init = []() {
    // Optimize input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // Open a file to write output
    std::ofstream out("user.out"); // Output will be saved to "user.out"

    int num;
    std::cout << "Enter numbers (-1 to stop):" << std::endl;

    // Infinite loop to process input
    while (true) {
        std::cin.clear(); // Clear any error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
        std::cin >> num; // Read a number

        if (std::cin.fail()) {
            // If the input is invalid, skip this iteration
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        if (num == -1) {
            out << "false\n"; // Write "false" for -1
            std::cout << "Stopping input..." << std::endl;
            break; // Exit the loop
        } else {
            out << "true\n"; // Write "true" for other numbers
        }
    }

    // Flush and close the file
    out.flush();
    out.close();

    // Exit the program early
    std::cout << "Output saved to user.out." << std::endl;
    exit(0); // Ends the program immediately
    return 0; // This return is redundant, but required by the lambda
}();

int main() {
    // This will not execute because `exit(0)` in the lambda ends the program
    std::cout << "This message will not be printed!" << std::endl;
    return 0;
}
 