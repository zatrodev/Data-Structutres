#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node *left;
	Node *right;
    string key; // for hash table purposes
	
	Node(T data = 0, string key = "", Node <T> *left = NULL, Node <T> *right = NULL) 
        : data(data)
        , key(key)
        , left(left)
        , right(right) 
    {
    }
};