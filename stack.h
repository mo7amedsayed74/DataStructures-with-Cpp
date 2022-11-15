#include<iostream>
#pragma once
using namespace std;
const int max_size=100;
template<class t>
class Stack{
private:
    int top;
    t item[max_size];
public:
    Stack();
    void Push(t element);
    void Pop();
    t Top();
    void Pop(t &element);
    int size();
    bool Is_empty();
    void display();
};

template<class t>
Stack<t>::Stack(){top=-1;}
template<class t>
void Stack<t>:: Push(t element){
    if(top==max_size-1){cout<<"your stack is full\n";}
    else top++ , item[top]=element;
}
template<class t>
void Stack<t>::Pop(){
    if(top==-1){cout<<"ERROR! your stack is empty\n";}
    else top--;
}
template<class t>
t Stack<t>::Top(){return item[top];}
template<class t>
void Stack<t>::Pop(t & element){
    if(top==-1)cout<<"ERROR! your stack is empty\n";
    else element=item[top], top--;
}
template<class t>
int Stack<t>::size(){return top+1;}
template<class t>
bool Stack<t>::Is_empty(){return top==-1;}
template<class t>
void Stack<t>::display(){for(int i=top;i>=0;i--)cout<<item[top]<<" ",top--;}

// --------------------------

void copyS(Stack<int>s1,Stack<int>&s2) // function to copy two stack
{
    Stack<int>def;
    for(int i=s1.size()-1;i>=0;i--){
        def.Push(s1.Top());
        s1.Pop();
    }
    for(int i=def.size()-1;i>=0;i--){
        s2.Push(def.Top());
        def.Pop();
    }
}
