#include <iostream>
#include <string>
using namespace std;

struct Task
{
    string description;
    bool completed;
};

void addTask(Task *&tasks, int &count, const std::string &description)
{
    Task *newTasks = new Task[count + 1];
    for (int i = 0; i < count; ++i)
    {
        newTasks[i] = tasks[i];
    }
    newTasks[count].description = description;
    newTasks[count].completed = false;
    delete[] tasks;
    tasks = newTasks;
    ++count;
}

void displayTasks(Task *tasks, int count)
{
    for (int i = 0; i < count; ++i)
    {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Not Completed") << "]\n";
    }
}

void markTaskCompleted(Task *tasks, int count)
{
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= count)
        tasks[taskNumber - 1].completed = true;
    else
        cout << "Invalid task number.\n";
}

int main()
{
    Task *tasks = nullptr;
    int taskCount = 0;

    while (true)
    {
        cout << "Enter a task (or 'Q/q' to exit): ";
        string input;
        getline(cin, input);

        if (input == "q" || input == "Q")
        {
            break;
        }

        addTask(tasks, taskCount, input);
    }

    while (true)
    {
        cout << "\nTasks:\n";
        displayTasks(tasks, taskCount);

        cout << "Enter 'c' to mark a task as completed or 'e' to quit: ";
        string cmd;
        getline(cin, cmd);

        if (cmd == "e" || cmd == "E")
        {
            break;
        }
        else if (cmd == "c")
        {
            markTaskCompleted(tasks, taskCount);
        }
        else
        {
            cout << "Unknown command.\n";
        }
    }

    delete[] tasks;
    return 0;
}
