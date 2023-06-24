#include<iostream>
#pragma once
using namespace std;
const int size=100;
template<class t>
class Queue{
private:
    int front,rear;
    t arr[size];
public:
    Queue():front(-1),rear(-1){}
    bool is_empty(){return front==-1&&rear==-1;}
    bool is_full(){return front==0&&rear==size-1;}
    void insert(t element){
        if(is_full()){
            cout<<"queue overflow";
            return;
        }
        if(front==-1)front=0;
        arr[++rear]=element;
    }
    void remove(){
        if(is_empty()){
            cout<<"queue underflow";
            return;
        }
        else if (front==rear)front=-1,rear=-1;
        else front++;
    }
    t getFront(){
        assert(!is_empty()); // if queue is empty , this function stop the program and give me the line number of error
        return arr[front];
    }
    t getRear(){
        assert(!is_empty()); // if queue is empty , this function stop the program and give me the line number of error
        return arr[rear];
    }
    void display(){
        if(is_empty()){
            cout<<"stack is empty";
            return;
        }
        for(int i=front;i<=rear;i++)cout<<arr[i]<<" ";
        cout<<"\n";
    }
};
