#include <iostream>
// #include "Stack.h"
#include "Braces.h"
#include <string.h>

#define valid true
#define invalid false

using namespace std;


class PostFix
{
    Stack stack;
    string inpExpression;
    char outExpression[30];
    int outStringLength = 0;

public:
    PostFix()
    {
    }
    ~PostFix()
    {
    }

    void getExpression(string exp)
    {
        inpExpression = '(' + exp + ')';
    }
    bool checkInpExpression();
    int precedence(char C);
    void convertExpression();
    void postfixExp()
    {for (int i = 0; i < outStringLength; i++)
        cout << outExpression[i];
    }
    string Exp()
    {return inpExpression;}
};

bool PostFix ::checkInpExpression()
{
    if (CheckBalance(inpExpression) == 1)
    {
        return valid;
    }
    else
    {
        return invalid;
    }
}

int PostFix ::precedence(char C)
{
    switch (C)
    {
    case '+':
        [[__fallthrough]];
    case '-':
        return 1;
    case '*':
        [[__fallthrough]];
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void PostFix ::convertExpression()
{   
    
    for (int i = 0; i < inpExpression.length(); i++)
    {
        //cout << char(inpExpression[i]);

        if (char(inpExpression[i]) == '(')
        {
            stack.push(char(inpExpression[i]));
        }
        else if (char(inpExpression[i]) == '+'||char(inpExpression[i]) == '-'||char(inpExpression[i]) == '/'||char(inpExpression[i]) == '*'||char(inpExpression[i]) == '^')
        {
            while (precedence(stack.peek())>= precedence(char(inpExpression[i])))
            {
                outExpression[outStringLength++] = char(stack.pop());
                if(char(stack.peek()) == '(')
                {
                    break;
                }
            }
            stack.push(char(inpExpression[i]));
        }   
        else if(isalpha(char(inpExpression[i])))
        {
            outExpression[outStringLength++] = char(inpExpression[i]);
        }
        else if (char(inpExpression[i]) == ')')
        {
            while (char(stack.peek()) != '(')
            {
                outExpression[outStringLength++] = char(stack.pop());
            }
            stack.pop();
        }
       
    }
    //cout << stack.peek();
    //cout << "\n" << outExpression;
}

int main()
{
    PostFix P1;
    string expression;
    cout << "\nEnter the expression :";
    cin >> expression;
    P1.getExpression(expression);
    
    if(P1.checkInpExpression() == 1)
    {
        P1.convertExpression();
        P1.postfixExp();
        cout << endl;
    }
    else
    {
        cout << "\nInvalid Expression";
    }
    system("pause");
    
    return 0;
}
