/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int diameter(TreeNode* root, int& d){
        if(root==NULL) return 0;

        int leftDiameter = 0, rightDiameter = 0;
        if(root->left) leftDiameter = diameter(root->left, d);
        if(root->right) rightDiameter = diameter(root->right, d);

        int currentDiameter = leftDiameter+rightDiameter;
        d = max(d, currentDiameter);
        return 1 + max(leftDiameter, rightDiameter);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int d = 0;
        diameter(root,d);        
        return d;
    }
};
