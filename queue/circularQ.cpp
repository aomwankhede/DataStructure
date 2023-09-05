#include <iostream>
using namespace std;
class queue
{
    int *arr;
    int front;
    int back;
    bool is_empty;
    int cap=0;
public:
    queue(int n)
    {
        cap=n;
        // cout<<n<<endl;
        // arr = new int (n*sizeof(int));
        arr = new int[n]; //-->this is a good way o=to use array
        front = -1;
        back = -1;
        is_empty = true;
    }
    void push(int t)
    {
        if(front==-1){
            front=0;
        }
        back = (back + 1) % cap;
        if (back == front and front!=0)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            is_empty = false;
            arr[back] = t;
        }
    }
    void pop()
    {
        if (front == back)
        {
            is_empty = true;
        }
        front = (front + 1) % cap;
    }
    int top()
    {
        if (!is_empty)
        {
            return arr[front];
        }
        return -1;
    }
    bool empty()
    {
        return is_empty;
    }
};
int main()
{
   queue q(5);
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);
   q.push(5);
   q.pop();
   q.push(12);
   q.push(13);
   q.pop();
   q.pop();
   q.pop();
   cout<<q.empty()<<endl;
   q.pop();
   q.push(14);
   cout<<q.top()<<endl;
    return 0;
}