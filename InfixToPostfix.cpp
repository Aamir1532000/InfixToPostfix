#include<bits/stdc++.h>
using namespace std;
template <class Type>
class Node{
public:
    Type data;
    Node* next;
};

template <class Type>
class Stack{
private:
    Node<Type>* top;
public:
    Stack();
    ~Stack();
    void push(Type x);
    Type pop();
    Type peek(int index);
    int isEmpty();
    int isFull();
    Type stackTop();
    bool isBalance(Type* exp);
};

template <class Type>
bool Stack<Type>::isBalance(Type* exp){
int i;
Type x;
for(i=0;exp[i]!='\0';i++){
    if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        push(exp[i]);
    else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
        if(isEmpty())return false;
        x=pop();
        if((exp[i]-x==1||exp[i]-x==2))
           continue;
        else
            return false;

    }
}
return (isEmpty())?true:false;
}

template <class Type>
Stack<Type>::Stack(){

top=nullptr;
}

template <class Type>
Stack<Type>::~Stack(){
Node<Type>* p=top;
while(top){

    top=top->next;
    delete p;
    p=top;

}
}

template <class Type>
void Stack<Type>::push(Type x){
    Node<Type>* t=new Node<Type>;
    if(t==nullptr)
        cout<<"stack overflow";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }

}

template <class Type>
Type Stack<Type>::pop(){
Node<Type>* p;
Type x=-1;
if(top==nullptr){
    cout<<"stack underflow";

}
else{
    p=top;
    x=p->data;
    top=top->next;
    delete p;

}
return x;

}

template <class Type>
int Stack<Type>::isFull(){

Node<Type>* t=new Node<Type>;
int r=t?0:1;
delete t;
return r;

}
template <class Type>
int Stack<Type>::isEmpty(){
return top?0:1;

}

template <class Type>
Type Stack<Type>::stackTop(){
if(top){
    return top->data;

}
return -1;
}

template <class Type>
Type Stack<Type>::peek(int index){
    if(isEmpty()){
        return -1;

    }
        else
        {
            Node<Type>* p=top;

            for(int i=0;p!=nullptr&&i<index-1;i++)
                p=p->next;
            if(p!=nullptr){
                return p->data;
            }
            else
            {
                return -1;
            }

        }
}

int pre(char x){
if(x=='+'||x=='-')
return 1;
else if(x=='*'||x=='/')
    return 2;
return 0;

}
int isOperand(char x){
if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
else
    return 1;
}
char* convert(char* infix){
Stack<char> st;
char* postfix=new char[strlen(infix)+1];
int i=0,j=0;
while(infix[i]!='\0'){
    if(isOperand(infix[i]))
        postfix[j++]=infix[i++];
    else{
        if(pre(infix[i])>pre(st.stackTop()))
            st.push(infix[i++]);
        else
            postfix[j++]=st.pop();
    }

}
while(!st.isEmpty()){

    postfix[j++]=st.pop();
}
postfix[j]='\0';
return postfix;


}
int main(){
char infix[100];
cin>>infix;
char* x=convert(infix);
for (int i=0;x[i]!='\0';i++)
    cout<<x[i];
}
