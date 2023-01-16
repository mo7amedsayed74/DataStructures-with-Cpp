//linked list
#include<iostream>
using namespace std;
#define ll long long
struct node{
    int value;
    node *next;
};
class linked_list{
    node *head;
public:
    linked_list(){
        head=NULL;
    }
    void create_node(int data){
        node *new_node = new node;
        new_node->next=NULL;
        new_node->value=data;
        head=new_node;
    }
    void insert_front(int data){
        if(head==NULL){
            create_node(data);
            return;
        }
        node *new_node = new node;
        new_node->value=data;
        new_node->next=head;
        head=new_node;
    }

    void insert_back(int data){
        if(head==NULL){
            create_node(data);
            return;
        }
        node *new_node = new node;
        node *temp = new node;
        new_node->value=data;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=NULL;
    }
    void insert_pos(int data,int pos){
        node *new_node = new node;
        new_node->value=data;
        node *cur = new node;
        node *pre = new node;
        cur=head;
        for(int i=0;i<pos-1;i++){
            pre=cur;
            cur=cur->next;
        }
        pre->next=new_node;
        new_node->next=cur;
    }
    void delete_front(){
        node *temp = new node;
        temp=head;
        head=head->next;
        delete temp;
    }
    void delete_back(){
        node *cur = new node;
        node *pre = new node;
        cur=head;
        while(cur->next!=NULL){
            pre=cur;
            cur=cur->next;
        }
        pre->next=NULL;
        delete cur;
    }
    void delete_pos(int pos){
        node *cur = new node;
        node *pre = new node;
        cur=head;
        for(int i=0;i<pos-1;i++){
            pre=cur;
            cur=cur->next;
        }
        pre->next=cur->next;
        delete cur;
    }
    void sort_LinkedList()
    {
        node *p, *q;
        int temp;
        for (p = head; p->next != NULL; p = p->next)
        {
            for (q = p; q != NULL; q = q->next)
            {
                if (p->value > q->value)
                {
                    temp = p->value;
                    p->value = q->value;
                    q->value = temp;
                }
            }
        }
    }

    void display(){
        node *temp = new node;
        temp = head;
        while (temp != NULL) {
            cout <<temp->value<<" ";
            temp = temp->next;
        }
        cout<<'\n';
    }
};


/*
int main() {
    linked_list x;
        x.insert_front(5);
        x.insert_front(6);
        x.insert_front(7);
        x.display();
        x.insert_pos(10, 2);
        x.display();
        x.delete_back();
        x.delete_front();
        x.display();
        x.insert_pos(11, 2);
        x.display();
        x.delete_pos(2);
        x.display();
}
 */