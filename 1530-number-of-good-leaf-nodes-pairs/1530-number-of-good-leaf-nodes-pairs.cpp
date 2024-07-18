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
    pair<int, vector<int>> countPairsUtil(TreeNode* node, int distance) {
        if (!node) {
            return {0, vector<int>(distance + 1, 0)};
        }
        
        if (!node->left && !node->right) {
            vector<int> d(distance + 1, 0);
            d[1] = 1;
            return {0, d};
        }
        
        auto left = countPairsUtil(node->left, distance);
        auto right = countPairsUtil(node->right, distance);

        int pairs = left.first + right.first;
        for (int i = 1; i <= distance; ++i) {
            for (int j = 1; j <= distance - i; ++j) {
                pairs += left.second[i] * right.second[j];
            }
        }
        
        vector<int> d(distance + 1, 0);
        for (int i = 1; i < distance; ++i) {
            d[i + 1] = left.second[i] + right.second[i];
        }

        return {pairs, d};
    }
    int countPairs(TreeNode* root, int distance) {
         return countPairsUtil(root, distance).first;
    }
};