#pragma once
#include <iostream>
#include <algorithm>

using namespace std;


// ------------------------------------------
//     class BinaryTree
//     process nodes in Pre/In/Post order
// -------------------------------------------

template <typename T>
class Tree
{
protected:
    // --------------------------------------------------------
    //      inner struct Node.
    //      a single Node of a binary tree.
    //---------------------------------------------------------
    struct Node
    {
        T value;
        Node* left;
        Node* right;
        Node(T val) :value(val), left(NULL), right(NULL) {}
        Node(T val, Node* l, Node* r) :value(val), left(l), right(r) {}
    };
    Node* root;
public:
    Tree() { root = NULL; }
    ~Tree();
    bool isEmpty() const;
    void clear() { clear(root); root = NULL; }
    void preOrder() { preOrder(root); }
    void inOrder() { inOrder(root); }
    void postOrder() { postOrder(root); }

    int leaves() { return leaves(root); } // counts the number of leaves in a tree
    int height() { return height(root); } // returns the height of a tree
    void reflect() { reflect(root); } // reflects the tree
    int onlyLeftSon() { return onlyLeftSon(root); } // returns the number of nodes with only one son


    virtual void process(T val) { cout << val << " "; }
    virtual void add(T val) = 0;
    virtual bool search(T val) = 0;
    virtual void remove(T val) = 0;


private:

    void clear(Node* current); 
    void preOrder(Node* current);  
    void inOrder(Node* current); 
    void postOrder(Node* current); 

    int leaves(Node* current); // counts the number of leaves in a tree - recursive
    int height(Node* current); // returns the height of a tree - recursive
    void reflect(Node* current); // reflects the tree - recursive
    int onlyLeftSon(Node* current); // returns the number of nodes with only one son - recursive
};


// ------------------------------
//   class BinaryTree implementation
// ------------------------------

template <typename T>
Tree<T>::~Tree() {
    if (root != NULL)
        clear(root);
}

template <typename T>
void Tree<T>::clear(Node* current) {
    if (current) {
        if (current->left)
            clear(current->left);
        if (current->right)
            clear(current->right);
        delete current;
    }
}

template <typename T>
bool Tree<T>::isEmpty() const {
    return  root == NULL;
}

template <typename T>
void Tree<T>::preOrder(Node* current) {
    if (current) {
        process(current->value);
        preOrder(current->left);
        preOrder(current->right);
    }
}

template <typename T>
void Tree<T>::inOrder(Node* current) {
    if (current) {
        inOrder(current->left);
        process(current->value);
        inOrder(current->right);
    }
}

template <typename T>
void Tree<T>::postOrder(Node* current) {
    if (current) {
        postOrder(current->left);
        postOrder(current->right);
        process(current->value);
    }
}
template <typename T>
int Tree<T>::leaves(Node* current) {  // counts the number of leaves in a tree - recursive
    if (!current) // if current == NULL
        return 0;
    if (current->left == NULL && current->right == NULL) // if left and right are NULL
        return 1;
    return leaves(current->left) + leaves(current->right); // recursive - left and right subtrees
}

template <typename T>
int Tree<T>::height(Node* current) {
    if (!current) // if current == NULL
        return 0;
    return max(height(current->left), height(current->right)) + 1; // recursive - max height of 2 subtrees
}

template <typename T>
void Tree<T>::reflect(Node* current) {
    if (current) {
        swap(current->left, current->right); // swaps left and right
        reflect(current->left); // recursive - left tree
        reflect(current->right); // recursive - right tree
    }
}

template <typename T>
int Tree<T>::onlyLeftSon(Node* current) {
    if (!current) // current == NULL
        return 0;
    if (current->left != NULL && current->right == NULL) // if only left son
        return 1 + onlyLeftSon(current->left);
    return onlyLeftSon(current->left) + onlyLeftSon(current->right);
}