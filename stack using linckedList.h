#include <iostream>

using namespace std;
template<class t>
struct node {
    t data;
    node *next;
};

template<class t>
class Cstack {
    node<t> *top;
public:
    Cstack() : top(NULL) {}

    bool isEmpty() {
        return top == NULL; // if top==NULL return true , else return false
    }

    bool isFull() {
        node<t> *newNode = new node<t>;
        if (newNode == NULL) {
            cout << "your stack is full\n";
            return true;
        }
        return false;
    }

    void push(t item) {
        node<t> *newNode = new node<t>;
        newNode->data = item;
        if (isEmpty()) {
            newNode->next = NULL;
        } else {
            newNode->next = top;
        }
        top = newNode;
    }

    t pop() { // to get top then remove it
        t value = top->data;
        node<t> *tmp = top;
        top = top->next;
        delete tmp;
        return value;
    }

    t peek() { // to get top without remove it
        return top->data;
    }

    int count() {
        int counter = 0;
        node<t> *tmp = top;
        while (tmp != NULL) {
            counter++;
            tmp = tmp->next;
        }
        delete tmp;
        return counter;
    }

    bool isFound(t value) { // search by value
        node<t> *tmp = top;
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

    void display() {
        node<t> *tmp = top;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n";
        delete tmp;
    }
};