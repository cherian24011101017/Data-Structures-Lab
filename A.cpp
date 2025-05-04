// Program to implement Stack ADT 
#include<cstdio>
#include<cstdlib>
using namespace std ;

#define size 5 

class Stack
{
    private :
          
        int arr[size] ;
        int top ;

    public :
              
        Stack() 
        {
           top = 0 ;
        }
        void Push(int ele) ;
        void Pop() ;
        void Peek() ; 
        
} ;

int main () 
{
   Stack stack ;
   int choice , ele ;

   do 
   {
    printf("\n    menu    \n") ;
    printf("1.Push \n") ;
    printf("2.Pop \n") ;
    printf("3.Peek \n") ;
    printf("4.Exit \n") ;
    printf("Enter your choice : ");
    scanf("%d", &choice ) ;
    switch(choice)
    {
       case 1 :
       printf("Enter element : ") ;
       scanf("%d", &ele ) ;
       stack.Push(ele) ;
       break ;
       case 2 :
       stack.Pop() ;
       break ;
       case 3 :
       stack.Peek() ;
       break ;
       case 4 :
       printf("Exiting the program") ;
       break ;
    }
   }
   while(choice != 4) ;
   return 0 ;
}

// Function Definitions 

// 1. Function to Push 

void Stack :: Push(int ele) 
{
   if(top == size -1 )
   {
      printf("Stack underflow") ;
   }
   arr[++top] = ele ;
   printf("The element %d is pushed ", ele ) ; 
}

// 2. Function to Pop

void Stack :: Pop() 
{
   if(top == -1)
   {
      printf("Stack overflow") ;
   }
   printf("Popped ele is %d ", arr[top--]) ;

}

// 3. Function to Peek 

void Stack :: Peek() 
{
   if(top == -1) 
   {
    printf("stack overflow") ;
   }
   printf("Top element is %d ", arr[top]) ;
}

