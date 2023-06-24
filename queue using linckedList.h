#include <iostream>
#include <cassert>

using namespace std;
template<class t>
struct node {
    t data;
    node *next;
};

template<class t>
class linkedQueue {
    node<t> *head, *tail;
    int length;
public:
    linkedQueue() : head(NULL), tail(NULL), length(0) {}


    bool isEmpty() {
        // return length==0;
        return head == NULL || tail == NULL;
    }

    bool isFull() {
        node<t> *newNode = new node<t>;
        if (newNode == NULL) {
            cout << "your queue is full\n";
            return true;
        }
        delete newNode;
        return false;
    }

    int getLength() { return length; }

    void insert(t value) {
        node<t> *newNode = new node<t>;
        newNode->data = value;
        newNode->next = NULL;
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void Dequeue() { // to remove top element

        assert(!isEmpty()); // if queue is empty , this function stop the program and give me the line number of error
        if (length == 1) {
            delete head;
            head = tail = NULL;
            length = 0;
        } else {
            node<t> *tmp = head;
            head = head->next;
            delete tmp;
            length--;
        }
    }

    t pop() { // to get top then remove it

        assert(!isEmpty()); // if queue is empty , this function stop the program and give me the line number of error
        t value = head->data;
        if (length == 1) {
            delete head;
            head = tail = NULL;
            length = 0;
            return value;
        } else {
            node<t> *tmp = head;
            head = head->next;
            delete tmp;
            length--;
            return value;
        }
    }

    t showTop() { /// to get top without remove it
        assert(!isEmpty()); // if queue is empty , this function stop the program and give me the line number of error
        return head->data;
    }

    void showTop(t &element) { /// to get top without remove it
        assert(!isEmpty()); // if queue is empty , this function stop the program and give me the line number of error
        element = head->data;
    }

    int count() { // (or) int count(){return length;}  , int count(){return getLength();}
        int counter = 0;
        node<t> *tmp = head;
        while (tmp != NULL) {
            counter++;
            tmp = tmp->next;
        }
        delete tmp;
        return counter;
    }

    bool isFound(t value) { // search by value
        node<t> *tmp = head;
        bool found = false;
        while (tmp != NULL) {
            if (tmp->data == value) {
                found = true;
                break;
            }
            tmp = tmp->next;
        }
        delete tmp;
        return found;
    }

    void clear() { // to remove all elements
        while (!isEmpty()) {
            Dequeue();
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "sorry, queue is empty\n";
            return;
        }
        node<t> *tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n";
        delete tmp;
    }
};
