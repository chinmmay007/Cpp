#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

class Student
{
public:
    int id;
    string name;
    int age;
    string course;

    Student(int id, string name, int age, string course)
        : id(id), name(name), age(age), course(course) {}
};

class StudentDatabase
{
private:
    vector<Student> students;

    int findStudentIndexById(int id)
    {
        for (size_t i = 0; i < students.size(); ++i)
        {
            if (students[i].id == id)
            {
                return i;
            }
        }
        return -1; // Not found
    }

public:
    void addStudent(int id, string name, int age, string course)
    {
        if (findStudentIndexById(id) != -1)
        {
            cout << "Student with ID " << id << " already exists.\n";
            return;
        }
        students.emplace_back(id, name, age, course);
        cout << "Student added successfully.\n";
    }

    void removeStudent(int id)
    {
        int index = findStudentIndexById(id);
        if (index != -1)
        {
            students.erase(students.begin() + index);
            cout << "Student removed successfully.\n";
        }
        else
        {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    void searchStudent(int id)
    {
        int index = findStudentIndexById(id);
        if (index != -1)
        {
            cout << "Student found: \n";
            // retreives data
            cout << "ID: " << students[index].id << "\n";
            cout << "Name: " << students[index].name << "\n";
            cout << "Age: " << students[index].age << "\n";
            cout << "Course: " << students[index].course << "\n";
        }
        else
        {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    void displayAllStudents()
    {
        if (students.empty())
        {
            cout << "No students in the database.\n";
            return;
        }
        for (const auto &student : students)
        {
            cout << "ID: " << student.id << "\n";
            cout << "Name: " << student.name << "\n";
            cout << "Age: " << student.age << "\n";
            cout << "Course: " << student.course << "\n";
            cout << "------------------------\n";
        }
    }
};

void clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    StudentDatabase db;
    int choice;

    while (true)
    {
        cout << "\nStudent Database Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear(); // Clearing the error flag
            clearInputBuffer();
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        clearInputBuffer();

        if (choice == 5)
            break;

        int id;
        string name;
        int age;
        string course;

        switch (choice)
        {
        case 1:
            cout << "Enter ID: ";
            if (!(cin >> id) || id <= 0)
            {
                cin.clear();
                clearInputBuffer();
                cout << "Invalid ID. Please enter a positive integer.\n";
                break;
            }
            clearInputBuffer();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Age: ";
            if (!(cin >> age) || age <= 0)
            {
                cin.clear();
                clearInputBuffer();
                cout << "Invalid age. Please enter a positive integer.\n";
                break;
            }
            clearInputBuffer();
            cout << "Enter Course: ";
            getline(cin, course);
            db.addStudent(id, name, age, course);
            break;

        case 2:
            cout << "Enter ID of student to remove: ";
            if (!(cin >> id) || id <= 0)
            {
                cin.clear();
                clearInputBuffer();
                cout << "Invalid ID. Please enter a positive integer.\n";
                break;
            }
            db.removeStudent(id);
            break;

        case 3:
            cout << "Enter ID of student to search: ";
            if (!(cin >> id) || id <= 0)
            {
                cin.clear();
                clearInputBuffer();
                cout << "Invalid ID. Please enter a positive integer.\n";
                break;
            }
            db.searchStudent(id);
            break;

        case 4:
            db.displayAllStudents();
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}