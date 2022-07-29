/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* &root, vector<int> &ans){
        if(!root) return;
        ans.push_back(root -> val);
        for(auto child: root -> children){
            solve(child, ans);
        }
    }
    vector<int> preorder(Node* root) {
        //iterative
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();
            ans.push_back(cur -> val);
            for (int i = cur -> children.size() - 1; i >= 0; i--) {
                if (cur -> children[i] != NULL) {
                    st.push(cur -> children[i]);
                }
            }
        }
        return ans;
        
       //  // recursive
       // vector<int> ans;
       //  solve(root, ans);
       //  return ans;
    }
};