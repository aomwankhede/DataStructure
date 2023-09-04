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
class cll
{
    Node *head;

public:
    cll()
    {
        head = NULL;
    }
    void push_front(int t)
    {
        Node *y = new Node(t);
        if (head == NULL)
        {
            head = y;
            head->next = head;
        }
        else
        {
            y->next = head;
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = y;
            head = y;
        }
    }
    void pop_back()
    {
        Node *prev = NULL;
        Node *temp = head;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete (temp);
    }
    void push_back(int t)
    {
        Node *y = new Node(t);
        if (head == NULL)
        {
            head = y;
            head->next = head;
        }
        else
        {
            y->next = head;
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = y;
        }
    }
    void pop_front()
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        Node *t = head;
        head = head->next;
        delete (t);
    }
    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout<<endl;
        cout<<"Is circular proof:-"<<(temp==head);
        cout << endl;
    }
};
int main()
{
    cll l1;
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(8);
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(9);
    // l1.pop_back();
    // l1.pop_back();
    // l1.pop_back();
    // l1.pop_front();
    // l1.pop_front();
    // l1.pop_front();
    // l1.pop_front();
    // l1.pop_front();
    // l1.pop_front();
    l1.display();
    return 0;
}