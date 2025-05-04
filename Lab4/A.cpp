#include <iostream>

using namespace std;

class list{

    private:

        struct node{

            int data;
            node* next;
        };
        node* head;
        void displayrevrecursive(node* node) {
            if (node == nullptr){

                return;
            }
            displayrevrecursive(node->next);
            cout << node->data << " -> ";
        }
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
        void displayrev();
        void reverselin();
};

int main(){

    list l;
    int choice = 0;
    int val;
    int pos;
    do{

        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Display Reverse\n10. Reverse Link\n11. Exit\nEnter 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 or 11: ";
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

                l.displayrev();
                break;
            case 10:

                l.reverselin();
                break;
        }
    } while (choice != 11);
}

list::list(){

    head = nullptr;
}

void list::insertbeg(int val){

    node* newnode = new node();
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void list::insertend(int val){

    if (head == nullptr){

        insertbeg(val);
    }
    else{

        node* newnode = new node();
        newnode->data = val;
        newnode->next = nullptr;
        node* temp = head;
        while (temp->next != nullptr){

            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void list::insertpos(int val, int pos){

    if (pos == 1){

        insertbeg(val);
    }
    else if (head != nullptr){

        node* temp = head;
        int ind = 0;
        while (temp->next != nullptr){

            ind++;
            temp = temp->next;
        }
        ind++;
        if ((pos > (ind + 1)) || (pos < 1)){

            cout << "\nInvalid position";
        }
        else if (pos == (ind + 1)){

            insertend(val);
        }
        else{

            int num = 1;
            temp = head;
            while (temp->next != nullptr){

                if ((num + 1) == pos){

                    node* newnode = new node();
                    newnode->data = val;
                    newnode->next = temp->next;
                    temp->next = newnode;
                    break;
                }
                num++;
                temp = temp->next;
            }
        }
    }
}

void list::deletebeg(){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{

        node* temp = head;
        head = temp->next;
    }
}

void list::deleteend(){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{

        node* temp = head;
        while (temp->next->next != nullptr){

            temp = temp->next;
        }
        temp->next = nullptr;
    }
}

void list::deletepos(int pos){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else if (pos == 1){

        deletebeg();
    }
    else{

        node* temp = head;
        int ind = 0;
        while (temp->next != nullptr){

            ind++;
            temp = temp->next;
        }
        ind++;
        if ((pos > ind) || (pos < 1)){

            cout << "\nInvalid position";
        }
        else if (pos == ind){

            deleteend();
        }
        else{

            int num = 1;
            temp = head;
            while (temp->next != nullptr){

                if ((num + 1) == pos){

                    temp->next = temp->next->next;
                    break;
                }
                num++;
                temp = temp->next;
            }
        }
    }
}

void list::search(int val){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{
        node* temp = head;
        int flag = 0;
        int pos = 1;
        while (temp->next != nullptr){

            if ((temp->data == val) && (pos != 1)){

                cout << "\nTarget was found at position " << pos;
                flag = 1;
            }
            pos++;
            temp = temp->next;
        }
        if (temp->data == val){

            cout << "\nTarget was found at position " << pos;
            flag = 1;
        }
        if (flag == 0){

            cout << "\nTarget was not found";
        }
    }
}

void list::display(){

    if (head == nullptr){

        cout << "\nList is empty";
    }
    else{
        node* temp = head;
        while (temp->next != nullptr){

            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << " -> NULL";
    }
}

void list::displayrev(){

    displayrevrecursive(head);
    cout << "NULL";
}

void list::reverselin(){

    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;
    while (curr != nullptr){

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
