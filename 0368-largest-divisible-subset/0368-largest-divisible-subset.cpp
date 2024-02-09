class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 1){
            return nums;
        }
        vector<int> dp(nums.size(), 1);
        int max_index = 0;
        std::sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                int rem = nums[i] % nums[j];
                if(rem == 0){
                    dp[i] = std::max(dp[i],dp[j] + 1);
                }
            }
            if(dp[i] > dp[max_index]){
                max_index = i;
            }
        }
        vector<int> res;
        res.push_back(nums[max_index]);
        int k = dp[max_index];
        int count = 1;
        for(int i = max_index - 1; i >=0; i--){
            int val = (res.back());
            if((val % nums[i]) == 0 and dp[i] + count == k){
                count++;
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};