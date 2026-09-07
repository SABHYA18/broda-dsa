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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);

        while(!q.empty()){
            int qLen = q.size();
            vector<int> ans;
            for(int i = 0; i<qLen; i++){

                TreeNode* node = q.front();
                q.pop();
                if(node) ans.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            if(ans.size()!=0){
                res.push_back(ans);
            }
        }
        return res;

    }
};
