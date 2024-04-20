/**
 * Basic Calculator Program
 *
 * This program takes two numbers and an arithmetic operator from the user and performs
 * the requested arithmetic operation. It supports addition (+), subtraction (-),
 * multiplication (*), and division (/). Division by zero is handled gracefully by returning
 * an optional type with no value, which indicates an error condition. The use of std::optional
 * allows the program to safely handle situations where an operation might fail, such as
 * division by zero.
 *
 * Features:
 * - Supports basic arithmetic operations: +, -, *, /
 * - Utilizes std::optional to manage failed operations (e.g., division by zero)
 * - Input validation for arithmetic operations
 * - Error handling and error messages for invalid inputs or operations
 */

#include <iostream>
#include <optional>

using namespace std;

// Function to perform arithmetic operations and handle errors using std::optional
optional<double> perform_operation(double num1, double num2, char operation) {
    switch (operation) {
        case '+': return num1 + num2; // Perform addition
        case '-': return num1 - num2; // Perform subtraction
        case '*': return num1 * num2; // Perform multiplication
        case '/': 
            if (num2 == 0.0) { // Check for division by zero
                cout << "Error: Division by zero." << endl;
                return nullopt;  // Return an empty optional as an error signal
            }
            return num1 / num2; // Perform division
        default:
            cout << "Error: Invalid operation." << endl;
            return nullopt; // Return an empty optional for any other invalid operation
    }
}

// Main function to handle user input and output the results
int main() {
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1; // Get the first number from user
    cout << "Enter second number: ";
    cin >> num2; // Get the second number from user
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation; // Get the arithmetic operation from user

    // Attempt to perform the operation using the provided numbers and operation
    auto result = perform_operation(num1, num2, operation);
    if (result) {
        cout << "Result: " << *result << endl; // If result is valid, display it
    } else {
        cout << "Operation failed. Please check your inputs." << endl;
        return 1;  // Return an error code if the operation failed
    }

    return 0;
}
