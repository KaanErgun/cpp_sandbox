#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    int id;
    int stock;
    double price;

    Product(string n, int i, int s, double p) : name(move(n)), id(i), stock(s), price(p) {}
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(const string& name, int id, int stock, double price) {
        products.emplace_back(name, id, stock, price);
        cout << "Product added successfully." << endl;
    }

    void updateStock(int id, int newStock) {
        for (auto& product : products) {
            if (product.id == id) {
                product.stock = newStock;
                cout << "Stock updated successfully for product ID " << id << "." << endl;
                return;
            }
        }
        cout << "Product not found with ID " << id << "." << endl;
    }

    void displayProducts() const {
        if (products.empty()) {
            cout << "No products to display." << endl;
            return;
        }
        cout << setw(10) << left << "ID" << setw(20) << "Name" << setw(10) << "Stock" << setw(10) << "Price" << endl;
        for (const auto& product : products) {
            cout << setw(10) << product.id << setw(20) << product.name << setw(10) << product.stock << setw(10) << product.price << endl;
        }
    }
};

int main() {
    Inventory inventory;
    string name;
    int id, stock, choice;
    double price;

    cout << "Inventory Management System" << endl;

    while (true) {
        cout << "1. Add Product" << endl;
        cout << "2. Update Stock" << endl;
        cout << "3. Display Products" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter product name: ";
                cin >> ws;  // to consume any leading whitespace
                getline(cin, name);
                cout << "Enter product ID: ";
                cin >> id;
                cout << "Enter stock amount: ";
                cin >> stock;
                cout << "Enter price: ";
                cin >> price;
                inventory.addProduct(name, id, stock, price);
                break;
            case 2:
                cout << "Enter product ID to update stock: ";
                cin >> id;
                cout << "Enter new stock amount: ";
                cin >> stock;
                inventory.updateStock(id, stock);
                break;
            case 3:
                inventory.displayProducts();
                break;
            case 4:
                cout << "Exiting application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
