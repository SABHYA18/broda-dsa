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
    int preIdx = 0;
    unordered_map<int, int> inorderMap;

    TreeNode* build(vector<int>& preorder, int startIndex, int endIndex){
        if(startIndex > endIndex){
            return NULL;
        }

        int rootValue = preorder[preIdx++];
        TreeNode* node = new TreeNode(rootValue);
        int inorderRootVal = inorderMap[rootValue];

        node->left = build(preorder, startIndex, inorderRootVal - 1);
        node->right = build(preorder, inorderRootVal+1, endIndex);

        return node;
    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        preIdx = 0;
        inorderMap.clear();

        for(int i = 0; i<inorder.size(); i++){
            inorderMap[inorder[i]]= i;
        }

        return build(preorder, 0, inorder.size()-1);

    }
};
