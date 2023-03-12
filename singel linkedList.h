//linked list
//Advantages    ( Dynamic size  -  ease of insertion/deletion )
//disAdvantages (random access isn’t allowed - extra memory space is required for pointer to each element )

struct node {
    int value;
    node *next;
};

class linked_list {
    node *head;
public:
    linked_list() {
        head = NULL;
    }

    bool isEmpty() {
        return (head == NULL);
        /*
          if(head==NULL) return true;
          else return false;
         */
    }

    void insert_front(int data) {
        node *newNode = new node;
        newNode->value = data;
        if (isEmpty()) { // head == NULL
            newNode->next = NULL;
        }
        else {
            newNode->next = head;
        }
        head = newNode;
    }

    void insert_back(int data) {
        node *newNode = new node;
        newNode->value = data;

        if (isEmpty()) { // head == NULL
            newNode->next = NULL;
            head = newNode;
        }
       else{
            node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
       }
    }

    void insert_pos(int data, int pos) { 
        if(pos==1){
            insert_front(data);
            return; // stop function
        }
        else if(pos == countElements()+1){
            insert_back(data);
            return; // stop function
        }
        else if(pos > countElements()+1){
            cout<<"Sorry ,invalid index\n";
            return; // stop function
        }
        node *newNode = new node;
        newNode->value = data;
        node *cur = head;
        node *pre = new node;
        for (int i = 0; i < pos - 1; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = newNode;
        newNode->next = cur;
    }

    void delete_front() {
        if(isEmpty()){
            cout<<"ERROR! your list is empty\n";
            return;
        }
        node *temp =head;
        head = head->next;
        delete temp;
    }

    void delete_back() {
        if(isEmpty()){
            cout<<"ERROR! your list is empty\n";
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
    }

    void delete_pos(int pos) {
        if(isEmpty()){
            cout<<"ERROR! your list is empty\n";
            return;
        }
        if(pos==1){
            delete_front();
            return; // stop function
        }
        else if(pos > countElements()){
            cout<<"Sorry ,invalid index\n";
            return; // stop function
        }
        node *cur = head;
        node *pre = new node;
        for (int i = 0; i < pos - 1; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }

    void sort_LinkedList() {
        node *p, *q;
        int temp;
        for (p = head; p->next != NULL; p = p->next) {
            for (q = p; q != NULL; q = q->next) {
                if (p->value > q->value) {
                    temp = p->value;
                    p->value = q->value;
                    q->value = temp;
                }
            }
        }
    }
    bool isFound(int element){ // to check if element exist in list or not
        bool exist=false;
        node *temp =head;
        while (temp != NULL) {
            if(temp->value==element){
                exist=true;
                break; // to exit from while loop
            }
            temp = temp->next;
        }
        if(exist)return true;
        else return false;
    }
    int countElements(){
        int cnt=0;
        node *temp =head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    void display() {
        node *temp =head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
};


/*
int main() {
 linked_list x;
    if(x.isEmpty())cout<<"your list is empty\n";

    x.insert_front(5);
    x.insert_front(6);
    x.insert_front(7);
    x.display();
    cout<<"you have "<<x.countElements()<<" items in your list\n";
    x.insert_pos(10, 2);
    x.display();
    cout<<"you have "<<x.countElements()<<" items in your list\n";
    x.delete_back();
    x.delete_front();
    x.display();
    cout<<"you have "<<x.countElements()<<" items in your list\n";
    x.insert_pos(11, 2);
    x.display();
    cout<<"you have "<<x.countElements()<<" items in your list\n";
    x.delete_pos(2);
    x.display();
    cout<<"you have "<<x.countElements()<<" items in your list\n";

    if(x.isFound(10))cout<<"10 is exist\n";
}
 */
