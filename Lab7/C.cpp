//Queue ADT using a Singly Linked List that performs the functions Enqueue, Dequeue and Peek
#include <iostream>

using namespace std;

class queue{

    private:

        struct node{

            int data;
            node* next;
        };
        node* head;
        node* tail;
        
    public:

        queue();

        void enqueue(int);

        void dequeue();

        void peek();
};

int main(){

    queue q1;
    int choice = 0;
    int val;
    do {

        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter 1, 2, 3 or 4: ";
        cin >> choice;
        switch (choice){

            case 1:

                cout << "\nEnter the number to be inserted at the back of the queue: ";
                cin >> val;
                q1.enqueue(val);
                break;
            case 2:

                q1.dequeue();
                break;
            case 3:

                q1.peek();
                break;
            case 4:

                break;
            default:

                cout << "\nEnter a valid choice\n";
        }
    } while (choice != 4);
}

//Constructor
queue::queue(){
    
    head = nullptr;
    tail = nullptr;
}

//Enqueue a value into the back of the queue
void queue::enqueue(int val){

    node* newnode = new node;
    newnode->data = val;
    newnode->next = nullptr;
    if (tail != nullptr){

        tail->next = newnode;
    }
    if (head == nullptr){

        head = newnode;
    }
    tail = newnode;
}

//Dequeue and return the value at the front of the queue
void queue::dequeue(){

    if (head == nullptr){

        cout << "\nQueue is empty\n";
    }
    else if (head->next == nullptr){

        cout << "\n" << head->data << "\n";
        head = nullptr;
        tail = nullptr;
    }
    else{

        cout << "\n" << head->data << "\n";
        head = head->next;
    }
}

//Peek at the value at the front of the queue
void queue::peek(){

    if (head == nullptr){

        cout << "\nQueue is empty\n";
    }
    else{

        cout << "\n" << head->data << "\n";
    }
}