#pragma once
#include "Tree.h"

template <typename T>
class SearchTree : public Tree<T>
{
public:
    void add(T val);
    bool search(T val);
    void remove(T val) { remove(NULL, this->root, val); } // removes a value from bst
    int level(T val) { if (!search(val)) return -1; else return level(this->root, val); } // returns the level of a value in bst

private:
    void add(typename Tree<T>::Node* current, T val);
    bool search(typename Tree<T>::Node* current, T val);
    void remove(typename Tree<T>::Node* parent, typename Tree<T>::Node* current, T val);  // removes a value from bst - recursive
    int level(typename Tree<T>::Node* current, T val); // returns the level of a value in bst - recursive
};

template <typename T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val) {
    if (!current)
        return false;
    if (current->value == val)
        return true;
    if (current->value < val)
        return search(current->right, val);
    else
        return search(current->left, val);
}

template <typename T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val) {
    if (current->value < val)
        if (!current->right) {
            current->right = new typename Tree<T>::Node(val);
            return;
        }
        else
            add(current->right, val);
    else
        if (!current->left) {
            current->left = new typename Tree<T>::Node(val);
            return;
        }
        else
            add(current->left, val);
}

template <typename T>
bool SearchTree<T>::search(T val) {
    return search(this->root, val);
}

template <typename T>
void SearchTree<T>::add(T val) {
    if (!this->root) {
        this->root = new typename Tree<T>::Node(val);
        return;
    }
    add(this->root, val);
}

// removes a value from bst - recursive
template <typename T>
void SearchTree<T>::remove(typename Tree<T>::Node* parent, typename Tree<T>::Node* current, T val) {
    if (current != NULL) {
        if (current->value == val) { // if we have found the value
            // case 1 - node is a leaf
            if (current->left == NULL && current->right == NULL) {
                if (current == this->root) { // if the node is the root
                    delete this->root;
                    this->root = NULL;
                    return;
                }
                if (parent->left->value == val) // if current is a left son
                    parent->left = NULL;
                else // if current is a right son
                    parent->right = NULL; 
                delete current;
            }

            // case 2 - node has only one son
            else if (current->left == NULL || current->right == NULL) {
                if (current == this->root) { // if the node is the root
                    if (current->left != NULL) { // if current's son is a left son
                        delete this->root;
                        this->root = current->left;
                        return;
                    }
                    else { // if currents son is a right son
                        delete this->root;
                        this->root = current->right;
                        return;
                    }
                }
                // if is not the root
                if (current->left != NULL) {  // if current's son is a left son
                    if (parent->left->value == val) // if current is a left son (of parent)
                        parent->left = current->left;
                    else // if current is a right son (of parent)
                        parent->right = current->left;
                }
                else { // if current's son is a right son
                    if (parent->left->value == val) // if current is a left son (of parent)
                        parent->left = current->right;
                    else // if current is a right son (of parent)
                        parent->right = current->right;
                }

            }

            // case 3 - node has two sons
            else {
                typename Tree<T>::Node* successor = current->right; // find the succesor - minimum of right subtree
                typename Tree<T>::Node* successorParent = current; // succesor's parent
                while (successor->left != NULL) { // find minimum 
                    successorParent = successor;
                    successor = successor->left;
                }
                swap(current->value, successor->value); // swap valus of current and succesor
                remove(successorParent, successor, successor->value); // remove the succesor
            }
        }
        else { // if value was not found - recurse
            remove(current, current->left, val);
            remove(current, current->right, val);
        }
    }
}

// returns the level of a value in bst - recursive
template <typename T>
int SearchTree<T>::level(typename Tree<T>::Node* current, T val) {
    if (current->value == val) // if value was found 
        return 0;
    else if (current->value < val) // if value is larger - go right
        return level(current->right, val) + 1;
    else // if value is smaller - go left
        return level(current->left, val) + 1;

}
