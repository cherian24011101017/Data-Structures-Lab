#include <iostream>

using namespace std;

class Process{

    private:

        int t = 0;
        int quantum=3;
        int process_counter = 0;   

        struct Node{

            int process_id;
            int bt;
            int rem_bt;
            int wt;
            struct Node *next;
        } *head, *tail;

    public:

        Process();

        void insert(int);

        void execute();

        void display();

};

Process::Process(){

    head = NULL;
}

void Process::insert(int bt){

    Node* newProcess = new Node; 
    newProcess->bt = bt;
    newProcess->rem_bt = bt;  
    newProcess->wt = 0;
    newProcess->process_id = ++process_counter;
    newProcess->next = NULL;

    if (head == NULL){

        head = tail = newProcess;
        newProcess->next = head;
    }
    else{

        tail->next = newProcess;
        newProcess->next = head;
        tail = newProcess;
    }

}

void Process::execute(){

    if (head == NULL){

        cout << "\nNo processes";
        cout << "\nTotal Execution Time: " << t;
        return;
    }
    Node *temp = head;
    int id = temp->process_id;
    if (temp->rem_bt > quantum){

            t += quantum;
            temp->rem_bt -= quantum;
            head = head->next;
            tail->next = temp;
            temp->next = head;
            tail = temp;
    }
    else{

        t = t + temp->rem_bt;
        temp->wt = t - temp->bt;
        temp->rem_bt = 0;
        if (head->next == head){

            delete temp;
            head = tail = NULL;
        }
        else{

            Node* last = head;
            while (last->next != head){

                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete temp;
        }
    }
}

int Process::display(){

    if (!head){

        cout << "\nNo processes";
        return;
    }
    Node *temp = head;
    do{

        cout << "\nProcess ID:" << temp->process_id;
        cout << "\nBurst Time: " << temp->bt;
        cout << "\nRemaining Time: " << temp->rem_bt;
        temp = temp->next;
    } while(temp != head);
}