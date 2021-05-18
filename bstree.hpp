#ifndef _BSTree_HPP_
#define _BSTree_HPP_

#include <iostream>
#include <vector>

#include "song.hpp"

using namespace std;

/**
 * Node: BSTree only works when T is a pointer to something.
 * 
 * Use BSTree like: BSTree<Song *> tree;
 * or               BSTree<User *> tree;
 */

template <class T>
class BSTree
{
    struct Node
    {
        friend BSTree;

        T data;
        Node *left;
        Node *right;
        Node *parent;

        Node(T val)
        {
            data = val;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
    };

    Node *root;

    void print(Node* nodePtr)
    {
        cout << nodePtr << endl;
        if (nodePtr == nullptr) return;
        if (nodePtr->left)
        {
            cout << "L: ";
            print(nodePtr->left);
        }
        if (nodePtr->parent != nullptr)
            cout << *(nodePtr->data) << " P: " << *(nodePtr->parent->data) << endl;
        else
            cout << *(nodePtr->data) << " P: " << (nodePtr->parent) << endl;
        if (nodePtr->right)
        {
            cout << "R: ";
            print(nodePtr->right);
        }
    }

    void freeMemory(Node*);

    T search(string, Node*, bool*);

    void remove(Node *node);

    Node *minimum(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr) current = current->left;
        return current;
    }

public:
    BSTree()
    {
        root = nullptr;
    }

    ~BSTree()
    {
        freeMemory(root);
    }

    void insert(T);
    void print()
    {
        cout << "Printing root!" << endl;
        print(root);
    }

    T search(string, bool*);

    /**
     * Removes the node T matching the provided string.
     * Type T must have the == operator overloaded
     */
    void remove(string str)
    {
        bool found = false;
        T nd = search(str, &found);

        if (!found) return;

        deleteNode(root, nd);
    }
    
    void deleteNode(Node *node, T data)
    {
        cout << "Deleting " << *data << " Comparing with " << *(node->data) << endl;

        if (node == nullptr) return;

        if (*data == *(node->data))
        {
            cout << "Data matched" << endl;
            
            // Extra: If node is root
            if (node == root) root = nullptr;

            // Case 1: Leaf
            if (node->right == nullptr && node->left == nullptr)
            {
                cout << "Case leaf\n";
                // are we left or right to parent?
                if (node->parent != nullptr)
                {
                    if (*(node->data) > *(node->parent->data))
                        node->parent->right = nullptr;
                    else
                        node->parent->left = nullptr;
                    
                }

                //delete node->data;
                node = nullptr;
                goto bst_remove_exit;
            }

            // Case 2: Node has only one child
            if ((node->right != nullptr) != (node->left != nullptr))
            {
                cout << "Case stem\n";
                if (node->parent != nullptr)
                {
                    // Child is to left
                    if ((node->right == nullptr) && (node->left != nullptr))
                    {
                        // // are we left or right to parent?
                        if (*(node->data) > *(node->parent->data))
                            node->parent->right = node->left;
                        else
                            node->parent->left = node->left;
                        
                        // Update child's new parent
                        node->left->parent = node->parent;
                    }
                    // Child is to right
                    else if ((node->right != nullptr) && (node->left == nullptr))
                    {
                        if (*(node->data) > *(node->parent->data))
                            node->parent->right = node->right;
                        else
                            node->parent->left = node->right;
                        
                        // Update child's new parent
                        node->right->parent = node->parent;
                    }
                }
                else 
                {
                    // We are removing root, make sure its successor has a nullptr parent
                    root = (node->right != nullptr) ? (node->right) : (node->left);
                    root->parent = nullptr;
                }
                goto bst_remove_exit;
            }

            // Case 3: Node has two children
            if (node->right != nullptr && node->left != nullptr)
            {
                cout << "Case 2children\n";
                // We will take the smaller node, the left, and attach it to the minimum node on right
                node->left->parent = minimum(node->right);
                node->left->parent->left = node->left;
                
                // Are we root?
                if (node->parent == nullptr)
                {
                    root = node->right;
                    node->right->parent = nullptr;
                }
                // No root.
                else {
                    // We have a parent, what side of parent are we on?
                    if (*(node->data) > *(node->parent->data))
                    {
                        node->parent->right = node->right;
                    }else{
                        node->parent->left = node->right;
                    }
                    node->right->parent = node->parent;
                }

            }

bst_remove_exit:
            cout << "root is " << root << endl;
            cout << "node is " << node << endl;
            cout << "node->data is inaccessible" << endl;
            cout << "*(node->data) is inaccessible" << endl;
        }

        else if (*data < *(node->data))
            /*node->left = */deleteNode(node->left, data);
        else if (*(data) > *(node->data))
            /*node->right = */deleteNode(node->right, data);
        // else if (*data == *(node->data))
        // {
            

        //     //if (node->parent == nullptr && node->left == nullptr && node->right == nullptr) delete node->data;
        //     /*else if (node->left == nullptr)
        //     {
        //         cout << "left is nullptr" << endl;
        //         if (node->parent != nullptr)
        //             (node->data > node->parent->data) ? (node->parent->right) : (node->parent->left) = node->right;
        //         delete node;
        //         node = nullptr;
        //         // Node *temp = node->right;
        //         // delete node;
        //         // node = nullptr;
        //         // return temp;
        //     }
        //     else if (root->right == nullptr)
        //     {
        //         cout << "right is nullptr" << endl;
        //         if (node->parent != nullptr)
        //             (node->data > node->parent->data) ? (node->parent->right) : (node->parent->left) = node->left;
        //         delete node;
        //         node = nullptr;
        //         // Node *temp = node->left;
        //         // delete node;
        //         // node = nullptr;
        //         // return temp;
        //     }*/
        //     /*Node *temp = minimum(node->right);
        //     node->data = temp->data;
        //     node->right = deleteNode(node->right, temp->data);*/
        // }
        //return node;
    }
};


