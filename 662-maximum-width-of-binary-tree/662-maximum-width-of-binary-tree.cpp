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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            //int curMin = q.front().second;
            int leftMax, rightMax;
            for(int i = 0; i < size; i++){
                int curId = q.front().second;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i == 0) leftMax = curId;
                if(i == size - 1) rightMax = curId;
                if(temp -> left) q.push({temp -> left, (long long)curId*2+1});
                if(temp -> right) q.push({temp -> right,(long long) curId*2+2});
            }
            ans = max(ans, rightMax-leftMax+1);
        }
        return ans;
    }
};