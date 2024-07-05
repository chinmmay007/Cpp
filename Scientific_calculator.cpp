#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char operation;
    double n1, n2;

    cout << "Enter operator (+, -, *, /, ^, sqrt(s), sin(i), cos(c), tan(t), log(l)): ";
    cin >> operation;

    switch (operation)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        cout << "Enter two operands: ";
        cin >> n1 >> n2;
        switch (operation)
        {
        case '+':
            cout << n1 << " + " << n2 << " = " << n1 + n2;
            break;
        case '-':
            cout << n1 << " - " << n2 << " = " << n1 - n2;
            break;
        case '*':
            cout << n1 << " * " << n2 << " = " << n1 * n2;
            break;
        case '/':
            if (n2 == 0)
            {
                cout << "Error! Division by zero.";
            }
            else
            {
                cout << n1 << " / " << n2 << " = " << n1 / n2;
            }
            break;
        }
        break;

    case '^':
        cout << "Enter base and exponent: ";
        cin >> n1 >> n2;
        cout << n1 << " ^ " << n2 << " = " << pow(n1, n2);
        break;

    case 's':
        cout << "Enter number: ";
        cin >> n1;
        cout << "sqrt(" << n1 << ") = " << sqrt(n1);
        break;

    case 'i':
        cout << "Enter angle in degrees: ";
        cin >> n1;
        cout << "sin(" << n1 << ") = " << sin(n1 * M_PI / 180.0);
        break;

    case 'c':
        cout << "Enter angle in degrees: ";
        cin >> n1;
        cout << "cos(" << n1 << ") = " << cos(n1 * M_PI / 180.0);
        break;

    case 't':
        cout << "Enter angle in degrees: ";
        cin >> n1;
        cout << "tan(" << n1 << ") = " << tan(n1 * M_PI / 180.0);
        break;

    case 'l':
        cout << "Enter number: ";
        cin >> n1;
        cout << "log(" << n1 << ") = " << log10(n1);
        break;

    default:
        cout << "Error! Invalid operator.";
        break;
    }

    return 0;
}
