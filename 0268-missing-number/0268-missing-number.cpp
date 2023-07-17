class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        for(int i = 1; i <= n; i++){
            mp[i]--;
        }
        for(auto it: mp){
            if(it.second == -1){
                return it.first;
            }
        }
        return 0;
    }
};