#include "LinkedList.h"
#include <map>
#include <iostream>
using namespace std;

template <typename T>
class HashTable
{
private:
    LinkedList<T> arr[10];
    map<string, int> hashedKeys;

    int hash(string key)
    {
        int index = 0;
        for (char chr : key)
        {
            index += chr + 1;
        }

        index = index % 10;
        cout << "Index: " << index << endl;
        hashedKeys[key] = index;
        return index;
    }

public:
    void add(string key, T value)
    {
        if (hashedKeys[key] != NULL)
        {
            cout << "Element already added in the table." << endl;
            return;
        }

        int index = hash(key);
        arr[index].add(value, key);
    }

    T get(string key)
    {
        int index = hashedKeys[key];
        LinkedList<T> specList = arr[index];

        if (specList.size == 1)
        {
            if (specList.head->key == key)
            {
                return specList.head->data;
            }

            cout << "Key does not exist in the table" << endl;
            return NULL;
        }

        Node<T> *trav = specList.head;
        while (trav->key != key)
        {
            trav = trav->right;
        }

        return trav->data;
    }

    void remove(string key)
    {
        int index = hashedKeys[key];
        arr[index].remove(key);
    }
};