// Main Menu of RR schedule
#include <iostream>
#include "robin.h"

using namespace std;

int main(){

    Process process;
    int option, time;
    do{

        cout << "\n1.Insert\n2.Execute\n3.Display\n4.Exit\nEnter 1, 2, 3 or 4: ";
        cin >> option;
        switch (option){

            case 1:

                cout << "\nEnter the process time: ";
                cin >> time;
                process.insert(time);
                break;
            case 2:

                process.execute();
                break;
            case 3:

                process.display();
                break;
            default:

                cout << "\nInvalid Input";
        }
    } while (option != 4);
}