#include "node.h"

template <typename T>
class BinarySearchTree
{
private:
    int nodeCount = 0;

    Node<T> *add(Node<T> *node, T elem)
    {
        if (node == NULL)
            node = new Node<T>(elem, NULL, NULL);
        else        
        {
            if (elem > node->data)
                node->right = add(node->right, elem);
            else
                node->left = add(node->left, elem);
        }

        return node;
    }

    Node<T> *remove(Node<T> *node, T elem)
    {
        if (node == NULL)
            return NULL;

        // FIND PHASE
        if (elem > node->data)
            node->right = remove(node->right, elem);
        else if (elem < node->data)
            node->left = remove(node->left, elem);

        // REMOVE PHASE
        else
        {
            if (node->right == NULL)
            {
                Node<T> *leftChild = node->left;

                node->left = NULL;

                return leftChild;
            }
            else if (node->left == NULL)
            {
                Node<T> *rightChild = node->right;

                node->right = NULL;

                return rightChild;
            }
            else
            {
                Node<T> *tmp = digRight(node->left);
                node->data = tmp->data;
                node->left = remove(node->left, tmp->data);

                // Node <T> *tmp = digLeft(node->right);
                // node->data = tmp->data;
                // node->right = remove(node->right, tmp->data);
            }
        }

        return node;
    }

    Node<T> *digRight(Node<T> *node)
    {
        Node<T> *trav = node;
        while (trav->right != NULL)
        {
            trav = trav->right;
        }

        return trav;
    }

    Node<T> *digLeft(Node<T> *node)
    {
        Node<T> *trav = node;
        while (trav->left != NULL)
        {
            trav = trav->left;
        }

        return trav;
    }

    int height(Node <T> *node){
        if (node == NULL)
            return 0;
        
        return max(height(node.left), height(node.right)) + 1;
    }

public:
    Node<T> *root = NULL;
    bool add(T elem)
    {
        if (contains(elem))
            return false;

        root = add(root, elem);
        ++nodeCount;
        return true;
    }

    bool remove(T elem)
    {
        if (contains(elem))
        {
            root = remove(root, elem);
            --nodeCount;
            return true;
        }

        return false;
    }

    int size()
    {
        return nodeCount;
    }

    bool contains(T elem)
    {
        Node<T> *trav = root;
        while (trav != NULL)
        {
            if (elem > trav->data)
                trav = trav->right;
            else if (elem < trav->data)
                trav = trav->left;
            else
                return true;
        }

        return false;
    }

    int height(){
        return height(root);
    }
};