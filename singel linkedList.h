//linked list
//Advantages    ( Dynamic size  -  ease of insertion/deletion )
//disAdvantages (random access isn’t allowed - extra memory space is required for pointer to each element )

#include <iostream>
using namespace std;

template<class t>
class linkedList {
    struct node {
        t data;
        node *next;
    };

    node *head;
    int length;
public:
    linkedList() {
        head = NULL;
        length = 0;
    }

    bool isEmpty() {
        return (head == NULL);
        /*
          if(head==NULL) return true;
          else return false;
         */
    }

    void insertFront(t element) {
        node *newNode = new node;
        newNode->data = element;
        if (isEmpty()) { // head == NULL
            newNode->next = NULL;
        } else {
            newNode->next = head;
        }
        head = newNode;
        length++;
    }

    void insertBack(t element) {
        node *newNode = new node;
        newNode->data = element;

        if (isEmpty()) { // head == NULL
            head = newNode;
            newNode->next = NULL;
        } else {
            node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
        length++;
    }

    void insertPos(t element, int pos) { // one index
        if (pos == 1) {
            insertFront(element);
            return; // stop function
        } else if (pos == (length + 1)) {
            insertBack(element);
            return; // stop function
        } else if (pos < 0 || pos > (length + 1)) {
            cout << "Sorry ,invalid index\n";
            return; // stop function
        }
        node *newNode = new node;
        newNode->data = element;
        node *cur = head;
        node *pre = new node;
        for (int i = 0; i < pos - 1; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = newNode;
        newNode->next = cur;
    }

    int search(t element) {
        node *pointer = head;
        int position = 0;
        while (pointer != NULL) {
            if (pointer->data == element) {
                return position; // founded
            }
            position++;
            pointer = pointer->next;
        }
        return -1; // isn’t found
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "ERROR! your list is empty\n";
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void deleteBack() {
        if (isEmpty()) {
            cout << "ERROR! your list is empty\n";
            return;
        }
        node *cur = head;
        node *pre = new node;
        while (cur->next != NULL) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        delete cur;
        length--;
    }

    void deleteByPos(int pos) {
        if (isEmpty()) {
            cout << "ERROR! your list is empty\n";
            return;
        }
        if (pos == 1) {
            deleteFront();
            return; // stop function
        } else if (pos > countElements()) {
            cout << "Sorry ,invalid index\n";
            return; // stop function
        }
        node *cur = head;
        node *pre = new node;
        for (int i = 1; i < pos; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
        length--;
    }

    void deleteByElement(t item) {
        if (isEmpty()) {
            cout << "your list is empty!\n";
            return;
        }
        int pos = search(item);
        if (pos == -1) {
            cout << "the element not found, try again.\n";
        } else {
            if (pos == 0)
                deleteFront();
            else if (pos == (length - 1))
                deleteBack();
            else {
                node *toRemove = head->next;
                node *toHold = head;
                for (int i = 1; i < pos; i++) {
                    toHold = toRemove;
                    toRemove = toRemove->next;
                }
                toHold->next = toRemove->next;
                delete toRemove;
                length--;
            }
        }
    }

    /// you can make this functions in one function
    void remove() {
        if (isEmpty()) {
            cout << "your list is empty!\n";
            return;
        }
        int pos, check;
        cout
                << "If you want to remove at position enter (1) \nIf you want to remove a specific element you do not know it’s position enter (2)\n";
        cin >> check;
        if (check == 1) {
            cout << "enter position : ";
            cin >> pos; // user deal with ( 1 index )
            pos--;
        } else if (check == 2) {
            t item;
            cout << "enter item please : ";
            cin >> item;
            pos = search(item); // return position ( 0 index )
        } else {
            cout << "wrong choice, try again.\n";
            remove(); // start function again
            return;
        }
        // start to check on position
        if (pos < 0 || pos >= length) {
            cout << "Out of the range, try again.\n";
            remove(); // start function again
            return;
        }
        if (pos == 0)
            deleteFront();
        else if (pos == length)
            deleteBack();
        else {
            node *pre = head;
            node *toRemove;
            for (int i = 1; i < pos; i++) {
                pre = pre->next;
            }
            toRemove = pre->next;
            pre->next = toRemove->next;
            delete toRemove;
            length--;
        }
    }

    void sortLinkedList() {
        node *i, *j;
        t temp;
        for (i = head; i->next != NULL; i = i->next) {
            for (j = i; j != NULL; j = j->next) {
                if (i->data > j->data) {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    bool isFound(t element) { // to check if element exist in list or not
        bool exist = false;
        node *temp = head;
        while (temp != NULL) {
            if (temp->data == element) {
                exist = true;
                break; // to exit from while loop
            }
            temp = temp->next;
        }
        delete temp;
        return exist;
        /*
         if (exist)return true;
         else return false;
         */
    }

    int countElements() {
        int cnt = 0;
        node *temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        delete temp;
        return cnt;
    } // int countElements(){ return length; }

    void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << '\n';
        delete temp;
    }

    void clear() {
        node *current;
        while (head != NULL) {
            current = head;
            head = head->next;
            delete current;
        }
        length = 0;
    }

    ~linkedList() {
        clear();
    }
};
