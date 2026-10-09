#include <iostream>
using namespace std;

class Stack
{
    int S[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }
    bool isfull()
    {
        if (top == 9)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int x)
    {
        if (isfull())
        {
            cout << "stack is full , cannot add element , overflow" << endl;
        }
        else
        {
            S[++top] = x;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty , no element to display" << endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << S[i] << " ";
            }
            cout << endl;
        }
    }
    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty  ";
            return INT_MIN;
        }
        else
        {
            return S[top];
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "no element to pop" << endl;
            return INT_MIN;
        }
        else
        {
            return S[top--];
        }
    }
};

int main()
{
    Stack s1;
    s1.push(6);
    s1.push(7);
    s1.push(66);
    s1.push(77);
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    cout << s1.Top();
    return 0;
}