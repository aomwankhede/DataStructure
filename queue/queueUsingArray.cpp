#include <iostream>
using namespace std;
class queue{
    int *arr;
    int front;
    int back;
    public:
    queue(int n){
        // arr = new int (n*sizeof(int));
        arr = new int [n];   //-->this is a good way o=to use array
        front=-1;
        back=-1;
    }
    void push(int t){
        if(front==-1){
            front++;
            back++;
            if(back==sizeof(arr)){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                arr[back]=t;
            }
        }
        else{
            back++;
            if(back==sizeof(arr)){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                arr[back]=t;
            }
        }
    }
    void pop(){
        for(int i=front;i<=back-1;i++){
            arr[i]=arr[i+1];
        }
        if(front==back){
            front--;
        }
        back--;
    }
    int top(){
        if(front>=0){
        return arr[front];}
        return -1;
    }
    bool empty(){
        return front==-1;
    }
};
int main(){
    queue q1(5);
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
    cout<<q1.top()<<endl;
    return 0;
}