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
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
           push(exp[i]);
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(top>=0){
                char text;
                text=pop();
                if((text==40 && exp[i]==41) || (text==91 && exp[i]==93) || (text==123 && exp[i]==125))
                    continue;
                else
                    return 0;
                
            }
            else 
              return 0;
        }
    }
    if(top<0)
      return 1;
}
int main() {
    string exp="{[(a*b)*(c*d)]*x}";
    // all brackets are detected
    int size=exp.length();
    stack stk(size);
    cout<<stk.isequal(exp);
    return 0;
}