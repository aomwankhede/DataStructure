#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int t)
    {
        this->data = t;
        this->next = NULL;
    }
};

class queue
{
    Node *front;
    Node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int t)
    {
        Node *y = new Node(t);
        if (front == NULL)
        {
            front = y;
            back = y;
        }
        else
        {
            back->next = y;
            back = y;
        }
    }
    void pop()
    {
        if (!front)
            return;
        Node *temp = front;
        front = front->next;
        delete (temp);
    }
    int top()
    {
        if (front == NULL)
            return -1;
        return front->data;
    }
    bool empty()
    {
        return front == NULL;
    }
};
int main()
{
    queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.push(8);
    q1.push(9);
    cout << q1.top() << endl;
    return 0;
}