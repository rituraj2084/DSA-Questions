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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int n = q.size();
            int prev = level&1 ? 1e9 : 0;

            // traversing level wise
            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                // same parity as level
                if((level&1) == ((node->val)&1)){
                    return false;
                }
                // odd level
                if((level&1) && node->val >= prev){
                    return false;
                }
                // even level
                if(!(level&1) && node->val <= prev){
                    return false;
                }
                prev = node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;
        }
        return true;
    }
};