#include<iostream>
#pragma once
using namespace std;

template<class t>
struct node
{
    t value;
    node<t>* next=NULL;
};
template<class t>
class circular_linkedList{
    node<t> *head,*tail;
public:
    static int cnt;
    circular_linkedList():head(NULL){cnt++;}
    // insert first
    void insertFirst(t element){
        node<t>*newNode=new node<t>;
        newNode->value=element;
        if(head==NULL){
            head=newNode; tail=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
        tail->next=head;
    }
    // insert last
    void insertLast(t element){
        node<t>*newNode=new node<t>;
        newNode->value=element;
        if(head==NULL){
            head=newNode; tail=newNode;
            return;
        }
        newNode->next=head;
        tail->next=newNode;
        tail=newNode;
    }
    // insert position
    void insertPos(t element,int pos){
        node<t>*newNode=new node<t>;
        newNode->value=element;
        node<t>*cur=head,*pre;
        for(int i=1;i<pos;i++){
            pre=cur;
            cur=cur->next;
        }
        pre->next=newNode;
        newNode->next=cur;
    }
    
    // Display
    void display(){
        node<t>*tmp=head;
        if(tmp==NULL){cout<<"your list is empty\n"; return;}
        while(tmp!=tail){
            cout<<tmp->value<<" ";
            tmp=tmp->next;
        }
        cout<<tmp->value<<"\n";
    }
};
template<class t>
int circular_linkedList<t>::cnt=0;