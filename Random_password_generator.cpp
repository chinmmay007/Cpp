// Random Password Generator :

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;

string generatePassword()
{
    string characters;
    for (char c = 'a'; c <= 'z'; ++c)
        characters += c;
    for (char c = 'A'; c <= 'Z'; ++c)
        characters += c;
    for (char c = '0'; c <= '9'; ++c)
        characters += c;
    string symbols = "!@#$%&*";

    srand(static_cast<unsigned>(time(0)));

    string password;
    password += symbols[rand() % symbols.length()];

    for (int i = 1; i < 8; i++)
    {
        password += characters[rand() % characters.length()];
    }

    random_shuffle(password.begin(), password.end());

    return password;
}

int main()
{
    cout << "Generated password: " << generatePassword() << endl;
    return 0;
}
