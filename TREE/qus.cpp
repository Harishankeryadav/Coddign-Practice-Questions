#include <iostream>
#include <queue>
#include "Tree_Node.h"

#include "TimerClock.h"
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
// qus-: finding the node with max node sum.
int maxSumNode(TreeNode<int> *root)
{
    int sum = root->data;
    static int x = 0;
    static int sum1 = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    if (sum > sum1)
    {
        sum1 = sum;
        x = root->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {

        maxSumNode(root->children[i]);
    }
    return x;
}

// next largest.
int nextLargest(TreeNode<int> *root, int x)
{
    static int nl = INT16_MAX;
    if (root->data > x && root->data < nl)
    {
        nl = root->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        nextLargest(root->children[i], x);
    }
    return nl;
}
// second largest in the given tree
int secondLargest(TreeNode<int> *root)
{
    static int f = 0;
    static int s = 0;

    if (root->data > f)
    {
        s = f;
        f = root->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        secondLargest(root->children[i]);
    }
    return s;
}

// replacing the nodes with thier depth.
void replaceNodeDepth(TreeNode<int> *&root)
{
    static int x = 0;
    if(root == NULL){
        return;
    }
    if (x == 0)
    {
        root->data = 0;
        x++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << "root->data : " << root->data << ",  X : " << x << endl;
        root->children[i]->data = x;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        x++;
        replaceNodeDepth(root->children[i]);
    }
}

int main()
{
    // ex : 1 3 2 3 4 1 5 2 6 7 3 8 9 10 0 0 0 0 2 11 12 1 13 0 0 1 14 0
    // 10 3 20 30 40 2 50 60 0 0 0 0
    {
    }
    TreeNode<int> *root = takeInput();
    cout << "Printing tree " << endl;
    printData(root);

    // int x = 0;
    // x = maxSumNode(root);
    // cout << "Node whose sum is max in the given tree is : " << x << endl;

    // int nl = 0;
    // cout << "Enter the value whose mas want to find  ";
    // cin >> nl;
    // nl = nextLargest(root, nl);
    // cout << "max : " << nl << endl;
    // {
    //     timer T;
    //     nl = secondLargest(root);
    //     cout << "Second largest " << nl ;
    // }

    replaceNodeDepth(root);
    cout << "after replacing with nodes level " << endl;
    printData(root);
}