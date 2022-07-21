class Solution {
public:
    int solveRec(vector<int>&nums, int ind){
        
        if(ind < 0) return 0;
        if(ind == 0) return nums[ind];
        
        int inc = solveRec(nums, ind-2) + nums[ind];
        int exc = solveRec(nums, ind-1);
        return max(inc, exc);
    }
    int solveMem(vector<int>&nums, int ind, vector<int>&dp){
        if(ind < 0) return 0;
        if(ind == 0) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        int inc = solveMem(nums, ind-2, dp) + nums[ind];
        int exc = solveMem(nums, ind-1, dp);
        dp[ind] = max(exc, inc);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        //memoization
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solveMem(nums, n-1, dp);
        
        //Recursive
        // int n = nums.size();
        // return solveRec(nums, n-1);
    }
};