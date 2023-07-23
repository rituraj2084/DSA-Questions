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
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> memo;
        return generateFBT(n, memo);
    }
private:
    vector<TreeNode*> generateFBT(int n, unordered_map<int, vector<TreeNode*>>& memo) {
        if (n == 0)
            return {};
        if (n == 1)
            return {new TreeNode(0)};
        if (memo.find(n) != memo.end())
            return memo[n];

        vector<TreeNode*> result;
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> leftSubtrees = generateFBT(i, memo);
            vector<TreeNode*> rightSubtrees = generateFBT(n - 1 - i, memo);

            for (TreeNode* leftSubtree : leftSubtrees) {
                for (TreeNode* rightSubtree : rightSubtrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = leftSubtree;
                    root->right = rightSubtree;
                    result.push_back(root);
                }
            }
        }

        memo[n] = result;
        return result;
    }
};