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

int main() {
    std::vector<Task> tasks;
    tasks.emplace_back("Study C++");
    tasks.emplace_back("Get ready for going out");
    tasks.emplace_back("Clean the room");

    for (size_t i = 0; i < tasks.size(); ++i){
        std::cout << i + 1 << ". "; tasks[i].displayTask();
    }


    return 0;
}