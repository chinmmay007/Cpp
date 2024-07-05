#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string computerChoice()
{
    string choices[] = {"rock", "paper", "scissors"};
    int index = rand() % 3;
    return choices[index];
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    string userChoice;
    cout << "Enter your choice (rock, paper, or scissors): ";
    cin >> userChoice;

    string computer = computerChoice();
    cout << "Computer chose: " << computer << endl;

    if (userChoice == computer)
    {
        cout << "It's a tie!" << endl;
    }
    else if ((userChoice == "r" && computer == "scissors") ||
             (userChoice == "p" && computer == "rock") ||
             (userChoice == "s" && computer == "paper"))
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "Computer wins!" << endl;
    }

    return 0;
}
