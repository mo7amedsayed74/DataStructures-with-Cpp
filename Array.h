#include<iostream>
#pragma once
using namespace std;
class array {
private:
    int size, length, * items;
public:
    array(int Asize) {
        items = new int[Asize];
        size = Asize; // number of items that the array can hold it
        length = 0; // number of items is already exist
    }
    void fill() {
        cout << "enter number of items you want to fill : ";
        int num; cin >> num;
        if (num > size) {
            cout << "overflow"; return;
        }
        length = num;
        for (int i = 0; i < num; i++) {
            cout << "enter item no " << i + 1 << " : ";
            cin >> items[i];
        }
    }
    int get_length() { return length; }
    int get_size() { return size; }
    void print_length() { cout << "the length of your array is : " << length << '\n'; }
    void print_size() { cout << "the size of your array is : " << size << '\n'; }
    int search(int key) {
        int ind = -1;
        for (int i = 0; i < length; i++) {
            if (items[i] == key) {
                ind = i; break;
            }
        }
        return ind;
    }


    void display() {
        cout << "array items is : ";
        for (int i = 0; i < length; i++)cout << items[i] << ' ';
        cout << '\n';
    }
};