#include<iostream>
#pragma once
using namespace std;
const int MAX=10;
template<class t>
class CircularQueue{
private:
    int front,rear;
    t arr[MAX];
public:
    CircularQueue():front(-1),rear(-1){}
    bool is_full(){return (front==0&&rear==MAX-1)||(front=rear+1);}
    bool is_empty(){return front==-1&&rear==-1;}
    void insert(t element){
        if(is_full()){cout<<"overflow"; return;}
        if(front==-1)front++,rear++; // empty
        else{
            if(rear==MAX-1)rear=0;
            else rear++;
        }
        arr[rear]=element;
    }
    void remove(){
        if(is_empty()){
            cout<<"queue underflow";
            return;
        }
        else if (front==rear)front=-1,rear=-1;
        else {
            if(front==MAX-1)front=0;
            else front++;
        }
    }
    void display();
};
template<class t>
void CircularQueue<t>::display(){
    if(front ==-1){cout<<"queue is empty"; return;}
    int front_pos=front,rear_pos=rear;

    if(front_pos > rear){
        while(front_pos<=MAX-1){
            cout<<arr[front_pos]<<" ";
            front_pos++;
        }
        front_pos=0;
    }
    while(front_pos<=rear_pos){
        cout<<arr[front_pos]<<" ";
        front_pos++;
    }
}
