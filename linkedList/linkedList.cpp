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
class ll
{
    Node *head;

public:
    ll()
    {
        head = NULL;
    }
    void push_front(int t)
    {
        Node *y = new Node(t);
        y->next = head;
        head = y;
    }
    void pop_front()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        delete (temp);
    }
    void push_back(int t)
    {
        Node *y = new Node(t);
        Node *temp = head;
        while (temp != NULL and temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp)
        {
            temp->next = y;
        }
        else
        {
            head = y;
        }
    }
    void pop_back()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev)
        {
            prev->next = NULL;
        }
        delete (temp);
    }
    void display()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    ll l1;
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(8);
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(9);
    l1.pop_back();
    l1.pop_back();
    l1.pop_back();
    l1.pop_back();
    l1.pop_back();
    l1.pop_back();
    l1.pop_back();
    l1.pop_back();
    l1.pop_back();
    l1.pop_back();
    l1.display();
    return 0;
}