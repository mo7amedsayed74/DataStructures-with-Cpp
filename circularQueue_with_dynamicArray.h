#include<iostream>
#include <cassert>

using namespace std;

template<class t>
class CircularQueue { // CircularQueue<dataType> queueName(size);
private:
    int front, rear, maxSize, length;
    t *arr;
public:
    CircularQueue(int size) {
        assert(size > 0); // size cannot be negative or zero
        maxSize = size;
        arr = new t[maxSize];
        length = 0;
        front = 0;
        rear = maxSize - 1;
    }

    bool is_full() {
        return length == maxSize;
    }

    bool is_empty() {
        return length == 0;
    }

    t getFront() {
        assert(!is_empty()); // if queue is empty , this function stop the program and give me the line number of error
        return arr[front];
    }

    t getRear() {
        assert(!is_empty()); // if queue is empty , this function stop the program and give me the line number of error
        return arr[rear];
    }

    int getLength() { // return The number of items in the queue
        return length;
    }

    void insert(t element) {
        if (is_full()) {
            cout << "overflow! cannot add item, queue is full.\n";
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = element;
        length++;
    }

    void remove() {
        if (is_empty()) {
            cout << "underflow! queue is empty.\n";
            return;
        }
        front = (front + 1) % maxSize;
        length--;
    }

    bool search1(t element) { // Search for an element , found or not found

        if (!is_empty()) { // (or)  if(length > 0)
            for (int i = front; i != rear; i = (i + 1) % maxSize) {
                if (arr[i] == element)return true;
            }
            if (arr[rear] == element)return true;
        }

        return false; // notFound
    }

    int search2(t element) { // Search for an element and return its index
        int notFound = -1;
        if (!is_empty()) { // (or)  if(length > 0)
            for (int i = front; i != rear; i = (i + 1) % maxSize) {
                if (arr[i] == element)return i;
            }
            if (arr[rear] == element)return rear;
        }
        return notFound; //  -1
    }

    void display() {
        if (is_empty()) { // (or)  if(length == 0)
            cout << "sorry! queue is empty.\n";
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % maxSize) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << "\n";
    }
};
