// Program to check the String Balance 
#include <iostream>
#include "stackll.h"  

using namespace std;

int main() {
    int choice;
    string exp;
    do {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                cin >> exp;
                if (isBalanced(exp)) 
                {
                    cout << "Balanced" << endl;
                } 
                else 
                {
                    cout << "Not Balanced" << endl;
                }
                break;
            case 2:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 2);
    return 0;
}

// Function to check paranthesis 

bool isBalanced(string exp) {
    Stack s;
    for (char ch : exp) {
        if (ch == '(') {
            s.Push(ch);
        } else if (ch == ')') {
            if (s.isEmpty()) {
                return false;  
            }
            s.Pop();
        }
    }
    return s.isEmpty();  
}
