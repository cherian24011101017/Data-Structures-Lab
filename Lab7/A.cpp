//Queue ADT using an array that performs the functions Enqueue, Dequeue and Peek
#include <iostream>

using namespace std;

class queue{

    private:

        int arr[5];
        int size;
        
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
    
    size = 0;
}

//Enqueue a value into the back of the queue
void queue::enqueue(int val){

    if (size == 5){

        cout << "\nQueue Overflow\n";
    }
    else{

        arr[size] = val;
        size++;
    }
}

//Dequeue and return the value at the front of the queue
void queue::dequeue(){

    if (size == 0){

        cout << "\nQueue is empty\n";
    }
    else{

        cout << "\n" << arr[0] << "\n";
        for (int i = 0; i < (size - 1); i++){

            arr[i] = arr[i + 1];
        }
        size--;
    }
}

//Peek at the value at the front of the queue
void queue::peek(){

    if (size == 0){

        cout << "\nQueue is empty\n";
    }
    else{

        cout << "\n" << arr[0] << "\n";
    }
}
