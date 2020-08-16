#include<iostream>
#include<cstring>
using namespace std;
class stack{
    private:
      int size;
      int top;
      char *s;  //since we are using letters i.e char
    public:
      stack(int size);
      ~stack();
      void push(int data);
      void displayStack();
      int pop();
      int isequal(string exp);
};
stack::stack(int size){
    this->size=size;
    this->top =-1;
    this->s=new char[this->size];
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

int stack::isequal(string exp){
    for(int i=0;i!='0';i++){
        if(exp[i]=='(')
           push('(');
        else if(exp[i]==')'){
            if(top>=0)
              pop();
            else 
              return 0;
        }
    }
    if(top<0)
      return 1;
}
int main() {
    string exp="(a*b)*(c*d))";
    // case 1 (a*b))  case 2 ((a*b) case 3 (a*b)
    int size=exp.length();
    stack stk(size);
    cout<<stk.isequal(exp);
    return 0;
}