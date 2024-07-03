#include<bits/stdc++.h>
using namespace std;


 int count(Node*& root) {
        if(root == NULL)    return 0;

        int leftCount = count(root->left);
        int rightCount = count(root->right);
        
        return 1+leftCount+rightCount;
    }
    int countNodes(TreeNode* root) {
     
        return count(root);
    }

    int main(){

        
    }