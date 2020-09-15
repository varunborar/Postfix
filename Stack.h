#include <iostream>

using namespace std;

struct Node
{
    char data;
    struct Node *next;
};

class Stack
{
    struct Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(char x);
    char pop();
    char peek();
    bool isEmpty();
    void clearStack();

    ~Stack()
    {
        clearStack();
    }
};

bool Stack ::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

void Stack ::push(char x)
{
    struct Node *newNode = new Node;
    newNode->data = x;

    if (isEmpty())
    {
        newNode->next = NULL;
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

char Stack ::pop()
{
    char val;
    struct Node *temp = top;
    if (isEmpty())
    {
        return '!';
    }
    else if (temp->next == NULL)
    {
        top = NULL;
        val = temp->data;
        delete temp;
    }
    else
    {
        top = top->next;
        val = temp->data;
        delete temp;
    }
    return val;
}

char Stack ::peek()
{
    if (isEmpty())
    {
        return '!';
    }
    else
    {
        return top->data;
    }
}

void Stack ::clearStack()
{
    struct Node *temp = top;
    while (top)
    {
        top = top->next;
        delete temp;
        temp = top;
    }
}
