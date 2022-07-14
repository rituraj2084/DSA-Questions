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
     TreeNode *func(vector<int>& preorder,int prstart,int prend,vector<int>& inorder,int instart,int 
                  inend,unordered_map<int,int>&mp){
        
        //Base case
        if(prstart>prend || instart>inend)  return NULL;
        TreeNode* root = new TreeNode(preorder[prstart]);
        
        //Pointers to Subsequent ROOT and Number of left numbers to root
        int inRoot = mp[root->val];
        int numsLeft = inRoot - instart;
        
        root->left = func(preorder,prstart+1,prstart+numsLeft,inorder,instart,inRoot-1,mp);
        root->right = func(preorder,prstart+numsLeft+1,prend,inorder,inRoot+1,inend,mp);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i =0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        TreeNode * root = func(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    /*
    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, 
                            vector<int>& inorder, int inStart, int inEnd, map<int, int>mp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int element = mp[root -> val];
        int nelement = element - inStart;
        root -> left = constructTree(preorder, preStart+1, preStart+nelement, inorder, inStart, element - 1, mp);
        root -> right = constructTree(preorder, preStart+nelement+1, preEnd, inorder, element+1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, preEnd = preorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;
        map<int, int> mp;
        for(int i = 0; i <= inEnd; i++) mp[inorder[i]] = i;
        return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
    }
    */
};