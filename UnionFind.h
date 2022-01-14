#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    int size;
    vector<int> sz;

    // id[i] points to the parent node of i, if id[i] = i, then parent node of i is itself
    vector<int> id;
    int numComponents;

    UnionFind(int size)
    {
        this->size = numComponents = size;

        for (int i = 0; i < size; ++i)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }

    // returns the root node of a particular node
    int find(int p)
    {
        int root = p;
        while (root != id[root])
            root = id[root];

        // path compression
        while (p != root)
        {
            int next = id[p];
            id[p] = root;
            p = next;
        }

        return root;
    }

    bool connected(int p, int q)
    {
        return this->find(p) == this->find(q);
    }

    int componentSize(int p)
    {
        return sz[find(p)];
    }

    void unify(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot)
            return;

        if (sz[pRoot] < sz[qRoot])
        {
            sz[qRoot] += sz[pRoot];
            id[pRoot] = qRoot;
        }
        else
        {
            sz[pRoot] += sz[qRoot];
            id[qRoot] = pRoot;
        }

        --numComponents;
    }
};