#include <string>
#include "trieClass.h"
using namespace std;

class Trie
{
    TrieNode *root;

    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return search(child, word.substr(1));
    }

    void insertWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    void removeWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }

        removeWord(child, word.substr(1));

        if (!child->isTerminal)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != nullptr)
                    return;
            }
            delete child;
            root->children[index] = nullptr;
        }
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    ~Trie()
    {
        delete root;
    }

    bool search(string word)
    {
        return search(root, word);
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
};