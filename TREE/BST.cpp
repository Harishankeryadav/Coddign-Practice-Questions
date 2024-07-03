#include <iostream>
#include "BSTfunctions.h"
#include "TimerClock.h"
#include <queue>
using namespace std;

// taking input level wise.
void Take_Input(Node<int> *&root)
{
    {
        int data;
        cout << "Enter the data ";
        cin >> data;
        root = new Node<int>(data);
        queue<Node<int> *> q;
        q.push(root);

        while (!q.empty())
        {
            Node<int> *newnode = q.front();
            q.pop();
            int newdata;
            cout << "enter the left of " << newnode->data << endl;
            cin >> newdata;
            if (newdata != -1)
            {
                newnode->left = new Node<int>(newdata);
                q.push(newnode->left);
            }

            cout << "Enter the right of " << newnode->right << endl;
            cin >> newdata;
            if (newdata != -1)
            {
                newnode->right = new Node<int>(newdata);
                q.push(newnode->right);
            }
        }
    }
}



int main()
{ // ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    BST b;
    cout << "Enter the root data ";
    // Node<int> *root;
    // {
    //     timer T;
    //     Take_Input(root);
    // }
    // // // print(root);
    // {
    //     timer T;
    //     b.Levelprinting();
    // }

    b.insert(50);
    b.insert(25);
    b.insert(75);
    b.insert(20);
    b.insert(30);
    b.insert(70);
    b.Levelprinting();
   

    b.deleteNode(20);
    b.Levelprinting();

    cout <<  b.searchData(70) << " s " << endl;
}