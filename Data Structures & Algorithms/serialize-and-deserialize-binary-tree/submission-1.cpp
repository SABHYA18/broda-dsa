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

class Codec {
private:
    void dfs(TreeNode* root, string& s){
        if(root==NULL) {
            s+="N,";
            return ;
        }


        s +=to_string(root->val) + ",";
        dfs(root->left, s);
        dfs(root->right, s);
        
    }

    TreeNode* deserializeDfs(stringstream& ss){
        string token;
        if(!getline(ss, token, ',')){
            return NULL;
        }

        if(token=="N"){
            return NULL;
        }

        TreeNode* newNode = new TreeNode(stoi(token));
        newNode->left = deserializeDfs(ss);
        newNode->right = deserializeDfs(ss);

        return newNode;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser = "";
        if(root==NULL) return ser;

        dfs(root, ser);
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream ss(data);
        return deserializeDfs(ss);
    }
};
