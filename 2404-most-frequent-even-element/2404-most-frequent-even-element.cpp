class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]%2 == 0)
                mp[nums[i]]++;
        }
        int count = 0;
        int ans = -1;
        for(auto it:mp){
            if(count < it.second){ 
                count = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};