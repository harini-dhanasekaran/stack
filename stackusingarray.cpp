#include <iostream>
using namespace std;
class stack{
    private:
      int size;
      int top;
      int *s;
    public:
      stack(int size);
      ~stack();
      void push(int data);
      void displayStack();
      int pop();
      int peek(int index);
};
stack::stack(int size){
    this->size=size;
    this->top =-1;
    this->s=new int[this->size];
}
stack::~stack(){
    delete [] this->s;
}
void stack::push(int data){
    if(this->top==this->size-1)
       cout <<"stack overflow";
    else
    {
       this->top++;
       this->s[this->top]=data;
    }
    
}

void stack::displayStack(){
    int topDup=this->top;
    while(topDup>=0){
        cout<<s[topDup]<<" ";
        topDup--;
    }
}

int stack::pop(){
    int x=1;
    if(this->top<0)
       cout<<"stack underflow";
    else
    {
        x=this->s[top];
        this->top--;
    }
    return x;
}

int stack::peek(int index){
    int x;
    if(index>=size || index<0)
      cout<<"invalid index";
    else{
        x=this->s[index];
    }
    return x;
}
int main(){
    int size;
    cout<<"enter the size of the stack";
    cin>>size;
    stack stk(size);
    stk.push(5);
    stk.push(10);
    stk.push(15);
    stk.push(20);
    stk.displayStack();
    cout<<endl;
    cout<<stk.pop();
    cout<<endl;
    stk.displayStack();
    cout<<endl;
    cout<<stk.peek(2);
    return 0;
}