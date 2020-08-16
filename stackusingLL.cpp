#include <iostream>
using namespace std;
class node{
    public:
      int data;
      node* next;
};
class stack{
    private:
      node* top;
    public:
      stack();
      ~stack();
      void push(int data);
      void displayStack();
      int pop();
      int peek(int index);
};
stack::stack(){
    top=NULL;
}
stack::~stack(){
    node* p=top;
    while(top){
        top=top->next;
        delete p;
        p=top;
    }
}
int stack::pop(){
    int data;
    node* p=top;
    top=top->next;
    data=p->data;
    delete p;
    return data;

}
int stack::peek(int index){
    index--;
    node* p=top;
    while(index--){
        p=p->next;
    }
    return p->data;
}
void stack::displayStack(){
    node* p=top;
    while(p){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL";
}
void stack::push(int data){
    node* temp=new node;
    if(temp==NULL){
        cout<<"stack overload";
    }
    else{
        temp->data=data;
        temp->next=top;
        top=temp;
    }
}
int main() {
    stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.displayStack();
    cout<<endl;
    cout<<stk.pop();
    cout<<endl;
    stk.displayStack();
    cout<<endl;
    cout<<stk.peek(1)<<" "<<stk.peek(2)<<" "<<stk.peek(3);
    return 0;
}