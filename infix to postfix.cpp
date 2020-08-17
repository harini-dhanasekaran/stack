#include<iostream>
#include<cstring>
using namespace std;
class stack{
    private:
      int size;
      int top;
      char *s;
    public:
      stack(int size);
      ~stack();
      void push(char data);
      char pop();
      void infixtopost(string exp);
      int pre(char c);
      int isOpened(char c);
};
stack::stack(int size){
    this->size=size;
    this->top =-1;
    this->s=new char[this->size];
}
stack::~stack(){
    delete [] this->s;
}

void stack::push(char c){
    if(this->top==this->size-1)
        cout<<"stack overflow";
      
    else{
        this->top++;
        this->s[this->top]=c;
    }
      
}


char stack::pop(){
    char temp='z';
    if(this->top<0)
      cout<<"stack underflow";
    else{
        temp=this->s[top];
        this->top--;
        
    }
    return temp;
}
void stack::infixtopost(string exp){
    int size=exp.length();
    char* postfix=new char[size+1];
    int i=0,j=0;
    size++;
    while(exp[i]!=NULL){
        if(isOpened(exp[i])){
            postfix[j++]=exp[i++];
        }
        else{
            if(pre(exp[i])>pre(s[top]) && top>=0)
               push(exp[i++]);
             else
                postfix[j++]=pop();
        }
    }
    while(s[top]!='#'){
         postfix[j++]=pop();
    }
    postfix[j++]='0';
    for(int i=0;postfix[i]!='0';i++)
      cout<<postfix[i];
    
}
int stack::isOpened(char exp){
    if(exp=='+' || exp=='-' || exp=='*' || exp=='/')
      return 0;
    else
      return 1;  
}

int stack::pre(char exp){
    if(exp=='+' || exp=='-')
      return 1;
    else if(exp=='*' || exp=='/')
      return 2;
    else
      return 0;
}

int main(){
    string exp="a+b*c+d";
    int size=exp.length();
    stack stk(size);
    stk.~stack();
    stack stack(size);
    stk.push('#');
    stk.infixtopost(exp);
    return 0;
}