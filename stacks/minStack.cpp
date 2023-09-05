#include <iostream>
#include <stack>
using namespace std;
class specialStack{
    stack<int>s;
    stack<int>ms;
    public:
    void push(int t){
        if(s.empty()){
            ms.push(t);
            s.push(t);
        }
        else{
            if(t<=ms.top()){
                ms.push(t);
            }
            s.push(t);
        }
    }
    void pop(){
        if(s.empty())return;
        if(s.top()==ms.top()){
            s.pop();
            ms.pop();
        }
        else{
            s.pop();
        }
    }
    int top(){
        if(s.empty())return -1;
        return s.top();
    }
    int mini(){
        if(s.empty())return -1;
        return ms.top();
    }
};
int main(){
    specialStack s1;
    s1.push(4);
    s1.push(5);
    s1.push(3);
    s1.push(2);
    s1.push(2);
    s1.push(0);
    s1.pop();
    s1.pop();
    cout<<s1.mini()<<endl;
    return 0;
}