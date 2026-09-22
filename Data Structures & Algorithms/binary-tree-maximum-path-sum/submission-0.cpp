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
    int maxSumPath(TreeNode* root, int& maxSum){
        if(root==NULL) return 0;
        
        int leftSum = max(0, maxSumPath(root->left, maxSum));
        int rightSum = max(0, maxSumPath(root->right, maxSum));

        int currentSum = root->val + leftSum+rightSum;

        maxSum = max(maxSum, currentSum);

        return root->val+max(leftSum, rightSum);

    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;

        int maxSum = INT_MIN;

        maxSumPath(root, maxSum);
        return maxSum;

                
    }   
};
