class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long, int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[i-nums[i]]++;
        }
        long long count = 0;
        for(int i = 0; i < nums.size(); i++){
            long long diff = i - nums[i];
            mp[diff]--;
            count += nums.size()-1-i-mp[diff];
        }
        return count;
    }
};