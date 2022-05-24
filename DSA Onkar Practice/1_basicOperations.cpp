#include <iostream>
using namespace std;

int main()
{
    int choice;
    int num1, num2, x;

    // Choice selection

    cout << "\nPlease enter your choice:"
            "\n1 = Addition"
            "\n2 = Subtraction"
            "\n3 = Multiplication"
            "\n4 = division"
            "\n5 = Exit"
            "\n\nChoice:- ";
    cin >> choice;

    // Validation

    while (choice < 1 || choice > 4)
    {
        cout << "\nPlease enter valid choice!"
                "\nReenter your valid choice:- ";
        cin >> choice;
    }

    // Switch cases :-

    switch (choice) // Switch case for choice
    {
    case 1:
        cout << "Enter two numbers\n";
        cin >> num1 >> num2;
        x = num1 + num2;
        cout << "Addition :- " << x;
        break;

    case 2:
        cout << "Enter two numbers\n";
        cin >> num1 >> num2;
        x = num1 - num2;
        cout << "Subtraction :- " << x;
        break;

    case 3:
        cout << "Enter two numbers\n";
        cin >> num1 >> num2;
        x = num1 * num2;
        cout << "Multiplication :- " << x;
        break;

    case 4:
        cout << "Enter Dividend and Divisor\n";
        cin >> num1 >> num2;

        // Condition
        while (num2 == 0)
        {
            cout << "\nDivisor cannot be zero."
                    "\nReEnter divisor once again: ";
            cin >> num2;
        }
        x = num1 / num2;
        cout << "Division :- " << x;
        break;

    case 5:
        return;

    default:
        cout << "\nError!";
    }

    return 0;
};