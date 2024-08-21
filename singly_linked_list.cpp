#include <iostream>

class Node
{
public:
    int data;
    int key;
    Node *next;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class SinglyLinkList
{
public:
    Node *head;
    SinglyLinkList()
    {
        head = NULL;
    }
    SinglyLinkList(Node *n)
    {
        head = n;
    }
    Node * nodeExists(int k){

    }
};
using namespace std;
int main()
{
    Node(1, 2);
    return 0;
}