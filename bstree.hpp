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

        Node(T val)
        {
			data = val;
			left = nullptr;
			right = nullptr;
        }
    };

    Node *root;

    void print(Node* nodePtr)
    {
        if (nodePtr == nullptr) return;
        if (nodePtr->left)
        {
            cout << "going left: ";
            print(nodePtr->left);
        }
        cout << *(nodePtr->data) << endl;
        if (nodePtr->right)
        {
            cout << "going right: ";
            print(nodePtr->right);
        }
    }

    void freeMemory(Node*);


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
        print(root);
    }
    T search(string);
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
            prev->right = treeNode;
        else
            prev->left = treeNode;
    }
}

template <class T>
T BSTree<T>::search(string str)
{
    
}

#endif // _BSTree_HPP_