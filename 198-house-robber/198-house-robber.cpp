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
    int solveTab(vector<int>&nums){
        int n = nums.size();
        vector<int> dp(n+1, 0);
        if(n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
    int solve(vector<int>&nums){
        int prev2 = 0;
        int prev1 = nums[0];
        int ans;
        for(int i = 1; i < nums.size(); i++){
          ans = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        //Space optimised
        return solve(nums);
        //tabulation
        // return solveTab(nums);
        
        //memoization
        // int n = nums.size();
        // vector<int> dp(n+1, -1);
        // return solveMem(nums, n-1, dp);
        
        //Recursive
        // int n = nums.size();
        // return solveRec(nums, n-1);
    }
};