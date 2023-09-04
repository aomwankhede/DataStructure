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
class dll
{
    Node *head;

public:
    dll()
    {
        head = NULL;
    }
    void push_front(int t)
    {
        Node *y = new Node(t);
        y->prev = NULL;
        y->next = head;
        head->prev = y;
        head = y;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        if (head != NULL)
            head->prev = NULL;
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
            y->prev = temp;
            y->next = NULL;
        }
        else
        {
            head = y;
            head->next = NULL;
            head->prev = NULL;
        }
    }
    void pop_back()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        Node *prevu = NULL;
        while (temp->next)
        {
            prevu = temp;
            temp = temp->next;
        }
        if (prevu)
        {
            prevu->next = NULL;
        }
        delete (temp);
    }
    void display()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        Node *prevu = NULL;
        while (temp)
        {
            prevu = temp;
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        while (prevu)
        {
            cout << prevu->data << " ";
            prevu = prevu->prev;
        }
    }
};
int main()
{
    dll l1;
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
    l1.pop_front();
    l1.pop_front();
    l1.pop_front();
    l1.pop_front();
    l1.pop_front();
    l1.display();
    return 0;
}