#include <iostream>
#include <string>
#include <map>
using namespace std;

string respond(const string &input)
{
    map<string, string> responses = {
        {"hello", "Hello! How are you?"},
        {"hi", "Heyya! How u doin?"},
        {"how are you", "I'm good, thanks!"},
        {"bye", "Goodbye!"},
        {"what is your name", "I'm Chinmmay's chatbot."}, // Add more responses here
    };

    auto response = responses.find(input);
    if (response != responses.end())
    {
        return response->second;
    }
    else
    {
        return "I didn't understand that.";
    }
}

int main()
{
    cout << "Chat with me! (type 'q' to exit)" << endl;
    while (true)
    {
        string input;
        getline(cin, input);
        if (input == "q")
        {
            break;
        }
        cout << respond(input) << endl;
    }

    return 0;
}
