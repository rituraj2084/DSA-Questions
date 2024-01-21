class Solution {
public:
    int solve(vector<int>&nums, int ind, vector<int>&dp){
        if(ind < 0) return 0;
        if(ind == 0) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        int inc = solve(nums, ind-2, dp) + nums[ind];
        int exc = solve(nums, ind-1, dp);
        dp[ind] = max(exc, inc);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
       int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(nums, n-1, dp); 
    }
};