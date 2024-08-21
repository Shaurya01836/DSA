#include <iostream>
using namespace std;
class stack
{
public:
    int top;
    int arr[5];

    stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;

        else
            return false;
    }
 
    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow " << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
};

int main()
{
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout << s1.arr[2];
    return 0;
}