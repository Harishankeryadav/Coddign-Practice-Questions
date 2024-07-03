#include <iostream>
#include <queue>
#include "Tree_Node.h"
#include"TimerClock.h"
using namespace std;

TreeNode<int> *takeInput()
{
    int rootdata;
    cout << "Enter the root data  ";
    cin >> rootdata;

    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n;
        TreeNode<int> *child;
        TreeNode<int> *temp = q.front();
        q.pop();
        cout << "Total no. of child of " << temp->data << " ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the " << i << "th child node of " << temp->data << " ";
            cin >> rootdata;
            child = new TreeNode<int>(rootdata);
            temp->children.push_back(child);
            q.push(child);
        }
    }
    cout << endl;
    return root;
}

void printData(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    if (root == NULL)
    {
        cout << "Empty tree " << endl;
        return;
    }
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        cout << temp->data << " : ";
        for (int i = 0; i < temp->children.size(); i++)
        {
            cout << temp->children[i]->data << " ,";
            q.push(temp->children[i]);
        }
        cout << endl;
    }
}

// counting the nodes of the given tree.
int nodeCount(TreeNode<int> *root)
{
    int n = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        n += nodeCount(root->children[i]);
    }
    return n;
}

int height(TreeNode<int> *root)
{
    int ans = 0;
    int a = 0;
    static int b = 0;
    if (root->children.size())
    {
        b++; // finding the leaf node of the given tree.
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        a = height(root->children[i]);
        ans = max(ans, a); // finding the heifht of the tree.
    }
    cout << "B : " << b << endl;
    return ans + 1;
}

// printing the child node at level x.
void printing_node(TreeNode<int> *root, int x)
{
    if (x == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printing_node(root->children[i], x - 1);
    }
}

void printInRange(TreeNode<int> *root, int x, int y)
{

    if (root->data >= x && root->data <= y)
    {
        cout << root->data << " ";
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printInRange(root->children[i], x, y);
    }
}

int main()
{ // ex : 1 3 2 3 4 1 5 2 6 7 3 8 9 10 0 0 0 0 2 11 12 1 13 0 0 1 14 0
    // 10 3 20 30 40 2 50 60 0 2 70 80 0 0 0 1 90 0
    TreeNode<int> *root = takeInput();
    cout << "Printing the given tree " << endl;
    printData(root);

    // int ans = 0;
    // ans = nodeCount(root);
    // cout << "Total nodes in the giveen tree is : " << ans << endl;
    // int hght = 0;
    // hght = height(root);
    // cout << "Height of the tree is " << hght << endl;

    cout << "enter the level ";
    int x;
    cin >> x;
    cout << "printing the node at level " << x << endl;
    printing_node(root, x);

    //  40 20 60 10 30 50 70 -1 -1 -1 -1 -1 -1 -1 -1
    // {
    //     timer T;
    //     cout << "Enter the range to print the data ";
    //     int x, y;
    //     cin >> x >> y;
    //     printInRange(root, x, y);
    // }
}