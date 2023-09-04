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
public:
    Node *head;
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
class stack{
    ll l;
    public:
    void push(int t){
        l.push_front(t);
    }
    void pop(){
        if(l.head==NULL){cout<<"Stack Undeflow"<<endl;return;}
        l.pop_front();
    }
    int top(){
        if(l.head==NULL)return 5000;
        return l.head->data;
    }
    bool empty(){
        return (l.head==NULL);
    }
};
int main(){
    stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}