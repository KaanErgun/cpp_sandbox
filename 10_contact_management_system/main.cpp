/**
 * Contact Management System
 *
 * This program is a simple console-based contact management system designed to help manage 
 * personal or business contacts. It allows users to add, update, delete, and view contact 
 * details such as name, phone number, and email address.
 *
 * Key Features:
 * 1. Add Contact: Allows the user to add new contact details to the system.
 * 2. Update Contact: Enables the user to update existing contact information.
 * 3. Delete Contact: Allows for the deletion of any contact from the system.
 * 4. Display Contacts: Lists all the contacts currently stored, showing detailed information.
 * 5. Exit: Exits the program.
 *
 * Usage:
 * The system prompts the user with a menu of actions corresponding to the features listed above. 
 * The user can select an action by entering the appropriate number associated with each feature. 
 * The program will then ask for the necessary information to perform the selected action, such as 
 * the contact's name or phone number.
 *
 * This application is ideal for individuals or small businesses looking to manage their contacts 
 * in a straightforward and efficient manner without the need for complex and costly software solutions.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;

    Contact(string n, string p, string e) : name(move(n)), phone(move(p)), email(move(e)) {}
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    void addContact(const string& name, const string& phone, const string& email) {
        contacts.emplace_back(name, phone, email);
        cout << "Contact added successfully." << endl;
    }

    void updateContact(const string& oldName, const string& newName, const string& newPhone, const string& newEmail) {
        auto it = find_if(contacts.begin(), contacts.end(), [&oldName](const Contact& c) { return c.name == oldName; });
        if (it != contacts.end()) {
            it->name = newName;
            it->phone = newPhone;
            it->email = newEmail;
            cout << "Contact updated successfully." << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void deleteContact(const string& name) {
        auto it = remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) { return c.name == name; });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << "Contact deleted successfully." << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void displayContacts() const {
        if (contacts.empty()) {
            cout << "No contacts to display." << endl;
            return;
        }
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << endl;
        }
    }
};

int main() {
    ContactManager manager;
    int choice;
    string name, phone, email, oldName;

    cout << "Contact Management System" << endl;

    while (true) {
        cout << "1. Add Contact" << endl;
        cout << "2. Update Contact" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Display Contacts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> ws; getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                cout << "Enter email: ";
                getline(cin, email);
                manager.addContact(name, phone, email);
                break;
            case 2:
                cout << "Enter old name: ";
                cin >> ws; getline(cin, oldName);
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new phone: ";
                getline(cin, phone);
                cout << "Enter new email: ";
                getline(cin, email);
                manager.updateContact(oldName, name, phone, email);
                break;
            case 3:
                cout << "Enter name to delete: ";
                cin >> ws; getline(cin, name);
                manager.deleteContact(name);
                break;
            case 4:
                manager.displayContacts();
                break;
            case 5:
                cout << "Exiting application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
