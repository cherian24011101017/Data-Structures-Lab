// Program to implement stack using linkedlist 
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std ;

class Stack 
{
    private:
        struct Node
        {
            int data ;
            struct Node *next ; 
        }; 
        struct Node *top ;
    public:
        Stack() 
    { 
       top = NULL ;
    }
    void Push(int ele) ;
    void Pop() ;
    void Peek() ;

};

int main ()
{
   Stack stack ;
   int choice , ele ;
   do 
   {
    cout << "\n menu \n" ;
    cout << "1.Push\n" ;
    cout << "2.Pop\n" ;
    cout << "3.Peek \n" ;
    cout << "4.Exit\n" ;
    cout << "Enter your choice : " ;
    cin >> choice  ;
    switch(choice)
    {
        case 1:
            cout << "Enter character to push: ";
            cin >> ele;
            stack.Push(ele);
            break;
        case 2:
            stack.Pop();
            break;
        case 3:
            stack.Peek();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
    while(choice != 4) ;
    return 0;
}

// Function definitions 

// 1. Function to Push 
void Stack::Push(int ele) 
{  
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node)) ;
    newnode->data = ele ;
    newnode->next = top ;
    top = newnode ;
    cout << "pushed "<< ele << " into stack " ;
}

// 2. Function to Pop 

void Stack::Pop()
{ 
    if (top == nullptr) 
    {
        cout << "Stack Underflow! Nothing to pop.\n";
        return;
    }
   cout  << top->data <<" is popped" ;
   top = top->next;  
}

// 3. Function to Peek

void Stack::Peek()
{
    if (top == nullptr) 
    {
        cout << "Stack empty Nothing to pop.\n";
        return;
    }
    cout  << top->data  ;
}
