#include<iostream>
#pragma once
using namespace std;

template<class t>
struct node
{
    t data;
    node<t>* next=NULL,*pre=NULL;
};

template<class t>
class double_linkedList{
    node<t>*head,*tail;
public:
    double_linkedList():head(NULL),tail(NULL){}
    void insertFirst(t ele){
        node<t>*newNode=new node<t>;
        newNode->next=NULL;
        newNode->pre=NULL;
        newNode->data=ele;
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        node<t>*tmp=head;
        tmp->pre=newNode;
        newNode->next=tmp;
        newNode->pre=NULL;
        head=newNode;
    }
    void insertPos(int pos,t ele){
        node<t>*newNode=new node<t>;
        newNode->next=NULL;
        newNode->pre=NULL;
        newNode->data=ele;
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        node<t>*cur=head,*per=NULL;
        for(int i=1;i<pos;i++){  // 1 2 3 4
            per=cur;
            cur=cur->next;
        }
        per->next=newNode;
        newNode->pre=per;
        cur->pre=newNode;
        newNode->next=cur;
    }
    void insertLast(t ele){
        node<t>*newNode=new node<t>;
        newNode->next=NULL;
        newNode->pre=NULL;
        newNode->data=ele;
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        node<t>*cur=head;
        while(cur!=tail){
            cur=cur->next;
        }
        cur->next=newNode;
        newNode->pre=cur;
        newNode->next=NULL;
        tail=newNode;
    }
    void deleteFirst(){
        if(head==NULL){
            cout<<"your list is empty\n";
            return;
        }
        node<t>*tmp=head;
        tmp->next->pre=NULL;
        head=tmp->next;
        delete tmp;
    }
    void deletePos(int pos){
        if(head==NULL){
            cout<<"your list is empty\n";
            return;
        }
        node<t>*cur=head,*pre=NULL;

        for(int i=1;i<pos;i++){ // 1 2 3 4
            pre=cur;
            cur=cur->next;
        }
        //  لو عايز امسح ال 3
        pre->next=pre->next->next;
        /*
           pre           اللي هيا 2
           pre->next     بتشاور على 3
           pre->next->next  هتكون بتشاور على ال 4

            ف انا كدا خليت ال next بتاع ال 2 بيشاور على ال 4 بدل م كان بيشاور على 3
         */
        pre->next->next->pre = pre;
        /*
            pre->next->next  دي ال 4 زي م اتفقنا
            هخلي ال pre بتاعها يشاور على ال 2
         */
        delete cur;
    }
    void deleteLast(){
        if(head==NULL){
            cout<<"your list is empty\n";
            return;
        }
        node<t>*cur=head,*pre=NULL;
        while(cur!=tail){
            pre=cur;
            cur=cur->next;
        }
        pre->next=NULL;
        tail=pre;
        delete cur;
    }

    void showStart(){
        node<t>*tmp=head;
        cout<<tmp->data<<'\n';
    }
    void showLast(){
        node<t>*tmp=tail;
        cout<<tmp->data<<'\n';
    }

    int count(){
        node<t>*tmp=head;
        int cnt=1;
        while(tmp!=tail){
            cnt++;
            tmp=tmp->next;
        }
        return cnt;
    }
    void startIndex(){
        if(head==NULL){
            cout<<"your list is empty\n";
            return ;
        }
        cout<<"0\n";
    }
    void lastIndex(){
        int ind=0;
        if(head==NULL){
            cout<<"your list is empty\n";
            return ;
        }
        ind=count()-1;
        cout<<ind<<'\n';
        /*
           (OR)
        node<t>*tmp=head;
        while(tmp!=tail){
            ind++;
            tmp=tmp->next;
        }
        cout<<ind<<"\n";
         */
    }

    void display(){
        node<t>*tmp=head;
        while(tmp!=tail){
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<tmp->data<<'\n';
    }
};

/*
int main()
{
        double_linkedList<int>x;
    for(int i=0;i<=6;i++){
        x.insertFirst(i);
    }
    x.display();
    cout<<"items count : "<<x.count()<<'\n';
    for(int i=0;i<=6;i++){
        x.insertLast(i);
    }
    x.display();
    cout<<"items count : "<<x.count()<<'\n';
    x.deleteFirst();
    x.display();
    cout<<"items count : "<<x.count()<<'\n';
    x.deleteFirst();
    x.display();
    cout<<"items count : "<<x.count()<<'\n';
    x.insertPos(10,25);
    x.display();
    cout<<"items count : "<<x.count()<<'\n';
    x.deleteLast();
    x.display();
    cout<<"items count : "<<x.count()<<'\n';
    x.deletePos(6);
    x.display();
    cout<<"items count : "<<x.count()<<'\n';

    cout<<"\n\n\n";
    cout<<"start index :  ";
    x.startIndex();
    cout<<"last index :   ";
    x.lastIndex();

    cout<<"show start :  ";
    x.showStart();
    cout<<"show last :  ";
    x.showLast();

}
 */