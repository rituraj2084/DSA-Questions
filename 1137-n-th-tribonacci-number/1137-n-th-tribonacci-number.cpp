class Solution {
public:
    int solveRec(int n){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        return solveRec(n-1) + solveRec(n-2) + solveRec(n-3);
    }
    
    int solveMem(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp) + solveMem(n-3, dp);
        return dp[n];
    }
    
    int solveTab(int n){
        if(n == 0) return 0;
        vector<int> dp(n+2, 0);
        dp[1] = 1, dp[2] = 1;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
    
    int solveOpt(int n){
        if(n == 0) return 0;
        int prev3 = 0, prev1 = 1, prev2 = 1;
        for(int i = 3; i <= n; i++){
            int ans = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int tribonacci(int n) {
        //optimised
        return solveOpt(n);
        
        // //tabulation
        // return solveTab(n);
        
        // //Memoization
        // vector<int> dp(n+1, -1);
        // return solveMem(n, dp);
        
        // // recursive
        // return solveRec(n);
    }
};