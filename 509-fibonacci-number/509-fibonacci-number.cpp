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
        vector<int> dp(n+2, 0);
        dp[0] = 0;
        dp[1] = 1;
        //int prev1 = 1, prev2 = 0;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        //tabulation
        return solveTab(n);
        
        // //Memoization
        // vector<int>dp(n+1, -1);
        // return solveMem(n, dp);
        
        // recursive
       //return solve(n);
    }
};