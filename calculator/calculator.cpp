#include <iostream>
#include <optional>

using namespace std;

optional<double> perform_operation(double num1, double num2, char operation) {
    switch (operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 == 0.0) {
                cout << "Error: Division by zero." << endl;
                return nullopt;  // Use optional to handle division by zero
            }
            return num1 / num2;
        default:
            cout << "Error: Invalid operation." << endl;
            return nullopt;
    }
}

int main() {
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    auto result = perform_operation(num1, num2, operation);
    if (result) {
        cout << "Result: " << *result << endl;
    } else {
        return 1;  // Return an error code if operation failed
    }

    return 0;
}
