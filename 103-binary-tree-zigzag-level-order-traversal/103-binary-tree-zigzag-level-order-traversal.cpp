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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>>ans;
        bool isLeftToRight = true;
        if(root == NULL) return ans;
        while(!q.empty()){
            int len = q.size();
            
            vector<int> v(len);
            for(int i = 0; i < len; i++){
                
                TreeNode* node = q.front();
                q.pop();
                int index = isLeftToRight?i:len-1-i;
                v[index] = (node->val);
                if(node->left){
                    q.push(node ->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(v);
            isLeftToRight = !isLeftToRight;
        }
        return ans;
    }
};