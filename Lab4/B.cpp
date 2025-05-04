#include <iostream>
#include "B.h"

using namespace std;

int main(){

    list list1, list2, list3;
    int choice, val;
    do{

        cout << "\n1. Insert List1\n2. Insert List2\n3. Merge Into List3\n4. Display\n5. Exit\nEnter 1, 2, 3, 4 or 5: ";
        cin >> choice;
        switch (choice){

        case 1:

            cout << "\nEnter the value to be inserted into List1: ";
            cin >> val;
            list1.insertasc(val);
            break;
        case 2:

            cout << "\nEnter the value to be inserted into List2: ";
            cin >> val;
            list2.insertasc(val);
            break;
        case 3:

            list3.merge(list1, list2);
            break;
        case 4:

            cout << "\nList1: ";
            list1.display();
            cout << "\nList2: ";
            list2.display();
            cout << "\nList3: ";
            list3.display();
            break;
        case 5:

            break;
        }
    } while (choice != 5);
}