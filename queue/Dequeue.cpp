#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int t)
    {
        this->data = t;
        this->next = NULL;
        this->prev = NULL;
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
    void push_back(int t)
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
            y->prev = back;
            back = y;
        }
    }
    void push_front(int t)
    {
        Node *y = new Node(t);
        if (front == NULL)
        {
            front = y;
            back = y;
        }
        else
        {
            y->next=front;
            front->prev=y;
            front=y;
        }
    }
    void pop_front()
    {
        if (!front)
            return;
        Node *temp = front;
        front = front->next;
        front->prev=NULL;
        delete (temp);
    }
    void pop_back()
    {
        if (!front)
            return;
        Node *temp = back;
        back = back->prev;
        back->next=NULL;
        delete (temp);
    }
    int top()
    {
        if (front == NULL)
            return -1;
        return front->data;
    }
    int backs()
    {
        if (front == NULL)
            return -1;
        return back->data;
    }
    bool empty()
    {
        return front == NULL;
    }
};
int main()
{
    queue q1;

    // Test push_back and push_front
    q1.push_back(1);
    q1.push_back(2);
    q1.push_front(3);
    q1.push_front(4);

    // Test top and backs
    cout << "Front: " << q1.top() << endl;
    cout << "Back: " << q1.backs() << endl;

    // Test pop_front and pop_back
    q1.pop_front();
    q1.pop_back();

    // Test top after popping
    cout << "Front after popping: " << q1.top() << endl;

    // Test empty
    cout << "Is the queue empty? " << (q1.empty() ? "Yes" : "No") << endl;

    cout<<q1.backs()<<endl;

    return 0;
}