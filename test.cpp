#include "HashTable.h"

int main()
{
    HashTable<int> table;
    table.add("aGHjk", 512);
    table.add("uwwdA", 101);
    table.add("uwwdb", 102);

    int elem = table.get("aGHjk");
    cout << elem;

    // table.remove("uwwdb");
    // elem = table.get("uwwdA");
    // cout << elem;
}