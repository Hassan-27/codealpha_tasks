#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> tasks; // Using Vector to store tasks as strings.
    char choice;

    //Added switch cases for navigating the menu
    do {
        cout << "===== To-Do List =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. List Tasks" << endl;
        cout << "3. Delete Task" << endl; 
        cout << "4. Exit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            //Adding new task 
            case '1': {             
                string newTask;
                cin.ignore(); 

                cout << endl << "Enter task: ";
                getline(cin, newTask);
                tasks.push_back(newTask);
                cout << "Task added successfully!" << endl << endl;
                break;
            }

            //Displaying added tasks
            case '2': {
                if (tasks.empty()) {
                    cout << endl << "No tasks added yet." << endl;
                } else {
                    cout << endl << "===== Tasks =====" << endl;
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        cout << i + 1 << ". " << tasks[i] << endl;
                    }
                }
                break;
            }

            //Deleting a task from the list
            case '3': {
                if (tasks.empty()) {
                    cout << "No tasks to delete." << endl;
                } else {
                    cout << "Enter task number to delete (1-" << tasks.size() << "): ";
                    int taskNumber;
                    cin >> taskNumber;
                    
                    if (taskNumber >= 1 && taskNumber <= tasks.size()) {        //Check if inputted task no. is valid
                        tasks.erase(tasks.begin() + taskNumber - 1);
                        cout << "Task " << taskNumber << " deleted successfully." << endl;
                    } else {
                        cout << "Invalid task number. No task deleted." << endl;
                    }
                }
                break;
            }

            // Existing the program
            case '4':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }

        cout << endl;

    } while (choice != '4');

    return 0;
}
