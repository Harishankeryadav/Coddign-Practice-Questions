#include <iostream>
using namespace std;
template <typename T>

class Node
{
public:
    T data;
   Node* left;
   Node* right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};