#include<iostream>
#include<cstring>
using namespace std;


//stack implemented using array

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
//parameterized constructer

stack::stack(int size){
    this->size=size;
    this->top =-1;
    this->s=new char[this->size];
}

// destructor
stack::~stack(){
    delete [] this->s;
}

// various function of stack class

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
// converts of infix to postfix
void stack::infixtopost(string exp){
    int size=exp.length();
    char* postfix=new char[size+1];    // new char array is created to store the result
    int i=0,j=0;
    size++;
    while(exp[i]!=NULL){
        if(isOpened(exp[i])){           // if operand directly add to postfix array
            postfix[j++]=exp[i++];
        }
        else{
            if(pre(exp[i])>pre(s[top]) && top>=0)          // check precedence 
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

// checks if passed char is (alphabet)operand or operator
int stack::isOpened(char exp){
    if(exp=='+' || exp=='-' || exp=='*' || exp=='/')
      return 0;
    else
      return 1;  
}

//checks the precedence of the passed operator

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
    stack stk(size);// line can be negleted
    stk.~stack();  // line can be negleted
    stack stack(size);
    stk.push('#');
    stk.infixtopost(exp);
    return 0;
}
