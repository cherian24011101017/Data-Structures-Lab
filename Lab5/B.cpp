//List ADT using Circular Linked List that performs the functions Insert Beginning, Insert End, Insert Position, Delete Beginning, Delete End, Delete Position, Search and Display
#include <iostream>

using namespace std;

class list{

    private:

        struct node{

            int data;
            node* next;
        };
        node* head;

    public:

        list();

        void insertbeg(int);

        void insertend(int);

        void insertpos(int, int);

        void deletebeg();

        void deleteend();

        void deletepos(int);

        void search(int);

        void display();
};

int main(){

    list l;
    int choice = 0;
    int val;
    int pos;
    do{

        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Exit\nEnter 1, 2, 3, 4, 5, 6, 7, 8 or 9: ";
        cin >> choice;
        switch (choice){

            case 1:

                cout << "\nEnter the number to be inserted at the beginning: ";
                cin >> val;
                l.insertbeg(val);
                break;
            case 2:

                cout << "\nEnter the number to be inserted at the end: ";
                cin >> val;
                l.insertend(val);
                break;
            case 3:

                cout << "\nEnter the number to be inserted: ";
                cin >> val;
                cout << "\nEnter the position the number should be inserted in: ";
                cin >> pos;
                l.insertpos(val, pos);
                break;
            case 4:

                l.deletebeg();
                break;
            case 5:

                l.deleteend();
                break;
            case 6:

                cout << "\nEnter the position to be deleted: ";
                cin >> pos;
                l.deletepos(pos);
                break;
            case 7:

                cout << "\nEnter the number to search for: ";
                cin >> val;
                l.search(val);
                break;
            case 8:

                l.display();
                break;
            case 9:

                break;
            default:

                cout << "\nEnter a valid choice";
        }
    } while (choice != 9);
}

//Constructor
list::list(){

    head = nullptr;
}

//Insert a value at the beginning of the circular linked list
void list::insertbeg(int val){

    node* newnode = new node;
    newnode->data = val;
    if (head == nullptr){

        head = newnode;
        newnode->next = head;
    }
    else{

        node* temp = head;
        while (temp->next != head){

            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

//Insert a value at the end of the circular linked list
void list::insertend(int val){

    node* newnode = new node;
    newnode->data = val;
    newnode->next = head;
    if (head == nullptr){

        head = newnode;
        newnode->next = head;
    }
    else{

        node* temp = head;
        while(temp->next != head){

            temp = temp->next;
        }
        temp->next = newnode;
    }
}

//Insert a value at any desired position in the circular linked list
void list::insertpos(int val, int pos){

    node* newnode = new node;
    newnode->data = val;
    newnode->next = nullptr;
    if (head == nullptr){

        head = newnode;
        newnode->next = head;
        return;
    }
    if (pos == 1){

        insertbeg(val);
        return;
    }
    node* temp = head;
    int count = 1;
    while ((temp->next != head) && (count < (pos - 1))) {

        temp = temp->next;
        count++;
    }
    if (count != (pos - 1)){

        cout << "\nInvalid position";
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

//Delete the value at the beginning of the circular linked list
void list::deletebeg(){

    if (head == nullptr){

        cout << "\nList is empty";
        return;
    }
    if (head->next == head){

        head = nullptr;
    }
    else{

        node* last = head;

        while (last->next != head){

            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
}

//Delete the value at the end of the circular linked list
void list::deleteend(){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{

        node *temp = head;
        while (temp->next->next != head){

            temp = temp->next;
        }
        temp->next = head;
        if (head->next == head){

            head = nullptr;
        }
    }
}

//Delete the value at any desired position in the circular linked list
void list::deletepos(int pos){

    if (head == nullptr){

        cout << "\nList is empty";
        return;
    }
    if (pos < 1){

        cout << "\nInvalid Position";
        return;
    }
    if (pos == 1){

        deletebeg();
        return;
    }
    node* temp = head;
    int count = 1;
    while ((temp->next != head) && (count < (pos - 1))) {

        temp = temp->next;
        count++;
    }
    if ((pos - 1) > count){

        cout << "\nInvalid position";
        return;
    }
    temp->next = temp->next->next;
}

//Search and return the index of any desired value in the circular linked list
void list::search(int val){

    if (head == nullptr){

        cout << "\nList is empty";
        return;
    }

    node* temp = head;
    int position = 1;
    do{

        if (temp->data == val){

            cout << "\nTarget was found at position " << position;
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    cout << "\nTarget was not found";
}

//Display all the values in the circular linked list
void list::display(){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{

        node* temp = head;
        do{

            cout << temp->data <<" -> ";
            temp = temp->next;
        } while (temp != head);
    }
}