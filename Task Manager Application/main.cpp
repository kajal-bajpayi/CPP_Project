#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
private:
    string title;
    string description;
    string dueDate;

public:
    Task(const string& t, const string& d, const string& dd) : title(t), description(d), dueDate(dd) {}

    const string& getTitle() const {
        return title;
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "--------------------------" << endl;
    }
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void displayTasks() const {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            for (const Task& task : tasks) {
                task.display();
            }
        }
    }

    void deleteTask(const string& title) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->getTitle() == title) {
                tasks.erase(it);
                cout << "Task '" << title << "' deleted successfully." << endl;
                return;
            }
        }
        cout << "Task '" << title << "' not found." << endl;
    }
};

int main() {
    TaskManager taskManager;

    char choice;
    do {
        cout << "Task Manager Application" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case '1': {
                string title, description, dueDate;
                cout << "Enter Task Title: ";
                getline(cin, title);
                cout << "Enter Task Description: ";
                getline(cin, description);
                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                Task task(title, description, dueDate);
                taskManager.addTask(task);
                cout << "Task added successfully." << endl;
                break;
            }

            case '2':
                cout << "Task List:" << endl;
                taskManager.displayTasks();
                break;

            case '3': {
                string title;
                cout << "Enter Task Title to Delete: ";
                getline(cin, title);
                taskManager.deleteTask(title);
                break;
            }

            case '4':
                cout << "Exiting Task Manager Application. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != '4');

    return 0;
}
