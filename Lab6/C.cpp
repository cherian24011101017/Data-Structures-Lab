//Program to implement infix and postfix 
#include <cstdio>
#include <cstdlib>
#include <iostream> 
#include "stackll.h" 

using namespace std ;

class Fix 
{
    private :
       string infixExp ;
       string postfixExp ;
       
    public : 
       Fix()
       {
           infixExp = "" ;
           postfixExp = "" ;
       } 
       void Infix() ;
       void Postfix() ;
       void Evaluate() ;

};

int main() 
{
    Fix fix ;
    int choice ;
    do
    {
        cout << "\n   menu    \n" ;
        cout << "1.Infix\n" ;
        cout << "2.Prefix\n" ;
        cout << "3.Evaluate\n" ;
        cout << "4.Exit\n" ;
        cout << "Enter your choice : " ;
        cin >> choice ;
        switch(choice)
        {
            case 1 : 
            fix.Infix() ;
            break ;
            case 2 :
            fix.Postfix() ;
            break ;
            case 3 :
            fix.Evaluate() ;
            break ;
            case 4 : 
            cout << "Exiting the program" ;
            break ;
        }
    } while (choice != 4);
    
}

//Function Definitions 

// 1. To check operarators 

bool isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=');
}

// Precedence order 

int precedence(char op)
{   
    if ( op == '+' || op == '-') return 1 ;
    if ( op == '*' || op == '/') return 2 ;
    if ( op == '=') return 0 ;
    return 0 ;
}

// Function converting Infix to postfix 

string InfixToPostfix (const string& infix)
{
    Stack s ;
    string postfix, num = "";

    for (size_t i = 0; i < infix.length(); i++) 
    {
        char ch = infix[i];

        
        if (isdigit(ch)) {
            while (i < infix.length() && isdigit(infix[i])) {
                num += infix[i++];
            }
            postfix += num + " "; 
            num = "";  
            i--;  
        }
        else if (ch =='(') 
        {
            s.Push(ch) ;
        }
        else if (ch == ')') 
        {
            while( !s.isEmpty() && s.Peek() != '(')
            {
                postfix += s.Pop();
            }
            s.Pop() ;
        }
        else if (isOperator(ch))  
        {   
            while( !s.isEmpty() && precedence(s.Peek()) >= precedence(ch))
            {
                postfix += s.Pop();
            }
            s.Push(ch) ;
        }
    }   
        while(!s.isEmpty())
        {
            postfix += s.Pop() ;
        } 

        return postfix ;
    
}

// Function Evaluating the converted Postfix Expression 

double EvaluatePostfix (const string& postfix)
{
    Stack s ;
    string num = "";

    for (size_t i = 0; i < postfix.length(); i++) 
    {
        char ch = postfix[i];

        if (isdigit(ch))  
        {
            while (i < postfix.length() && (isdigit(postfix[i]) || postfix[i] == '.'))
            {
                num += postfix[i++];
            }
            s.Push(stod(num));  
            num = "";  
            i--;  
        }
        else if(isOperator(ch))
        {
            double b = s.Pop() ;
            double a = s.Pop() ;
            switch(ch)
            {
                case '+': s.Push(a + b); break;
                case '-': s.Push(a - b); break;
                case '*': s.Push(a * b); break;
                case '/':  
                if (b == 0) 
                {
                    cout << "Error: Division by zero\n";
                    return 0;
                }
                s.Push(a / b); 
                break;
            }

        }
    }
    return s.Pop() ;
}

// 1. Function to Get Infix Expression 

void Fix :: Infix()
{
    cout << "Enter your expression : " ;
    cin >> infixExp ;
}

// 2. Function to convert Infix to Postfix 

void Fix :: Postfix()
{  
    if(infixExp.empty())
    {
        cout << "Error: No infix expression stored!\n";
        return;
    } 
    postfixExp = InfixToPostfix(infixExp);
    cout << "Postfix Expression: " << postfixExp << endl;
}

// 3. Function to Evaluate 

void Fix :: Evaluate()
{
    if(postfixExp.empty())
    {
        cout << "Error: No postfix expression !\n";
        return;
    } 
    cout << "Evaluation result :" << EvaluatePostfix(postfixExp) << endl;
}

