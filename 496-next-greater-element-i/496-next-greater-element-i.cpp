class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    
        /*
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> m;
        for (int i=0; i<(int)(nums1.size()); i++) {
            auto itr = m.find(nums1[i]);
            if (itr != m.end()) {
                ans[i] = itr->second;
            }
        }
        return ans;
        */
    }
};