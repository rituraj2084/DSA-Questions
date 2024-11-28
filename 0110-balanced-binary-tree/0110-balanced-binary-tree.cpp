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
    int getHeight(TreeNode* root){
        if(!root) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
       if(!root) return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return abs(leftHeight-rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};