//List ADT using Doubly Linked List that performs the functions Insert Beginning, Insert End, Insert Position, Delete Beginning, Delete End, Delete Position, Search and Display
#include <iostream>

using namespace std;

class list{

    private:

        struct node{

            int data;
            node* next;
            node* prev;
        };
        node* head;
        node* tail;

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
    tail = nullptr;
}

//Insert a value at the beginning of the doubly linked list
void list::insertbeg(int val){

    node* newnode = new node;
    newnode->data = val;
    newnode->next = head;
    newnode->prev = nullptr;
    if (head == nullptr){

        head = newnode;
        tail = newnode;
    }
    else{

        head = newnode;
        (newnode->next)->prev = newnode;
    }

}

//Insert a value at the end of the doubly linked list
void list::insertend(int val){

    node* newnode = new node;
    newnode->data = val;
    newnode->next = nullptr;
    newnode->prev = tail;
    if (tail == nullptr){

        head = newnode;
        tail = newnode;
    }
    else{

        tail = newnode;
        (newnode->prev)->next = newnode;
    }
}

//Insert a value at any desired position in the doubly linked list
void list::insertpos(int val, int pos){

    if (head == nullptr){

        if (pos != 1){

            cout << "\nInvalid Position";
        }
        else{

            insertbeg(val);
        }
    }
    else{

        node* temp = head;
        int size = 0;
        while (temp != nullptr){

            temp = temp->next;
            size++;
        }
        if ((pos <1) || (pos > size + 1)){

            cout << "\nInvalid Position";
        }
        else if (pos == 1){

            insertbeg(val);
        }
        else if (pos == size + 1){

            insertend(val);
        }
        else{

            temp = head;
            int flag = 1;
            while (flag < pos){

                temp = temp->next;
                flag++;
            }
            node* newnode = new node;
            newnode->data = val;
            newnode->next = temp;
            newnode->prev = temp->prev;
            (temp->prev)->next = newnode;
            temp->prev = newnode;
        }
    }
}

//Delete the value at the beginning of the doubly linked list
void list::deletebeg(){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{

        if (head->next == nullptr){

            head = nullptr;
            tail = nullptr;
        }
        else{

            head = head->next;
            head->prev = nullptr;
        }
    }
}

//Delete the value at the end of the doubly linked list
void list::deleteend(){

    if (tail == nullptr){

        cout << "\nList is empty";
    }
    else{

        if (tail->prev == nullptr){

            head = nullptr;
            tail = nullptr;
        }
        else{

            tail = tail->prev;
            tail->next = nullptr;
        }
    }
}

//Delete the value at any desired position in the doubly linked list
void list::deletepos(int pos){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{

        node* temp = head;
        int size = 0;
        while (temp != nullptr){

            temp = temp->next;
            size++;
        }
        if ((pos <1) || (pos > size)){

            cout << "\nInvalid Position";
        }
        else if (pos == 1){

            deletebeg();
        }
        else if (pos == size){

            deleteend();
        }
        else{

            temp = head;
            int flag = 1;
            while (flag < pos){

                temp = temp->next;
                flag++;
            }
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
        }
    }
}

//Search and return the index of any desired value in the doubly linked list
void list::search(int val){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{
        node* temp = head;
        int ind = 1;
        int flag = 0;
        while (temp != nullptr){

            if (temp->data == val){

                cout << "\nTarget was found at position " << ind;
                flag = 1;
            }
            temp = temp->next;
            ind++;
        }
        if (flag == 0){

            cout << "\nTarget was not found in the list";
        }
    }
}

//Display all the values in the doubly linked list
void list::display(){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{

        cout << "\nHead to Tail";
        node* temp1 = head;
        cout << "\nNULL <- ";
        while (temp1 != nullptr){

            if (temp1->next == nullptr){

                cout << temp1->data << " -> ";
                temp1 = temp1->next;
            }
            else{

                cout << temp1->data << " -> <- ";
                temp1 = temp1->next;
            }
        }
        cout << "NULL";
        cout << "\nTail to Head";
        node* temp2 = tail;
        cout << "\nNULL <- ";
        while (temp2 != nullptr){

            if (temp2->prev == nullptr){

                cout << temp2->data << " -> ";
                temp2 = temp2->prev;
            }
            else{

                cout << temp2->data << " -> <- ";
                temp2 = temp2->prev;
            }
        }
        cout << "NULL";
    }
}
