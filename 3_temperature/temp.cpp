/**
 * Temperature Conversion Program
 *
 * This program allows the user to convert temperatures between Fahrenheit, Celsius, and Kelvin.
 * The user is prompted to enter the original temperature unit, the temperature value, and the target unit for conversion.
 * The program handles conversion in any direction among Fahrenheit, Celsius, and Kelvin.
 *
 * Features:
 * - Convert temperatures between Fahrenheit, Celsius, and Kelvin
 * - Input validation for unit correctness
 * - Case-insensitive unit comparison
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double f) {
    return (f - 32) * 5.0 / 9.0;
}

// Convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32;
}

// Convert Celsius to Kelvin
double celsius_to_kelvin(double c) {
    return c + 273.15;
}

// Convert Kelvin to Celsius
double kelvin_to_celsius(double k) {
    return k - 273.15;
}

// Convert Fahrenheit to Kelvin
double fahrenheit_to_kelvin(double f) {
    return fahrenheit_to_celsius(f) + 273.15;
}

// Convert Kelvin to Fahrenheit
double kelvin_to_fahrenheit(double k) {
    return celsius_to_fahrenheit(kelvin_to_celsius(k));
}

// Main function to handle user input and display converted temperatures
int main() {
    double temperature;
    string input_unit, target_unit;

    // Prompt for original temperature unit
    cout << "Enter original unit (Fahrenheit, Celsius, Kelvin): ";
    cin >> input_unit;

    // Prompt for temperature value
    cout << "Enter temperature in " << input_unit << ": ";
    cin >> temperature;

    // Prompt for target conversion unit
    cout << "Convert to (Fahrenheit, Celsius, Kelvin): ";
    cin >> target_unit;

    // Normalize the case of user inputs for consistent comparison
    transform(input_unit.begin(), input_unit.end(), input_unit.begin(), ::tolower);
    transform(target_unit.begin(), target_unit.end(), target_unit.begin(), ::tolower);

    // Determine and execute the appropriate conversion based on user input
    double converted = 0;
    bool valid_conversion = true;

    if (input_unit == "celsius" && target_unit == "fahrenheit") {
        converted = celsius_to_fahrenheit(temperature);
    } else if (input_unit == "celsius" && target_unit == "kelvin") {
        converted = celsius_to_kelvin(temperature);
    } else if (input_unit == "fahrenheit" && target_unit == "celsius") {
        converted = fahrenheit_to_celsius(temperature);
    } else if (input_unit == "fahrenheit" && target_unit == "kelvin") {
        converted = fahrenheit_to_kelvin(temperature);
    } else if (input_unit == "kelvin" && target_unit == "celsius") {
        converted = kelvin_to_celsius(temperature);
    } else if (input_unit == "kelvin" && target_unit == "fahrenheit") {
        converted = kelvin_to_fahrenheit(temperature);
    } else if (input_unit == target_unit) {
        converted = temperature;  // No conversion necessary if units are the same
    } else {
        valid_conversion = false;
        cout << "Invalid unit combination entered." << endl;
    }

    // Output the result if conversion was successful
    if (valid_conversion) {
        cout << temperature << " " << input_unit << " is " << converted << " " << target_unit << "." << endl;
    }

    return 0;
}