template <class T>
void BSTree<T>::freeMemory(BSTree::Node *node)
{
    if (node == nullptr) return;
    if (node->left)
        freeMemory(node->left);
    if (root->right)
        freeMemory(node->right);
    delete node;
}

template <class T>
void BSTree<T>::insert(T val)
{
    Node *treeNode = new Node(val);
    Node *temp = nullptr;
    Node *prev = nullptr;

    temp = root;
    while(temp != nullptr)
    {
        prev = temp;
        if (*(temp->data) < *(treeNode->data))
            temp = temp->right;
        else
            temp = temp->left;
    }

    if (prev == nullptr)  root = treeNode;
    else
    {
        if (*(prev->data) < *(treeNode->data))
            prev->right = treeNode, treeNode->parent = prev;
        else
            prev->left = treeNode, treeNode->parent = prev;
    }
}

template <class T>
T BSTree<T>::search(string str, bool *found)
{
    return search(str, root, found);
}

template <class T>
T BSTree<T>::search(string str, Node *parent, bool *found)
{
    if (parent == nullptr)
    {
        *found = false;
        return nullptr;
    }

    if (*(parent->data) == str)
    {
        *found = true;
        return parent->data;
    }
    
    // Decide to search left or right...

    if (*(parent->data) < str)
    {
        return search(str, parent->right, found);
    }
    else if (*(parent->data) > str)
    {
        return search(str, parent->left, found);
    }

    *found = false;
    return nullptr;
}




// template <class T>
// void BSTree<T>::remove(Node *node)
// {
//     /**
//      * Three cases for removing a Node.
//      * Either is the root, a leaf, or middle node.
//      */


//     /* The easy cases */

//     /* Node is a leaf */
//     if (node->right == nullptr && node->left == nullptr)
//     {
//         // Node has no children.
//         if (node->parent->right == node) node->parent->right = nullptr;
//         else if (node->parent->left == node) node->parent->left = nullptr;
//         delete node;
//     }
//     /**
//      * Node has only one child, set parent to skip it */
//     else if ((node->right != nullptr) != (node->left != nullptr))
//     {
//         node->parent = (node->right != nullptr) ? node->right : node->left;
//         delete node;
//     }

//     /**
//      * The 'hard' case, node has two children,
//      */

    
//     // Case 2: Node is the root
//     else if (node == root)
//     {
//         /* Root has one child, delete the root, and raise child to root */
//         if ((node->right != nullptr) != (node->left != nullptr))
//         {
//             root = (node->right != nullptr) ? node->right : node->left;
//             root->parent = nullptr;
//             delete node;
//         }
//         /* Root has no children, just delete */
//         else if (node->right == nullptr && node->left == nullptr)
//         {
//             delete node, root = nullptr;
//         }
//         /* Root has two children, move smaller one to another spot */
//         else if (node->right != nullptr && node->left != nullptr)
//         {

//         }
//     }
// }

// template <class T>
// void BSTree<T>::remove(string name, Node *parent)
// {
//     if (parent == nullptr) return;
//     else if (parent->data == val)
//     {
//         // Remove this node, parent
//     }else if (parent->data)
// }

// template <class T>
// void BSTree<T>::remove(string name)
// {
//     /**
//      * Starting at root, find the node with value T and remove it
//      */
//     remove(val, root);

//     if (!found) return;

//     /**
//      * Three cases for removing from BST.
//      * Either removing head node, a leaf with no children, or one in the middle
//      */

// }

#endif // _BSTree_HPP_