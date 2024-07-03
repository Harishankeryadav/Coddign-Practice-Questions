#include <iostream>
#include "trie.h"
using namespace std;

int main()
{
    Trie trie;
    trie.insertWord("hello");
    trie.insertWord("world");

    cout << trie.search("hello") << endl;
    cout << trie.search("world") << endl;
    cout << trie.search("hell") << endl;

    trie.removeWord("hello");
    cout << trie.search("hello") << endl;

    return 0;
}