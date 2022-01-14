#include "node.h"

template <typename T>
struct LinkedList
{
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    int size = 0;

    void add(T val, string key)
    {
        Node<T> *newNode = new Node<T>(val, key);
        if (size == 0)
            head = tail = newNode;
        else
        {
            newNode->left = tail;
            tail->right = newNode;
            tail->right->left = tail;
            tail = tail->right;
        }

        size++;
    }

    // for hash table purposes only
    void remove(string key)
    {
        if (size == 1)
        {
            head = tail = NULL;
            return;
        }

        Node<T> *trav = head;
        while (trav->key != key)
        {
            trav = trav->right;
        }

        trav->left->right = trav->right;
        trav->right->left = trav->left;
        head = trav;

        trav = NULL;
        size--;
    }
};