// In this code we implemented stack
// here we implemented stack with basic operation like push,pop,size,top

#include<iostream>
using namespace std;

class stack{
    public:
    int* arr;
    int top;
    int size;
    // constructor
    stack(int size){
        this->size=size;
        this->top=-1;
        arr=new int[size];
    }

    void push(int element){
        if(top==size){
            cout<<"Overflow insertion not possible";
        }
        else{
            top=top+1;
            arr[top]=element;
        }
    }
    void pop(){
        if(top<0){
            cout<<"underflow deletion not possible";
        }
        else{
            top--;
        }
    }
    void peek(){
        if(top>=0){
          cout<<arr[top];
            
        }
        else{
            cout<<"underflow no element present";
        }
        
    }
    bool isempty(){
        if(top==-1){
            cout<<"true";
        }
        else{
            cout<<"false";
        }
    }
    
};

int main(){
    stack stk(5);
    stk.push(4);
    stk.push(3);
    stk.peek();
    cout<<endl;
    stk.isempty();
    cout<<endl;
    stk.pop();
    stk.peek();
    cout<<endl;
    stk.isempty();
    cout<<endl;
    stk.pop();
    stk.peek();
    cout<<endl;
    stk.isempty();
    cout<<endl;
    return 0;
}
// output is
//   3
// false
// 4
// false
// underflow no element present
// true