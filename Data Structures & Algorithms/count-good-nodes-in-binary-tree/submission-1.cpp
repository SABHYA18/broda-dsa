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
    int goodCount(TreeNode* node, int maxSoFar){
        if(node==NULL) return 0;
        int maxNode = 0;
        if(node->val>=maxSoFar){
            maxNode = 1;
        }

        int newMax = max(maxSoFar, node->val);

        maxNode +=goodCount(node->left, newMax);
        maxNode +=goodCount(node->right, newMax);

        return maxNode;
    }
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;

        return goodCount(root, root->val);

    
    }
};
