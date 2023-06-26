#include <iostream>
#include <cassert>

using namespace std;

template<class t> // allow me to use array for all data type
class Array {
private:
    int maxSize, length;
    t *arr;
public:
    Array(int arraySize) {
        assert(arraySize > 0); // if condition is false , this function stop the program and give me the line number of error
        arr = new t[arraySize];
        maxSize = arraySize; // number of items that the array can hold it
        length = 0; // number of items is already exist
    }

    bool isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return length == maxSize;
    }

    int getSize() {
        return maxSize; // number of items that the array can hold it
    }

    int getLength() {
        return length; // number of items is already exist
    }

    void printLength() {
        cout << "the length of your array is : " << length << '\n';
    }

    void printSize() {
        cout << "the size of your array is : " << maxSize << '\n';
    }

    void display() {
        if (length == 0) {
            cout << "your list is empty.\n";
        } else {
            cout << "array items is : [ ";
            for (int i = 0; i < length; i++)
                cout << arr[i] << ' ';
            cout << "]\n";
        }
    }

    void fill() {
        cout << "enter " << maxSize << " item/s to fill your array :\n"; // may be [ 1 item ]
        for (int i = 0; i < maxSize; i++)
            cin >> arr[i];
        length = maxSize;
    }


    int search(t key) { // key is the value for search
        int index = -1;
        for (int i = 0; i < length; i++) {
            if (arr[i] == key) {
                index = i;
                break;
            }
        }
        return index; // if index still -1 then key isn’t exist otherwise return index of this value
    }

    void addItem(t newItem) {
        if (length == maxSize) // if(isFull())
            cout << "sorry! cannot add new item ,your list is full.\n";
        else {
            arr[length] = newItem;
            length++;
            // we can do this in one line >>>>  items[length++]=newItem;
        }
    }

    void insert(t newItem, int index) { // to add item at any place   ,  0 index
        if (index >= maxSize)
            cout << "Index out of range\n";
        else if (length == maxSize)
            cout << "sorry, your list is full\n";
        else if (index > length)
            cout << "sorry, can’t leave empty places\n";
        else {
            for (int i = length; i > index; i--) {
                arr[i] = arr[i - 1]; // shift elements
            }
            arr[index] = newItem;
            length++;
        }
    }

    void insertWithoutDuplicate(t newItem) {
        if (search(newItem) == -1) {
            addItem(newItem);
        } else {
            cout << "This item already exists.\n";
        }
    }

    t getItemAt(int index) {
        if (index < 0 || index >= length) {
            cout << "out of range...!\n";
        } else {
            return arr[index];
        }
    }

    void Delete(int index) { // 0 index
        if (index >= maxSize) {
            cout << "Index out of range\n";
        } else if (index >= length) {
            cout << "There is no item in this place.\n";
        } else {
            for (int i = index; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }

    void clear() {
        length = 0;
    }

    void Enlarge(int newSize) { // to increase size of array by make a new array by large size and copy item
        if (newSize <= maxSize)
            cout << "sorry, New size must be larger\n";
        else {
            t *old = arr; // copy
            arr = new t[newSize]; // edit size
            for (int i = 0; i < length; i++) {
                arr[i] = old[i]; // restore items
            }
            maxSize = newSize;
            delete[] old;
        }
    }

    void Merge(Array other) { // to merge your array with another
        int newSize = maxSize + other.getSize();
        Enlarge(newSize);
        for (int i = 0; i < other.getLength(); i++) {
            arr[length++] = other.arr[i];
        }
    }

    ~Array() {
        delete[]arr;
    }
};
