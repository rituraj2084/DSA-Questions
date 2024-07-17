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
    unordered_map<int, bool> hashed_to_delete;
    TreeNode* postOrder(TreeNode* root, vector<TreeNode*>& result) {
        if(root == NULL)
            return NULL;
        
        root->left = postOrder(root->left, result);
        root->right = postOrder(root->right, result);
        if(hashed_to_delete[root->val]){
            if(root->left)
                result.push_back(root->left);
            if(root->right)
                result.push_back(root->right);

            return NULL;
        }

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int &node: to_delete) {  // for easier lookup
            hashed_to_delete[node] = true;
        }

        vector<TreeNode*> result;
        if(postOrder(root, result)) {  // if root node is not deleted
            result.push_back(root);
        }

        return result;
    }
};