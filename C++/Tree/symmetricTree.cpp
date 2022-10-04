#include<bits/stdc++.h>
using namespace std;
//to check 2 trees are same using traversals -> if any 2 traversals are simultaneously same for 
//both the trees then only it can be said as similar
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
  };

class Solution {
    
   
public:
     bool isSymmetric(TreeNode *root) {
        return root ==NULL || isMirror(root->left, root->right);
    }
   bool isMirror(TreeNode *node1, TreeNode *node2) {
        if (node1 == NULL && node2 == NULL) return true;
        if (node1 == NULL || node2 == NULL) return false;
        if (node1->val != node2->val) return false;
        return isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
    }
};

int main(){
	Solution s1;
	struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    struct TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    bool res=s1.isSameTree1(root,root1);

    cout<<res<<endl;


    

}