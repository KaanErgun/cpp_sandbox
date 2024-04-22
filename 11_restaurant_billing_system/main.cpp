/**
 * Restaurant Billing System
 *
 * This program is a simple console-based restaurant billing system designed to help manage 
 * orders and generate bills for customers. It allows the restaurant staff to add various 
 * dishes to a customer's order, calculate the total amount, and print a detailed bill.
 *
 * Key Features:
 * 1. Add Dish to Order: Allows the user to add dishes along with their prices to the current order.
 * 2. Finalize Bill: Calculates the total amount for the order and displays a detailed bill.
 * 3. Exit: Exits the program.
 *
 * Usage:
 * The system prompts the user with a menu of actions corresponding to the features listed above.
 * The user can select an action by entering the number associated with each feature. The program
 * will then perform the necessary steps to execute the selected action.
 *
 * This application is ideal for small to medium-sized restaurants looking for a straightforward
 * solution to manage customer bills without needing complex POS (Point of Sale) systems.
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>  // For std::accumulate

using namespace std;

struct Dish {
    string name;
    double price;

    Dish(string n, double p) : name(move(n)), price(p) {}
};

class Order {
private:
    vector<Dish> dishes;

public:
    void addDish(const string& name, double price) {
        dishes.push_back(Dish(name, price));
        cout << "Dish added successfully." << endl;
    }

    void printBill() const {
        double total = accumulate(dishes.begin(), dishes.end(), 0.0,
                                  [](double sum, const Dish& dish) { return sum + dish.price; });

        cout << "\nFinal Bill" << endl;
        cout << "----------" << endl;
        for (const auto& dish : dishes) {
            cout << setw(20) << left << dish.name << "$" << fixed << setprecision(2) << dish.price << endl;
        }
        cout << setw(20) << left << "Total" << "$" << total << endl;
    }
};

int main() {
    Order currentOrder;
    int choice;
    string dishName;
    double dishPrice;

    cout << "Restaurant Billing System" << endl;

    while (true) {
        cout << "1. Add Dish to Order" << endl;
        cout << "2. Finalize Bill" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter dish name: ";
                cin >> ws; getline(cin, dishName);
                cout << "Enter dish price: ";
                cin >> dishPrice;
                currentOrder.addDish(dishName, dishPrice);
                break;
            case 2:
                currentOrder.printBill();
                break;
            case 3:
                cout << "Exiting application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
