#include <iostream>
#include <vector>
#include <string>

class Task {
    std::string description;
    bool completed;

    public:
    Task(std::string description):description(description) {
        completed = false;
    }

    void displayTask() const {
        if (completed) {
            std::cout <<"[x] " << description << std::endl;
        }
        else {
            std::cout <<"[ ] " << description << std::endl;
        }
    }
    void markCompleted() {
        completed = true;
    }
    void markIncomplete() {
        completed = false;
    }
};

void showAllTasks(const std::vector<Task> &tasks);
void addTask(std::vector<Task> &tasks, std::string description);
void markTaskCompleted(std::vector<Task> &tasks);
void markTaskIncomplete(std::vector<Task> &tasks);
int getValidIndex(const std::vector<Task> &tasks);

int main() {
    std::vector<Task> tasks;
    bool running = true;
    int choice;
    while (running) {
        std::cout <<" <Menu (1-5 choices)> ";
        std::cout <<"\n<-------------------->\n";
        std::cout <<"1. Add Task\n";
        std::cout <<"2. Show All Tasks\n";
        std::cout <<"3. Mark task as completed\n";
        std::cout <<"4. Mark task as incomplete\n";
        std::cout <<"5. exit\n";
        std::cin >>choice;
        switch (choice) {
            case 1: {
                std::string description;
                std::cout <<"\nEnter task description: \n";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(tasks,description);
                break;
            }
            case 2: {
                showAllTasks(tasks);
                break;
            }
            case 3: {
                if (tasks.empty()) {
                    std::cout <<"No tasks yet. Please add a task.\n" << std::endl;
                    break;
                }
                markTaskCompleted(tasks);
                
                break;
            }
            case 4: {
                if (tasks.empty()) {
                    std::cout <<"No tasks yet. Please add a task.\n" << std::endl;
                    break;
                }
                markTaskIncomplete(tasks);
                break;
            }
            case 5: {
                running = false;
                break;
            }
            default: {
                std::cout <<"Invalid choice. Please select one of the valid options (1 - 5)\n";
            }
        }
    }
    std::cout <<"Program has been closed" <<std::endl;

    return 0;
}
void showAllTasks(const std::vector<Task> &tasks) {
    if (tasks.empty()) {
        std::cout <<"No tasks yet." << std::endl;
    }
    else {
        for (size_t i = 0; i < tasks.size(); ++i){
            std::cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }
}
void addTask(std::vector<Task> &tasks, std::string description) {
    tasks.emplace_back(description);
}
void markTaskCompleted(std::vector<Task> &tasks) {
    int chosenTask = getValidIndex(tasks);
    tasks[chosenTask].markCompleted();
    showAllTasks(tasks);
}
void markTaskIncomplete(std::vector<Task> &tasks) {
    int chosenTask = getValidIndex(tasks);
    tasks[chosenTask].markIncomplete();
    showAllTasks(tasks);
}

int getValidIndex(const std::vector<Task> &tasks) {
    int choice;
    int taskSize = static_cast<int>(tasks.size());
    do {
        std::cout <<"\nPlease select a task number to apply the changes: \n";
        showAllTasks(tasks);
        std::cin >>choice;
        if (choice < 1 || choice > taskSize) {
            std::cout <<"Invalid/non-existent task was selected. "
                        "Please select a number indicating your chosen task.\n";
        }
    }
    while (choice < 1 || choice > taskSize);

    return choice - 1;
}
