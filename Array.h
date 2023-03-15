
template<class t> // allow me to use array for all data type
class Array {
private:
    int size, length;
    t *items;
public:
    Array(int arraySize) {
        items = new int[arraySize];
        size = arraySize; // number of items that the array can hold it
        length = 0; // number of items is already exist
    }

    void fill() {
        int num;
        cout << "enter number of items you want to fill : ";
        cin >> num;
        if (num > size) {
            cout << "ERROR! overflow\n";
            return;
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

    int search(t key) { // key is the value for search
        int index = -1;
        for (int i = 0; i < length; i++) {
            if (items[i] == key) {
                index = i;
                break;
            }
        }
        return index; // if index still -1 then key isn’t exist otherwise return index of this value
    }

    void addItem(t newItem) {
        if (length == size)
            cout << "You cant exceed the array size\n";
        else {
            items[length] = newItem;
            length++;
            // we can do this in one line >>>>  items[length++]=newItem;
        }
    }

    void insert(t newItem, int index) { // to add item at any place
        index--; // user use 1 index but we use 0 index
        if (index >= size - 1)
            cout << "Index out of range\n";
        else if (length == size)
            cout << "sorry, your list is full\n";
        else if (index > length)
            cout << "sorry, can’t leave empty places\n";
        else {
            for (int i = length; i > index; i--) {
                items[i] = items[i - 1]; // shift elements
            }
            items[index] = newItem;
            length++;
            // we can do this in one line >>>>  items[length++]=newItem;
        }
    }

    void Delete(int index) {
        if (index >= size)
            cout << "Index out of range\n";
        else {
            index--; // user use 1 index but we use 0 index
            for (int i = index; i < length - 1; i++) {
                items[i] = items[i + 1];
            }
            length--;
        }
    }

    void display() {
        cout << "array items is : [ ";
        for (int i = 0; i < length; i++)
            cout << items[i] << ' ';
        cout << "]\n";
    }

    void Enlarge(int newSize) { // to increase size of array by make a new array by large size and copy item
        if (newSize <= size)
            cout << "sorry, New size must be larger\n";
        else {
            t *old = items; // copy
            items = new int[newSize]; // edit size
            for (int i = 0; i < length; i++) {
                items[i] = old[i]; // restore items
            }
            size = newSize;
            delete[] old;
        }
    }

    void Merge(Array other) { // to merge your array with another
        int newSize = size + other.get_size();
        Enlarge(newSize);
        for (int i = 0; i < other.get_length(); i++) {
            items[length++] = other.items[i];
        }
    }
};
