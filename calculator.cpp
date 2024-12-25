//this is an app for a simple calculator

#include <iostream>
using namespace std;

int main() {
    char op;
    double num1, num2;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;//input variable

    switch (op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;//for addition
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;//for subtraction
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;//for multiplication
            break;
        case '/':
            if (num2 != 0)
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;//for division
            else
                cout << "Error: Division by zero!" << endl;//can't divide by zero
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
    }

    return 0;
}


//lets run it