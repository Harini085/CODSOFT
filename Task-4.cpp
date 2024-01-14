#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Function 
void displayMenu();

void addTask(vector<Task>& tasks);

void viewTasks(const vector<Task>& tasks);

    void markAsCompleted(vector<Task>& tasks);

   void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;

    while (true) {
        displayMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        	
            case 1:
                addTask(tasks);
                break;
                
            case 2:
                viewTasks(tasks);
                break;
                
            case 3:
                markAsCompleted(tasks);
                break;
                
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the to-do list manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// Function definitions

void displayMenu() {
    cout << "\n**************To-Do List Manager *************\n";
    cout <<"1. Add Task\n";
    cout <<"2. View Tasks\n";
    cout <<"3. Mark Task as Completed\n";
    cout <<"4. Remove Task\n";
    cout <<"5. Exit\n";
    cout<<"\n*************************************************\n";
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    cout << "Enter the task description: ";
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    
    string description;
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "* Task added successfully ! *\n";
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n===== Tasks =====\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << setw(3) << (i+1) << ". ";
            cout << (tasks[i].completed ? "[X] " : "[ ] ");
            cout << tasks[i].description << endl;
        }  }  }

void markAsCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter the task index to mark as completed: ";
        int index;
        cin >> index;
        
        if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed.\n";
        } 
		
		else {
            cout << "Invalid task index.\n";
        }  }  }

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    
    if (!tasks.empty()) {
        cout << "Enter the task index to remove: ";
        int index;
        
     cin >> index;
        if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            
            cout << "*Task removed successfully.*\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }
}


