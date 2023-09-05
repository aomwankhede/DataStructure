#include <iostream>
using namespace std;
class stack{
    int *arr;
    int top1;
    int top2;
    public:
    stack(int n){
        arr=new int (n*sizeof(int));
        top1=-1;
        top2=n;
    }
    bool empty1(int t){
        return top1==-1;
    }
    bool empty2(int t){
        return top2==sizeof(arr);
    }
    void push1(int t){
        top1++;
        if(top1==top2){
            top1--;
            cout<<"Stack overflow"<<endl;
        }
        else{
            arr[top1]=t;
        }
    }
    void push2(int t){
        top2--;
        if(top1==top2){
            top2++;
            cout<<"Stack overflow"<<endl;
        }
        else{
            arr[top2]=t;
        }
    }
    void pop1(){
        if(top1<0){
            cout<<"Stack underflow"<<endl;
        }
        else{
            top1--;
        }
    }
    void pop2(){
        if(top2==sizeof(arr)){
            cout<<"Stack underflow"<<endl;
        }
        else{
            top2++;
        }
    }
    int tops1(){
        if(top1>=0 || top1< sizeof(arr)){
            return arr[top1];
        }
        return -1;
    }
    int tops2(){
        if(top2>=0 || top2< sizeof(arr)){
            return arr[top2];
        }
        return -1;
    }
};
int main(){
    stack s1(10);
    s1.push1(16);
    s1.push1(15);
    s1.push1(14);
    s1.push1(13);
    s1.push1(12);
    s1.push2(56);
    s1.push2(57);
    s1.push2(58);
    s1.push2(59);
    s1.push2(60);
    s1.pop1();
    s1.pop1();
    s1.pop1();
    s1.pop2();
    s1.pop2();
    s1.pop2();
    s1.pop2();
    cout<<s1.tops1()<<endl;
    cout<<s1.tops2()<<endl;
    return 0;
}