//  {<<{ another way }>>}  ( https://ideone.com/BvOLzv )

#include<iostream>
#pragma once
using namespace std;

template<class t>
struct node
{
    t data;
    node<t>* next=NULL;
};

template<class t>
class linked_list
{
private:
    node<t>*head;
public:
    linked_list():head(NULL){}
    node<t>*create_node();
    void free_node(node<t> *p);
    void add_first(int val);
    void add_last(int val);
    int remove_first();
    int remove_last();
    void AddAfter(int val,int pos);
    void Del(int data);
    int count();
    int Search(int data);
    void reverse();
    void Display_list();
};

template<class t>
node<t>* linked_list<t>::create_node(){
    node<t> *p;
    p=new node<t>;
    return p; // address
}
template<class t>
void linked_list<t>::free_node (node<t> *p){delete (p);}
template<class t>
void linked_list<t>::add_first(int val) {
    node<t> *p;
    p = create_node();
    p->data = val;
    if (head == NULL) {
        p->next = NULL;
        head = p;
        return;
    }
    p->next = head;
    head = p;
}
template<class t>
void linked_list<t>::add_last(int val)
{
    node<t> *p=create_node();
    p->data=val;
    p->next=NULL;
    if(head==NULL){ head=p; return; }
    node<t>*q=head;
    while(q->next!=NULL)
        q=q->next;
    q->next=p;
}
template<class t>
void linked_list<t>::AddAfter(int val,int pos) {
    node<t> *p, *q;
    q = head;
//Finding the position to add new element to the linked list
    for (int i = 0; i < pos - 1; i++) {
        q = q->next;
        if (q == NULL) {
            cout << "There are less than "<<pos<<"elements\n";
            return;
        }//end if
    } //End of for
    p = create_node();
    p->data = val;
    p->next = q->next;
    q->next = p;
}
template<class t>
void linked_list<t>::Del(int dat)
{
    node<t> *p=head;
    if (p->data == dat) // First element deleted
    {
        head=head->next;
        free_node(p);
        return;
    } // Element deleted in between
    node<t> *q=head, *k;
    while(q->data != dat){ k=q; q=q->next; }
    if (q->next == NULL && q->data != dat){ cout<<"The element does not exist on the List\n"; return; }
    k->next=q->next;
    free_node(q);
}
template<class t>
int linked_list<t>::remove_first(){
    int val;
    node<t> *p =head;
    if(head==NULL) return -1;
    if(p->next==NULL){
        val=p->data;
        free_node(head);
        head=NULL;
        return val;
    }
    head=p->next;
    val=p->data;
    free_node(p);
    return val;
}
template<class t>
int linked_list<t>::remove_last(){
    int val;
    if(head==NULL) return -1;
    node<t> *q=head;
    if(q->next==NULL){
        val=q->data;
        free_node(head);
        head=NULL;
        return val;
    }
    node<t> *k;
    while(q->next!=NULL){ k=q;  q=q->next; }
    val=q->data;
    free_node(q);
    k->next=NULL;
    return val;
}
template<class t>
void linked_list<t>::Display_list(){
    node<t> *q=head;
    if (head == NULL){ cout<<"List is empty\n"; return; }
    cout<<"The elements of the list are: ";
    while (q->next != NULL){ cout<<q->data<<" ";  q=q->next; } // end while
    cout<<q->data<<" ";
}
template<class t>
int linked_list<t>::count(){  // count the number of nodes
    node<t> *q=head;
    int cnt=0;
    while(q!=NULL){ q=q->next;  cnt++; }
    return cnt;
}
template<class t>
int linked_list<t>::Search(int dat)
{
    node<t> *p=head;
    int pos=0;
    while(p->next != NULL){
        if (p->data == dat)
            pos++;
        p=p->next;
    }
    if (p==NULL)
        return -1;
    return pos;
}
template<class t>
void linked_list<t>::reverse()
{
    node<t>* current_node = head;
    node<t>* prev_node = NULL;
    node<t>* next_node = NULL;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    head = prev_node;
}


/*

//  {<<{ another way }>>}

template<class t>
struct node
{
    t data;
    node<t>* next=NULL;
};

template<class t>
 class linked_list {
private:
    node<t>* head=new node<t>;
    int size;
public:
    linked_list(){ head = NULL; size = 0; }
    bool is_empty(){ return size==0; }
    void insert_front(t value)
    {
        node<t>* new_node = new node<t>;
        new_node->data = value;
        if (head == NULL)
            new_node->next = NULL;
        else
            new_node->next = head;
        head = new_node;
        size++;
    }
    void insert_back(t value)
    {
        node<t>* new_node = new node<t>;
        new_node->data = value;
        new_node->next = NULL;
        if (head == NULL)
            head = new_node;
        else
        {
            node<t>* tmp = head;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = new_node;
        }
        size++;
    }

    void insert_position(int pos, t value) {
        node<t>* pre = new node<t>;
        node<t>* cur = new node<t>;
        node<t>* tmp = new node<t>;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        tmp->data = value;
        pre->next = tmp;
        tmp->next = cur;
        size++;
    }

    void delete_first() {
        if (is_empty())
        {
            cout << "This list is empty\n";
            return;
        }
        node<t>* tmp = new node<t>;
        tmp = head;
        head = head->next;
        delete tmp;
        size--;
    }

    void delete_last() {
        if (is_empty())
        {
            cout << "This list is empty\n";
            return;
        }
        node<t>* cur = new node<t>;
        node<t>* pre = new node<t>;
        cur = head;
        while (cur->next != NULL)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        delete cur;
        size--;
    }

    void delete_position(int pos) {
        if (is_empty())
        {
            cout << "This list is empty\n";
            return;
        }
        node<t>* cur = new node<t>;
        node<t>* pre = new node<t>;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        size--;
    }

    void display() {
        node<t>* tmp = new node<t>;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n";
    }
};

 */
