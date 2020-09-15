#include "Stack.h"


int CheckBalance(string expression)
{   
    Stack checkBraces;
    int i = 0;
    while(expression[i] != '\0')
    {
        
        if(expression[i] == '(')
        {
            checkBraces.push(expression[i]);
        }
        else if(expression[i] == ')')
        {
            checkBraces.pop();
        }
        else
        {}
        
        i++;
    }
    if(checkBraces.isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}