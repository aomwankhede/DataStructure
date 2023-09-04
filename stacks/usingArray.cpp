#include <iostream>
#define INT_MAX 50000;
using namespace std;
class stack{
    int topu;
    int *arr;
    public:
    stack(int n){
        topu=-1;
        arr = new int (n*sizeof(int));
    }
    void push(int t){
        topu++;
        if(topu>=sizeof(arr)){
            cout<<"Stack overflow"<<endl;
        }
        else{
            arr[topu]=t;
        }
    }
    void pop(){
        if(topu<0){
            cout<<"Stack underflow"<<endl;
            return;
        }
        topu--;
    }
    int top(){
        if(topu<0||topu>sizeof(arr))return INT_MAX;
        return arr[topu];
    }
    bool empty(){
        return topu==-1;
    }
    int size(){
        return topu+1;
    }
};
int main(){
    stack s(5);
    s.push(4);
    s.push(6);
    s.push(7);
    s.push(9);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}