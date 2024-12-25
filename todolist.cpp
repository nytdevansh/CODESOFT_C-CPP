#include <iostream>
#include <vector>
#include <string>


struct Task {
    std::string name;
    std::string status; // Status can be "Pending", "Ongoing", or "Completed"
};

std::vector<Task> taskList;

// Function to add tasks
void add(int n) {
    std::cout << "Enter the tasks:\n";
    for (int i = 0; i < n; i++) {
        Task task;
        std::cout << "Task " << i + 1 << ": ";
        std::cin.ignore(); // Clear the input buffer
        std::getline(std::cin, task.name); // Allow multi-word input
        task.status = "Pending"; // New tasks default to "Pending"
        taskList.push_back(task);
    }
    std::cout << n << " task(s) added successfully.\n";
}

// Function to display all tasks
void view() {
    if (taskList.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }

    std::cout << "Task List:\n";
    for (size_t i = 0; i < taskList.size(); i++) {
        std::cout << i + 1 << ". " << taskList[i].name 
                  << " [" << taskList[i].status << "]\n";
    }
}

// Function to update the status of a task
void updateStatus() {
    if (taskList.empty()) {
        std::cout << "No tasks available to update.\n";
        return;
    }

    view();
    std::cout << "Enter the task number to update status: ";
    int taskNumber;
    std::cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskList.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    std::cout << "Enter new status (Pending/Ongoing/Completed): ";
    std::string newStatus;
    std::cin >> newStatus;

    // Validate status input
    if (newStatus != "Pending" && newStatus != "Ongoing" && newStatus != "Completed") {
        std::cout << "Invalid status. Please enter 'Pending', 'Ongoing', or 'Completed'.\n";
        return;
    }

    taskList[taskNumber - 1].status = newStatus;
    std::cout << "Task " << taskNumber << " updated to " << newStatus << ".\n";
}

// Function to remove a task
void removeTask() {
    if (taskList.empty()) {
        std::cout << "No tasks available to remove.\n";
        return;
    }

    view();
    std::cout << "Enter the task number to remove: ";
    int taskNumber;
    std::cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskList.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    taskList.erase(taskList.begin() + taskNumber - 1);
    std::cout << "Task " << taskNumber << " removed successfully.\n";
}

// Main program
int main() {
    int choice;

    do {
        std::cout << "\nTask Manager\n";
        std::cout << "1. Add Tasks\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Update Task Status\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                std::cout << "Enter the number of tasks to add: ";
                std::cin >> n;
                add(n);
                break;
            }
            case 2:
                view();
                break;
            case 3:
                updateStatus();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                std::cout << "Exiting Task Manager. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}