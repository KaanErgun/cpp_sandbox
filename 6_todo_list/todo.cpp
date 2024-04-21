/**
 * ToDo List Application
 *
 * This simple console application allows users to manage a to-do list.
 * Users can add tasks, delete tasks, and view all tasks. The tasks are
 * stored in a vector of strings, and the application uses basic console
 * input and output for interaction. This example utilizes C++17 features
 * for handling input and managing the tasks list.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDo {
private:
    vector<string> tasks;  // Vector to store the list of tasks

public:
    // Adds a task to the list
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added successfully." << endl;
    }

    // Deletes a task from the list by its index
    void deleteTask(int index) {
        if (index < 0 || index >= tasks.size()) {  // Check for valid index
            cout << "Invalid task index." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index);
        cout << "Task deleted successfully." << endl;
    }

    // Displays all tasks in the list
    void showTasks() const {
        if (tasks.empty()) {  // Check if the list is empty
            cout << "No tasks to show." << endl;
            return;
        }
        cout << "Tasks List:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ": " << tasks[i] << endl;  // Display each task with a 1-based index
        }
    }
};

int main() {
    ToDo todoList;
    int choice;
    string task;
    int taskIndex;

    while (true) {
        cout << "\nToDo List Application" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. Show All Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a task to add: ";
                cin.ignore(); // Clear input buffer before taking string input to avoid skipping input
                getline(cin, task);
                todoList.addTask(task);
                break;
            case 2:
                todoList.showTasks();
                cout << "Enter the index of the task to delete: ";
                cin >> taskIndex;
                todoList.deleteTask(taskIndex - 1); // Convert 1-based index to 0-based
                break;
            case 3:
                todoList.showTasks();
                break;
            case 4:
                cout << "Exiting application." << endl;
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
