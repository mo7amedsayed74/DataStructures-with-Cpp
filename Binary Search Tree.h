/// tree is hierarchical (non linear) data structure
/// Binary Search Tree (BST) {value of LEFT_CHILD is smaller than root , value of RIGHT_CHILD is greater or equal to the root}
/*
   ADVANTAGES OF BST :
    - searching an element is easy
    - As compared to array and linked list , INSERTION and DELETION are faster
 */

// start code
#include <iostream>

using namespace std;

class node {
public:
    // declare variable in public scope to allow access
    int data;
    node *leftChild, *rightChild;

    node(int data) {
        this->data = data;
        leftChild = rightChild = NULL;
    }
};

class BST {
public:
    node *root;

    BST() : root(NULL) {}

    node *Insert(node *newRoot, int item) {
        if (newRoot == NULL) {
            node *newNode = new node(item);
            //return newNode;
            newRoot = newNode;
            return newRoot;
        } else if (item < newRoot->data) {
            newRoot->leftChild = Insert(newRoot->leftChild, item);
        } else { // item >= newRoot->data
            newRoot->rightChild = Insert(newRoot->rightChild, item);
        }
        return newRoot;
    }

    void Insert(int item) {
        root = Insert(root, item);
    }
    // ---------------------------------------------

    bool Search(node *newRoot, int item) {
        if (newRoot == NULL) {
            return false;
        } else if (item == newRoot->data) {
            return true;
        } else if (item < newRoot->data) { // item exists in left
            Search(newRoot->leftChild, item);
        } else { // item > newRoot->data     // item exists in right
            Search(newRoot->rightChild, item);
        }
    }

    bool Search(int item) {
        return Search(root, item);
    }
    // ---------------------------------------------

    node *findMin(node *newRoot) {
        if (newRoot == NULL)return NULL; // Empty tree
        while (newRoot->leftChild != NULL) {
            newRoot = newRoot->leftChild;
        }
        return newRoot;

        // another way
        /*
            if(newRoot==NULL)return NULL; // Empty tree
            else if(newRoot->leftChild==NULL)return newRoot;
            else findMax(newRoot->leftChild);
         */
    }

    int findMin() {
        node *tmp = findMin(root);
        return tmp->data;
    }

    node *findMax(node *newRoot) {
        if (newRoot == NULL)return NULL; // Empty tree
        while (newRoot->rightChild != NULL) {
            newRoot = newRoot->rightChild;
        }
        return newRoot;

        // another way
        /*
            if(newRoot==NULL)return NULL; // Empty tree
            else if(newRoot->rightChild==NULL)return newRoot;
            else findMax(newRoot->rightChild);
         */
    }

    int findMax() {
        node *tmp = findMax(root);
        return tmp->data;
    }
    // ---------------------------------------------

    node *Delete(node *newRoot, int item) {
        if (newRoot == NULL) {
            cout << "sorry! this item not found on your tree.";
            return newRoot;
        } else if (item < newRoot->data) { // item exists in left
            newRoot->leftChild = Delete(newRoot->leftChild, item);
        } else if (item > newRoot->data) { // item exists in right
            newRoot->rightChild = Delete(newRoot->rightChild, item);
        } else {
            // No child
            if (newRoot->rightChild == NULL && newRoot->leftChild == NULL) { // this item is leaf node
                delete newRoot;
                newRoot = NULL;
            }
                // one child
            else if (newRoot->rightChild == NULL) { // has one child on the left
                node *tmp = newRoot;
                newRoot = newRoot->leftChild;
                delete tmp;
            } else if (newRoot->rightChild != NULL) { // has one child on the right
                node *tmp = newRoot;
                newRoot = newRoot->rightChild;
                delete tmp;
            }
                // two children
            else { // has two children

                node *maxItemOnLeft = findMax(newRoot->leftChild);
                newRoot->data = maxItemOnLeft->data;
                newRoot->leftChild = Delete(newRoot->leftChild, maxItemOnLeft->data);

                /*
                  node* minItemOnRight = findMin(newRoot->rightChild);
                  newRoot->data = minItemOnRight->data;
                  newRoot->rightChild = Delete(newRoot->rightChild, minItemOnRight->data);
                 */
            }
        }
        return newRoot;
    }

    void Delete(int item) {
        root = Delete(root, item);
    }
    //----------------------------------


    // display
    void preOrder(node *Root) { // root _ left _ right
        if (Root == NULL)return;

        cout << Root->data << " ";
        preOrder(Root->leftChild);
        preOrder(Root->rightChild);
    }

    void inOrder(node *Root) { // left _ root _ right
        if (Root == NULL)return;

        inOrder(Root->leftChild);
        cout << Root->data << " ";
        inOrder(Root->rightChild);
    }

    void postOrder(node *Root) { // left _ right _ root
        if (Root == NULL)return;

        postOrder(Root->leftChild);
        postOrder(Root->rightChild);
        cout << Root->data << " ";
    }
};