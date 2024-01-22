class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if(it.second == 2) ans.push_back(it.first);
        }
        for(int i = 1; i <= n; i++){
            if(mp.find(i) == mp.end()) ans.push_back(i);
        }
        return ans;
    }
};