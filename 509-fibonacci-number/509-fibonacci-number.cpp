class Solution {
public:
    int solve(int n){
        if(n <= 1) return n;
        return solve(n-1) + solve(n-2);
    }
    
    int solveMem(int n, vector<int> &dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp);
        return dp[n];
    }
    
    int solveTab(int n){
        if(n == 0) return 0;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        //int prev1 = 1, prev2 = 0;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    int solveOpt(int n){
        if(n == 0) return 0;
        int prev1 = 1, prev2 = 0;
        int ans;
        for(int i = 2; i <= n; i++){
            ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    
    int fib(int n) {
        // Space optimised
        return solveOpt(n);
        
        // //tabulation
        // return solveTab(n);
        
        // //Memoization
        // vector<int>dp(n+1, -1);
        // return solveMem(n, dp);
        
        // recursive
       //return solve(n);
    }
};