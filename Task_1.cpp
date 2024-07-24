#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string& name) : name(name), completed(false) {}
    
    void markAsCompleted() {
        completed = true;
    }
    
    bool isCompleted() const {
        return completed;
    }
    
    const std::string& getName() const {
        return name;
    }
    
private:
    std::string name;
    bool completed;
};

class ToDoList {
public:
    void addTask(const std::string& taskName) {
        tasks.emplace_back(taskName);
    }
    
    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markAsCompleted();
        } else {
            std::cerr << "Invalid task number!" << std::endl;
        }
    }
    
    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }
        
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << (i + 1) << ". " << tasks[i].getName() 
                      << (tasks[i].isCompleted() ? " [Completed]" : "") 
                      << std::endl;
        }
    }
    
private:
    std::vector<Task> tasks;
};

void showMenu() {
    std::cout << "\nTo-Do List Application\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Complete Task\n";
    std::cout << "3. View Tasks\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    ToDoList todoList;
    int choice;
    
    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();  // Clear the newline character left in the buffer
        
        switch (choice) {
            case 1: {
                std::cout << "Enter task name: ";
                std::string taskName;
                std::getline(std::cin, taskName);
                todoList.addTask(taskName);
                break;
            }
            case 2: {
                std::cout << "Enter task number to complete: ";
                int taskNumber;
                std::cin >> taskNumber;
                todoList.completeTask(taskNumber - 1);
                break;
            }
            case 3:
                todoList.viewTasks();
                break;
            case 4:
                std::cout << "Exiting application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please choose again." << std::endl;
                break;
        }
    } while (choice != 4);
    
    return 0;
}
