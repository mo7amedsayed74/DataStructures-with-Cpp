#include <iostream>

using namespace std;
template<class t>
struct node {
    t data;
    node *next;
};

template<class t>
class Cqueue {
    node<t> *head;
public:
    Cqueue() : head(NULL) {}

    bool isEmpty() {
        return head == NULL;
    }

    bool isFull() {
        node<t> *newNode = new node<t>;
        if (newNode == NULL) {
            cout << "your queue is full\n";
            return true;
        }
        return false;
    }

    void insert(t value) {
        node<t> *newNode = new node<t>;
        newNode->data = value;
        newNode->next = NULL;
        if (isEmpty()) {
            head = newNode;
        } else {
            node<t> *tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }

    void Dequeue() { // to remove top element
        if (isEmpty())
            cout << "error! your queue is empty\n";

        node<t> *tmp = head;
        head = head->next;
        delete tmp;
    }

    t pop() { // to get top then remove it
        if (isEmpty())
            cout << "error! your queue is empty\n";

        t value = head->data;
        node<t> *tmp = head;
        head = head->next;
        delete tmp;
        return value;
    }

    t showTop() { // to get top without remove it
        return head->data;
    }

    int count() {
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
        if(isEmpty()){
            cout<<"sorry, queue is empty\n";
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