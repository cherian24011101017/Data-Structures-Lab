#include <iostream>

using namespace std;

class list{

    private:

        struct node{

            int data;
            node* next;
        };
        node* head;
        node** gethead(){

            return &head;
        }

    public:

        list(){

            head = nullptr;
        }

        void insertasc(int val){

            node* newnode = new node;
            newnode->data = val;
            newnode-> next = nullptr;
            if ((head == nullptr) || (head->data >= val)){

                newnode->next = head;
                head = newnode;
                return;
            }
            node* current = head;
            while ((current->next != nullptr) && (current->next->data < val)){

                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }

        void merge(list& list1, list& list2){

            node* p1 = *list1.gethead();
            node* p2 = *list2.gethead();
            head = nullptr;
            node** tail = &head;
            while ((p1 != nullptr) && (p2 != nullptr)){

                if (p1->data < p2->data){

                    *tail = new node;
                    (*tail)->data = p1->data;
                    (*tail)->next = nullptr;
                    p1 = p1->next;
                }
                else{

                    *tail = new node;
                    (*tail)->data = p2->data;
                    (*tail)->next = nullptr;
                    p2 = p2->next;
                }
                tail = &((*tail)->next);
            }
            if ((p1 == nullptr) && (p2 == nullptr)){

                cout << "\nLists are empty";
            }
            while (p1 != nullptr){

                *tail = new node;
                (*tail)->data = p1->data;
                (*tail)->next = nullptr;
                tail = &((*tail)->next);
                p1 = p1->next;
            }
            while (p2 != nullptr){

                *tail = new node;
                (*tail)->data = p2->data;
                (*tail)->next = nullptr;
                tail = &((*tail)->next);
                p2 = p2->next;
            }
        }

        void display(){

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
};