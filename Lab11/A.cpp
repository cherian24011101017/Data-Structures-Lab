//Hash ADT using an array that performs the functions Insert, Delete, Search and Display
#include <iostream>

using namespace std;

class hash1{

    private:

        int arr[10];
        
    public:

        hash1();

        int hashfn(int);

        void insert(int);

        void del(int);

        void search(int);

        void display();
};

int main(){

    hash1 h1;
    int choice = 0;
    int val;
    do {

        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n\nEnter 1, 2, 3, 4 or 5: ";
        cin >> choice;
        switch (choice){

            case 1:

                cout << "\nEnter the number to be inserted into the hash table: ";
                cin >> val;
                h1.insert(val);
                break;
            case 2:

                cout << "\nEnter the number to be deleted from the hash table: ";
                cin >> val;
                h1.del(val);
                break;
            case 3:

                cout << "\nEnter the number whose position is to be found in the hash table: ";
                cin >> val;
                h1.search(val);
                break;
            case 4:

                h1.display();
                break;
            case 5:

                break;
            default:

                cout << "\nEnter a valid choice";
        }
    } while (choice != 5);
}

//Constructor
hash1::hash1(){
    
    for (int i = 0; i < 10; i++){

        arr[i] = -1;
    }
}

//Hash Function
int hash1::hashfn(int val){

    return (val % 10);
}

//Insert a value into the hash table
void hash1::insert(int val){

    int flag = 0;
    for (int i = hashfn(val); i < 10; i++){

        if (arr[i] == -1){

            arr[i] = val;
            flag = 1;
            break;
        }
    }
    if (flag == 0){

        for (int j = 0; j < hashfn(val); j++){

            if (arr[j] == -1){

                arr[j] = val;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0){

        cout << "\nThe hash table is full\n";
    }
}

//Delete a value from the hash table
void hash1::del(int val){

    int flag = 0;
    for (int i = hashfn(val); i < 10; i++){

        if (arr[i] == val){

            arr[i] = -1;
            flag = 1;
            break;
        }
    }
    if (flag == 0){

        for (int j = 0; j < hashfn(val); j++){

            if (arr[j] == val){

                arr[j] = -1;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0){

        cout << "\n" << val << " was not found in the hash table\n";
    }
}

//Search for a value in the hash table
void hash1::search(int val){

    int flag = 0;
    for (int i = hashfn(val); i < 10; i++){

        if (arr[i] == val){

            flag = 1;
            cout << "\n" << val << " was found at position " << (i + 1) << "\n";
            break;
        }
    }
    if (flag == 0){

        for (int j = 0; j < hashfn(val); j++){

            if (arr[j] == val){

                flag = 1;
                cout << "\n" << val << " was found at position " << (j + 1) << "\n";
                break;
            }
        }
    }
    if (flag == 0){

        cout << "\n" << val << " was not found in the hash table\n";
    }
}

//Display the hash table
void hash1::display(){

    for (int i = 0; i < 10; i++){

        if (arr[i] == -1){

            cout << "\n" << (i + 1) << " -> EMPTY";
        }
        else{

            cout << "\n" << (i + 1) << " -> " << arr[i];
        }
    }
    cout << "\n";
}
